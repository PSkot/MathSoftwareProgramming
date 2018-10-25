#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

double* fwsubst(
  unsigned long n,
  double alpha,
  double **R,  /* two-dimensional array, row-major */
  double *b    /* one-dimensional array */
);

double **malloc_array2d(size_t m, size_t n);

int main(int argc, char const *argv[]) {
    //Declare variables
    unsigned long n = 5;
    double alpha = 2.5;
    double **R;
    double *b;

    //Allocate memory
    R = malloc_array2d(n, n);
    b = (double*)malloc(n*sizeof(double));

    //Assign values to R
    for(size_t i = 0; i < n; ++i){
      for(size_t j = 0; j < n; ++j){
        R[i][j] = j+1+5*i;
      }
    }

    //Make R upper triangular
    for(size_t i = 0; i < n; ++i){
      for(size_t j = 0; j < n; ++j){
        if(i > j)
          R[i][j] = 0;
      }
    }

    //Assign values to b
    for(size_t i = 0; i < n; ++i){
      b[i] = i+1;
    }

  //Print R
  printf("R:\n");

  for(size_t i = 0; i < n; ++i){
    for(size_t j = 0; j < n; ++j){
      printf("%.0lf\t", R[i][j]);
      }
      printf("\n");
  }

  //Print b
  printf("\nb:\n");

  for(size_t i = 0; i < n; ++i){
    printf("%.0lf\n", b[i]);
  }

    printf("\nx:\n");

  //Call forward substitution function
  fwsubst(n, alpha, R, b);

  //Print solution x (from overwritten b)
  for(size_t i = 0; i < n; ++i){
    printf("%.4lf\n", b[i]);
  }

    printf("\n");

  return 0;
}

double* fwsubst(
  unsigned long n,
  double alpha,
  double **R,  /* two-dimensional array, row-major */
  double *b    /* one-dimensional array */
  ){

    //Calculate first solution element x (overwriting b)
    b[0] /= alpha + R[0][0];

    //Calculate the remaining x's (overwriting b)
    for(size_t k = 1; k < n; ++k){
      double sum = 0.0;
      for(size_t i = 0; i <= k - 1; ++i){
        sum += b[i]*R[i][k];
      }
      b[k] = (b[k] - sum)/(alpha + R[k][k]);
    }

    /*//Check for numerical failure, return -1 if failure
      for(size_t i = 0; i < n; ++i)
      {
        if(!isfinite(b[i]))
          return -1;
      }*/

    //Success
    return b;
}

double **malloc_array2d(size_t m, size_t n)
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
