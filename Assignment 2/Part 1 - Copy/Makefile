CC=gcc
CFLAGS=-Wall -std=c99

# Assume MSYS2/MinGw -- override below if macOS or Gbar
CPPFLAGS=-I/opt/OpenBLAS
LDFLAGS = -L/opt/OpenBLAS/lib
LDLIBS=-lopenblas

.PHONY: clean run
	
clean:
	-$(RM) call_dgesv_test

run:
	./call_dgesv_test
