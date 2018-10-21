/* array.h */
#ifndef ARRAY_H
#define ARRAY_H
#include <stdlib.h>
#include <stdint.h>
double ** malloc_array2d(size_t m, size_t n);
void free_array2d(double **ptr);
#endif
