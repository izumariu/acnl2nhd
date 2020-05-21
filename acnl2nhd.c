#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>
#include <time.h>
#include "palette.h"
#define PATTERN_LENGTH 20
#define CREATOR_LENGTH 11
#define ISLAND_LENGTH 10
typedef unsigned char uchar;

uchar swapNibbles(uchar c) {

	// swaps the nibbles of a byte

	return ((c % 16) << 4) + (c >> 4);

}

void storeBigEndian(uchar *in, int limit, wchar_t *buf) {

	// converts the little endian encoded names
	// into big endian and stores them in a
	// buffer

	for(int i = 0; i < limit; i++) {

		int ev_val = (in[i*2+1] << 8) + in[i*2+0];
		buf[i] = btowc(ev_val);

	}

	buf[limit] = L'\0';

}

int main(int argc, char** argv) {	

	if(argc != 2) {

		fprintf(stderr, "USAGE: %s <ACNL file>\n", argv[0]);

		return 1;

	}

	FILE *acnl = fopen(argv[1], "r");

	if(!acnl) {

		fprintf(stderr, "File '%s' does not exist. Aborting.\n", argv[1]);

		return 1;

	}

	// store length of file
	long int acnl_length;
	
	fseek(acnl, 0, SEEK_END);
	acnl_length = ftell(acnl);

	if(acnl_length != 620) {

		fprintf(stderr, "File '%s' is not exactly 620 bytes long and thus not a proper ACNL file.\n", argv[1]);

		return 1;

	}


	// allocate all the important variables:

	// wide char buffer for storeBigEndian()
	wchar_t *wchar_buf = (wchar_t*) malloc(22 * sizeof(wchar_t));
	
	// metadata of the creator and his creation
	uchar *patternName = (uchar*) malloc(PATTERN_LENGTH * 2 + 1);
	uchar *islandName  = (uchar*) malloc( ISLAND_LENGTH * 2 + 1);
	uchar *creatorName = (uchar*) malloc(CREATOR_LENGTH * 2 + 1);

	// raw palette data and NHD-style palette data
	uchar *palette    = (uchar*) malloc(15 * 1 + 1);
	uchar *paletteRgb = (uchar*) malloc(15 * 3 + 1);

	// and the picture itself
	uchar *picture = (uchar*) malloc(512);

	// now grab all of the metadata and store but also print it
	fseek(acnl, 0x000, SEEK_SET);
	fgets(patternName, PATTERN_LENGTH * 2 + 1, acnl);
	storeBigEndian(patternName, PATTERN_LENGTH, wchar_buf);
	printf("Pattern: %ls\n", wchar_buf);

	fseek(acnl, 0x02c, SEEK_SET);
	fgets(creatorName, CREATOR_LENGTH * 2 + 1, acnl);
	storeBigEndian(creatorName, CREATOR_LENGTH, wchar_buf);
	printf("Creator: %ls\n", wchar_buf);

	fseek(acnl, 0x042, SEEK_SET);
	fgets(islandName, ISLAND_LENGTH * 2 + 1, acnl);
	storeBigEndian(islandName, ISLAND_LENGTH, wchar_buf);
	printf("Origin:  %ls\n", wchar_buf);

	// grab the ACNL palette...
	fseek(acnl, 0x58, SEEK_SET);
	fgets(palette, 15 + 1, acnl);

	// and convert it to RGB (NHD style)
	
	uchar *color;
	
	for(int pI = 0; pI < 15; pI++) {

		color = getRGB(palette[pI]);
		printf("Palette(0x%1X): (%u, %u, %u)\n", pI, color[0], color[1], color[2]);

		for(int sI = 0; sI < 3; sI++) paletteRgb[pI * 3 + sI] = color[sI];
	
	}

	// store the actual picture

	fseek(acnl, 0x06c, SEEK_SET);

	for(int i = 0; i < 512; i++) {

		uchar currentChar = fgetc(acnl);

		picture[i] = currentChar; // nibbles?
		
	}

	// initialize a randomizer for what's probably an ID

	time_t tRand;
	srand((unsigned)time(&tRand));

	// create the final file name

	int inname_length = strlen(argv[1]);
	uchar *outname = (uchar*) malloc(inname_length + 4);
	strcpy(outname, argv[1]);
	strcat(outname, ".nhd\0");

	FILE *outfile = fopen(outname, "w");

	for(int i = 0; i < 4; i++) fputc(rand() % 256, outfile); // TODO is this an ID????
	fputc(0x008, outfile);
	while(ftell(outfile) <= 0x00f) fputc(0x0, outfile);
	
	// write pattern name; can't use fputs here because of all the '\0's
	for(int i = 0; i < PATTERN_LENGTH*2; i++) fputc(patternName[i], outfile);
	fputs("\x81\xEF\x47\xFB\0", outfile);

	// write island name
	for(int i = 0; i < ISLAND_LENGTH*2; i++) fputc(islandName[i], outfile);
	fputs("\x02\0", outfile);

	// unknown no.1
	for(int i = 0; i < 3; i++) fputc(0x0, outfile);
	fputs("\x27\xE6\xA4\xBE\0", outfile);

	// write creator name (+1 character bc ACNL creator length is 11 and NHD is 12)
	for(int i = 0; i < CREATOR_LENGTH*2; i++) fputc(creatorName[i], outfile);
	for(int i = 0; i < 2; i++) fputc(0x0, outfile);

	// unknown no.2
	fputc(0x00, outfile);
	fputc(0xEE, outfile);
	for(int i = 0; i < 6; i++) fputc(0x00, outfile);
	
	// palette
	for(int i = 0; i < 15*3; i++) fputc(paletteRgb[i], outfile);

	// actual picture
	for(int i = 0; i < 512; i++) fputc(picture[i], outfile);

	// EOF
	for(int i = 0; i < 3; i++) fputc(0x0, outfile);
	
	free(patternName);
	free(creatorName);
	free( islandName);

	free(palette   );
	free(paletteRgb);

	free(picture);

	free(outname);

	free(wchar_buf);
	
	fclose(acnl);
	fclose(outfile);

	return 0;

}
