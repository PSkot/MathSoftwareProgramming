#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

double ** malloc_array2d(size_t n);
int fwsubst(unsigned long n, double alpha, double **R, double *b);

int main(void) {
  unsigned long n = 5;
  double alpha = 2.5;
  double **R;
  double *b;

  R = malloc_array2d(n);
  b = (double*)malloc(n*sizeof(double));

  for(size_t i = 0; i < n; ++i){
    for(size_t j = 0; j < n; ++j){
      R[i][j] = j+1+5*i;
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
    return 0;
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
