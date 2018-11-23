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

clean:
	-$(RM) *.o $(EXECUTABLE)

run: $(EXECUTABLE)
	-./$(EXECUTABLE)
