#include "palette.h"
#include <stdio.h>
#include <stdlib.h>

char acnl_palette[16][10][3] = {

	{	
		//block 0
		"\xFF\xEE\xFF",
		"\xFF\x99\xAA",
		"\xEE\x55\x99",
		"\xFF\x66\xAA",
		"\xFF\x00\x66",
		"\xBB\x44\x77",
		"\xCC\x00\x55",
		"\x99\x00\x33",
		"\x55\x22\x33",
		"\xFF\xFF\xFF"
	},

	{
		//block 1
		"\xFF\xBB\xCC",
		"\xFF\x77\x77",
		"\xDD\x32\x10",
		"\xFF\x55\x44",
		"\xFF\x00\x00",
		"\xCC\x66\x66",
		"\xBB\x44\x44",
		"\xBB\x00\x00",
		"\x88\x22\x22",
		"\xEE\xEE\xEE"
	},
	
	{
		//block 2
		"\xDD\xCD\xBB",
		"\xFF\xCD\x66",
		"\xDD\x66\x22",
		"\xFF\xAA\x22",
		"\xFF\x66\x00",
		"\xBB\x88\x55",
		"\xDD\x44\x00",
		"\xBB\x44\x00",
		"\x66\x32\x10",
		"\xDD\xDD\xDD"
	},
	
	{
		//block 3
		"\xFF\xEE\xDD",
		"\xFF\xDD\xCC",
		"\xFF\xCD\xAA",
		"\xFF\xBB\x88",
		"\xFF\xAA\x88",
		"\xDD\x88\x66",
		"\xBB\x66\x44",
		"\x99\x55\x33",
		"\xF1\xB5\xC1",
		"\xCC\xCC\xCC"
	},
	
	{
		//block 4
		"\xFF\xCD\xFF",
		"\xEE\x88\xFF",
		"\xCC\x66\xDD",
		"\xBB\x88\xCC",
		"\xCC\x00\xFF",
		"\x99\x66\x99",
		"\x88\x00\xAA",
		"\x55\x00\x77",
		"\x33\x00\x44",
		"\xBB\xBB\xBB"
	},
	
	{
		//block 5
		"\xFF\xBB\xFF",
		"\xFF\x99\xFF",
		"\xDD\x22\xBB",
		"\xFF\x55\xEE",
		"\xFF\x00\xCC",
		"\x88\x55\x77",
		"\xBB\x00\x99",
		"\x88\x00\x66",
		"\x55\x00\x44",
		"\xAA\xAA\xAA"
	},
	
	{
		//block 6
		"\xDD\xBB\x99",
		"\xCC\xAA\x77",
		"\x77\x44\x33",
		"\xAA\x77\x44",
		"\x99\x32\x00",
		"\x77\x32\x22",
		"\x55\x22\x00",
		"\x33\x10\x00",
		"\x22\x10\x00",
		"\x99\x99\x99"
	},
	
	{
		//block 7
		"\xFF\xFF\xCC",
		"\xFF\xFF\x77",
		"\xDD\xDD\x22",
		"\xFF\xFF\x00",
		"\xFF\xDD\x00",
		"\xCC\xAA\x00",
		"\x99\x99\x00",
		"\x88\x77\x00",
		"\x55\x55\x00",
		"\x88\x88\x88"
	},
	
	{
		//block 8
		"\xDD\xBB\xFF",
		"\xBB\x99\xEE",
		"\x66\x32\xCC",
		"\x99\x55\xFF",
		"\x66\x00\xFF",
		"\x55\x44\x88",
		"\x44\x00\x99",
		"\x22\x00\x66",
		"\x22\x10\x33",
		"\x77\x77\x77"
	},
	
	{
		//block 9
		"\xBB\xBB\xFF",
		"\x88\x99\xFF",
		"\x33\x32\xAA",
		"\x33\x55\xEE",
		"\x00\x00\xFF",
		"\x33\x32\x88",
		"\x00\x00\xAA",
		"\x10\x10\x66",
		"\x00\x00\x22",
		"\x66\x66\x66"
	},
	
	{
		//block 10
		"\x99\xEE\xBB",
		"\x66\xCD\x77",
		"\x22\x66\x10",
		"\x44\xAA\x33",
		"\x00\x88\x33",
		"\x55\x77\x55",
		"\x22\x55\x00",
		"\x10\x32\x22",
		"\x00\x22\x10",
		"\x55\x55\x55"
	},
	
	{
		//block 11
		"\xDD\xFF\xBB",
		"\xCC\xFF\x88",
		"\x88\xAA\x55",
		"\xAA\xDD\x88",
		"\x88\xFF\x00",
		"\xAA\xBB\x99",
		"\x66\xBB\x00",
		"\x55\x99\x00",
		"\x33\x66\x00",
		"\x44\x44\x44"
	},
	
	{
		//block 12
		"\xBB\xDD\xFF",
		"\x77\xCD\xFF",
		"\x33\x55\x99",
		"\x66\x99\xFF",
		"\x10\x77\xFF",
		"\x44\x77\xAA",
		"\x22\x44\x77",
		"\x00\x22\x77",
		"\x00\x10\x44",
		"\x33\x33\x33"
	},
	
	{
		// block 13
		"\xAA\xFF\xFF",
		"\x55\xFF\xFF",
		"\x00\x88\xBB",
		"\x55\xBB\xCC",
		"\x00\xCD\xFF",
		"\x44\x99\xAA",
		"\x00\x66\x88",
		"\x00\x44\x55",
		"\x00\x22\x33",
		"\x22\x22\x22"
	},
	
	{
		// block 14
		"\xCC\xFF\xEE",
		"\xAA\xEE\xDD",
		"\x33\xCD\xAA",
		"\x55\xEE\xBB",
		"\x00\xFF\xCC",
		"\x77\xAA\xAA",
		"\x00\xAA\x99",
		"\x00\x88\x77",
		"\x00\x44\x33",
		"\x11\x11\x11"
	},
	
	{
		// block 15
		"\xAA\xFF\xAA",
		"\x77\xFF\x77",
		"\x66\xDD\x44",
		"\x00\xFF\x00",
		"\x22\xDD\x22",
		"\x55\xBB\x55",
		"\x00\xBB\x00",
		"\x00\x88\x00",
		"\x22\x44\x22",
		"\x00\x00\x00"
	}	

};

char *getRGB(unsigned char palptr) {

	palptr %= 256;

	char block = palptr >> 4;
	char index = palptr % 16;
	
	//fprintf(stderr, "getRGB(): palptr = 0x%2x ; block = %1x ; index = %1x\n", palptr, block, index);

	return acnl_palette[block][index >= 9 ? 9 : index];

}
