CC = gcc
CFLAGS=-Wall -std=c99
LDLIBS=-lm

test: test.o array.o
test.o: array.h
array.o: array.h

.PHONY: clean run

clean:
	-$(RM) test test.o array.o

run: test
	./test
