CC=gcc
CFLAGS=-Wall -std=c99

# Assume MSYS2/MinGw -- override below if macOS or Gbar
CPPFLAGS=-I/opt/OpenBLAS
LDFLAGS = -L/opt/OpenBLAS/lib
LDLIBS=-lopenblas
objects=$(patsubst %.c,%.o,$(wildcard *.c))

solve: $(objects)

.PHONY: clean run
clean:
	-$(RM) solve $(objects)

run:
	./solve A.txt b.txt x.txt
