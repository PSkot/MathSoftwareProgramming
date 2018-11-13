CC=gcc
FC=gfortran
CFLAGS=-Wall -std=c99

# Assume MSYS2/MinGw -- override below if macOS or Gbar
CPPFLAGS=-I/mingw64/include/OpenBLAS/lib
LDFLAGS = -L/mingw64/include/OpenBLAS/lib
LDLIBS=-lopenblas

.PHONY: all clean

all: example_blas example_cblas

clean:
	-$(RM) *.o
	-$(RM) example_blas
	-$(RM) example_cblas

run:
	./example_blas
	./example_cblas
