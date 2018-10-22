#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "matrix.h"

double ** malloc_array2d(size_t n);
int fwsubst(unsigned long n, double alpha, double **R, double *b);

int main(int argc, char const *argv[]) {
  int n = 3;
  double **RE = malloc_array2d(n);
  double **CE = malloc_array2d(n);
  matrix_t R = {.m=n, .n=n, .A=RE};
  matrix_t C = {.m=n  .n=n, .A=CE};


  for(size_t i = 0; i < n; ++i){
    for(size_t j = 0; j < n; ++j){
      R->A[i][j] = j+1+5*i;
    }
  }

  for(size_t i = 0; i < n; ++i){
    for(size_t j = 0; j < n; ++j){
      if(i > j)
        R[i][j] = 0;
    }
  }

  for(size_t i = 0; i < n; ++i){
    b[i] = i+1;
  }


    for(size_t k = 1; k < C->n; ++k){
      double* sum = malloc(C->n*sizeof(double));
      for(size_t i = 0; i <= k - 1; ++i){
        for(size_t j = 0; j < C->n; ++j){
        sum[j] += C->A[i][j]*R->A[i][k];
        }
        }
          C->A[k] = C->A[k] - sum;
          C->A[k] = fwsubst(C->n, R->A[k][k], R->A, C->A[k]);
        }
          return 0;

for(size_t i = 0; i < n; ++i){
  for(size_t j = 0; j < n; ++j){
    printf("%.2lf\t", R[i][j]);
    }
    printf("\n");
}

  printf("\n");

for(size_t i = 0; i < n; ++i){
  printf("%.2lf\n", b[i]);
}

  printf("\n");

//printf("%.2lf\n", fwsubst(n, alpha, R, b));

/*printf("%.4lf\n", R[0][0]);

for(size_t i = 0; i < n; ++i)
  printf("%.4lf\n", b[i]);*/
return 0;
}

int fwsubst(
  unsigned long n,
  double alpha,
  double **R,  /* two-dimensional array, row-major */
  double *b    /* one-dimensional array */
  ){
    //Check positive dimensions and check for overflow
    //R = malloc_array2d(n);
    //b = (double*)malloc(n*sizeof(double));
    /*if (n <= 0 || n*n > SIZE_MAX)
      return NULL;

    //Allocate memory to R and b
    R[0] = (double*)malloc(n*n*sizeof(double));
    if (R[0] == NULL) {
      free(R);
      return NULL;
    }
    for (size_t i = 1; i < n; i++)
      R[i] = R[0] + i * n;

    b = (double*)malloc(n*sizeof(double));*/


    //Ensure matrix is upper triangular
    /*for(size_t i = 0; i < n; ++i)
      for(size_t j = 0; j < n; ++j)
        if(i > j)
          R[i][j] = 0;*/

    //Calculate first solution element x (overwriting b)
    b[0] /= (alpha + R[0][0]);

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
double **malloc_array2d(size_t n) {

// Check dimensions and check m*n for overflow
  if (n == 0 || n > SIZE_MAX / n)
    return NULL;

// Allocate two-dimensional array
  double **B = (double**)malloc(n * sizeof(*B));
  if (B == NULL){
    printf("Failed memory step 1\n");
    return 0;}
  B[0] = (double*)malloc(n * n * sizeof(double));
  if (B[0] == NULL) {
    free(B);
    printf("Failed memory step 2\n");
    return 0;
  }
  for (size_t i = 1; i < n; i++)
    B[i] = B[0] + i * n;
  return B;
}
