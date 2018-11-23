CC=gcc
CFLAGS=-Wall -std=c99 -g
EXECUTABLE=solve

# Assume MSYS2/MinGw -- override below if macOS or Gbar
CPPFLAGS=-I/opt/OpenBLAS
LDFLAGS = -L/opt/OpenBLAS/lib
LDLIBS=-lopenblas


.PHONY: all clean run

all: $(EXECUTABLE)

$(EXECUTABLE): matrix_io.o call_dgesv.o solve.o

matrix_io.o: matrix_io.h
call_dgesv.o: matrix_io.h
solve.o: matrix_io.h

clean:
	-$(RM) *.o $(EXECUTABLE)

run: $(EXECUTABLE)
	-./$< $(ARGS)
