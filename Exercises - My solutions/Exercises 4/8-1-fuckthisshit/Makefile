CFLAGS=-Wall -std=c99
LDLIBS=-lm
bc_81: avg.o read_input.o
avg.o: avg.h
read_input.o: read_input.h
.PHONY: clean run
clean:
	-$(RM) *.o bc_81
run: bc_81
	./bc_81
