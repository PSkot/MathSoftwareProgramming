#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "matrix.h"

double* fwsubst(unsigned long n, double alpha, double **R, double *b);
matrix_t* tri_sylvester_solve(const matrix_t *R, matrix_t *C);
double **malloc_array2d(size_t m, size_t n);

int main(int argc, char const *argv[]) {
    //Declare variables
    unsigned long n = 5;
    double **RE = malloc_array2d(n, n);
    double **CE = malloc_array2d(n, n);
    matrix_t R = {.m=n, .n=n, .A=RE};
    matrix_t C = {.m=n, .n=n, .A=CE};

    //Assign values to R
    for(size_t i = 0; i < n; ++i){
      for(size_t j = 0; j < n; ++j){
        R.A[i][j] = j+1+5*i;
      }
    }

    //Make R upper triangular
    for(size_t i = 0; i < n; ++i){
      for(size_t j = 0; j < n; ++j){
        if(i > j)
          R.A[i][j] = 0;
      }
    }

    //Assign values to C
    for(size_t i = 0; i < n; ++i){
      for(size_t j = 0; j < n; ++j){
        C.A[i][j] = j+1+5*i;
      }
    }

  //Print R
  printf("R:\n");

  for(size_t i = 0; i < n; ++i){
    for(size_t j = 0; j < n; ++j){
      printf("%.0lf\t", R.A[i][j]);
      }
      printf("\n");
  }

  //Print b
  printf("\nC:\n");

  for(size_t i = 0; i < n; ++i){
    for(size_t j = 0; j < n; ++j){
      printf("%.0lf\t", C.A[i][j]);
      }
      printf("\n");
  }

  //Call tri_sylvester_solve function
  tri_sylvester_solve(&R, &C);

  //Print solution X (from overwritten C)
  printf("\nX:\n");

  for(size_t i = 0; i < n; ++i){
    for(size_t j = 0; j < n; ++j){
      printf("%.4lf\t", C.A[i][j]);
      }
      printf("\n");
  }

    printf("\n");

  return 0;
}


matrix_t* tri_sylvester_solve(const matrix_t *R, matrix_t *C){

  //Ensure correct dimensions and no NULL pointers
  if(
  (R == NULL) ||
  (C == NULL) ||
  !(C->n == C->m && R->n == R->m && C->n == R->n) ||
  (C->n == 0)
  )
  {
    return NULL;
  }

  //Run step 2 for the first row of X (overwriting C)
  C->A[0] = fwsubst(C->n, R->A[0][0], R->A, C->A[0]);

  //Apply step 1 and 2 for remaining X's (overwriting C)
  for(size_t k = 1; k < C->n; ++k){
    double* sum = (double*)malloc(C->n*sizeof(double));
    for(size_t i = 0; i <= k - 1; ++i){
      for(size_t j = 0; j < C->n; ++j){
      sum[j] += C->A[i][j]*R->A[i][k];
      }
    }
      for(size_t j = 0; j < C->n; ++j){
        //Step 1
        C->A[k][j] -= sum[j];
      }
        //Step 2
        C->A[k] = fwsubst(C->n, R->A[k][k], R->A, C->A[k]);
  }

  //Check for numerical failure, return -1 if failure
  for(size_t i = 0; i < C->n; ++i){
    for(size_t j = 0; j < C->n; ++j){
      if(!isfinite(C->A[i][j]))
        return NULL;
    }
  }

  //Success
  return C;
}

double* fwsubst(
  unsigned long n,
  double alpha,
  double **R,  /* two-dimensional array, row-major */
  double *b    /* one-dimensional array */
  ){

    //Calculate first solution element x (overwriting b)
    b[0] /= alpha + R[0][0];

    //Calculate the remaining x's through forward substitution (overwriting b)
    for(size_t k = 1; k < n; ++k){
      double sum = 0.0;
      for(size_t i = 0; i <= k - 1; ++i){
        sum += b[i]*R[i][k];
      }
      b[k] = (b[k] - sum)/(alpha + R[k][k]);
    }

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
