CC=gcc
CFLAGS=-Wall -std=c99

# Assume MSYS2/MinGw -- override below if macOS or Gbar
CPPFLAGS=-I/mingw64/include/OpenBLAS/lib
LDFLAGS = -L/mingw64/include/OpenBLAS/lib
LDLIBS=-lopenblas

.PHONY: all clean

all: Test

clean:
	-$(RM) *.o
	-$(RM) Test


run:
	./Test
