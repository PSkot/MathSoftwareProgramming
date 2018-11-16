CC=gcc
CFLAGS=-Wall -std=c99

# Assume MSYS2/MinGw -- override below if macOS or Gbar
CPPFLAGS=-I/opt/OpenBLAS/lib
LDFLAGS = -L/opt/OpenBLAS/lib
LDLIBS=-lopenblas

.PHONY: all clean

all: Test

clean:
	-$(RM) Test.o
	-$(RM) Test


run:
	./Test
