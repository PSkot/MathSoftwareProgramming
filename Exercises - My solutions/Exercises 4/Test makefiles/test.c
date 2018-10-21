/* test.c */
#include "array.h"
#include <math.h>
#include <stdio.h>
int main(int argc, char const *argv[]) {
size_t m = 10, n = 5;
double **E = malloc_array2d(m, n);
for (size_t i = 0; i < 10; i++) {
  for (size_t j = 0; j < 5; j++) {
      E[i][j] = exp(-i * n - j);
    }
  }
free_array2d(E);
if (malloc_array2d(m, 0) != NULL)
  return -1;
if (malloc_array2d(0, n) != NULL)
  return -1;
if (malloc_array2d(0, 0) != NULL)
  return -1;


return 0;

}
