CFLAGS=-Wall -std=c99
LDLIBS=-lm
program: avgarray.o
avgarray.o: avgarray.h
.PHONY: clean run
clean:
	-$(RM) *.o program
run: program
	./program
