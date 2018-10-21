#include <stdlib.h>
#include <math.h>
#include "matrix.h"
#include <stdio.h>

double ** malloc_2d(unsigned long m, unsigned long n);

int main(int argc, char const *argv[]) {

  int n = 5;
  double **RE = malloc_2d(n,n);
  double *CE = malloc(n*sizeof(double));
  matrix_t R = {.m=n, .n=n, .A=RE};
  matrix_t C = {.m=n  .n=n, .v=CE};

  for (size_t i = 0; i < n; i++) {
    C.v[i] = i+1;
  }


  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      R.A[i][j] = j+1+i*5;
    }
  }

  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if(i > j)
        R.A[i][j] = 0;
    }
  }


  C.v[0] /= R.A[0][0]*2;

  for(size_t k = 1; k < R.n; ++k){
    double sum = 0.0;
    for(size_t i = 0; i <= k - 1; ++i){
        sum += C.v[i]*R.A[i][k];
    }
    C.v[k] = (C.v[k] - sum);
    sum = 0.0;
    for (size_t i = 0; i <= k - 1; ++i) {
      sum += C.v[i]*R.A[i][k];
    }
    C.v[k] = (C.v[k] - sum)/(R.A[k][k]*2);
  }
  for(size_t i = 0; i < n; ++i){
  printf("%.4lf\n", C.v[i]);
  }

  return 0;
}

double ** malloc_2d(unsigned long m, unsigned long n) {

  double ** dptr = malloc(m*sizeof(double *));
  if (dptr == NULL) return NULL;
  *dptr = calloc(m*n,sizeof(double));
  if (*dptr == NULL) {
    free(dptr);
    return NULL;
  }
  for (unsigned long i=1;i<m;i++) {
    dptr[i] = dptr[0] + i*n;
  }
  return dptr;
}
