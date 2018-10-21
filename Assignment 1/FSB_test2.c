#include <math.h>
#include <stdint.h>
#include <stdlib.h>

double **malloc_array2d(size_t m, size_t n);
int fwsubst(
  unsigned long n,
  double alpha,
  double **R,  /* two-dimensional array, row-major */
  double *b    /* one-dimensional array */
);

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}

int fwsubst(
  unsigned long n,
  double alpha,
  double **R,  /* two-dimensional array, row-major */
  double *b    /* one-dimensional array */
  ){

    //Allocate memory
    R = malloc_array2d(n, n);
    b = malloc(n*sizeof(double));

    //Calculate first solution element x (overwriting b)
    b[0] /= alpha + R[0][0];

    //Calculate the remaining x's
    for(size_t k = 1; k < n; ++k){
      double sum = 0.0;
      for(size_t i = 0; i <= k - 1; ++i){
        sum += b[i]*R[i][k];
      }
      b[k] = (b[k] - sum)/(alpha + R[k][k]);
    }

    //Check for numerical failure, return -1 if failure
      for(size_t i = 0; i < n; ++i)
      {
        if(fabs(b[i]) == INFINITY || fabs(b[i]) == NAN)
          return -1;
      }

    //Success
    return b[1];
}

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
