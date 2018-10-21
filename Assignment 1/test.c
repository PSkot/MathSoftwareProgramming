#include <stdlib.h>
#include <stdint.h>
double ** malloc_array2d(size_t m, size_t n);
void free_array2d(double **ptr);

/* Allocate two-dimensional array of doubles */
double **malloc_array2d(size_t m, size_t n)
{
  // Check dimensions and check m*n for overflow
  if (m == 0 || n == 0 || m > SIZE_MAX / n)
    return NULL;
  // Allocate two-dimensional array
  double **B = malloc(m * sizeof(*B));
  if (B == NULL)
    return NULL;
  B[0] = malloc(m * n * sizeof(double));
  if (B[0] == NULL)
  {
    free(B);
    return NULL;
  }
  for (size_t i = 1; i < m; i++)
    B[i] = B[0] + i * n;
  return B;
}

/* Free two-dimensional array of doubles */
void free_array2d(double **ptr) {
free(ptr[0]);
free(ptr);
return;
}

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
