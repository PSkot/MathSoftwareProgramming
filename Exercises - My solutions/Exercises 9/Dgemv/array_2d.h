#include <stdlib.h>

double **malloc_2d(size_t m, size_t n)
{
// Check dimensions and check m*n for overflow
  if (m == 0 || n == 0 || m > SIZE_MAX / n)
    return NULL;
// Allocate two-dimensional array
  double **B = (double**)malloc(m * sizeof(*B));
  if (B == NULL)
    return NULL;
  B[0] = (double*)malloc(m * n * sizeof(double));
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
void free_2d(double **ptr) {
free(ptr[0]);
free(ptr);
return;
}