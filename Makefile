PROG=acnl2nhd

$(PROG): $(PROG).o palette.o
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) -c $<

%.o: %.c
	$(CC) -c $<

clean:
	$(RM) *.o

.PHONY: clean
