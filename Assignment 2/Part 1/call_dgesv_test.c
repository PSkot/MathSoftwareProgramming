#include "matrix_io.h"
#include <stdlib.h>
#include <stdio.h>

double **malloc_array2d(size_t n);
int call_dgesv(matrix_t * A, vector_t * b);

int main(int argc, char const *argv[]) {
  const int n = 3;
  double **RE = malloc_array2d(n);
  double *BE = (double*)calloc(n, sizeof(double*));
  matrix_t A = {.m=n, .n=n, .A=RE};
  vector_t b = {.n=n, .v=BE};

  //Assign values to R

  for(size_t i = 0; i < n; ++i){
    for(size_t j = 0; j < n; ++j){
      A.A[i][j] = rand() % 100 + 1;
    }
  }

  for(size_t i = 0; i < n; ++i){
      b.v[i] = rand() % 100 + 1;
  }

  printf("Matrix A:\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%f\t", A.A[i][j]);
    }
    printf("\n");
  }

  printf("\nVector b:\n");
    for (int i = 0; i < n; i++) {
      printf("%f\n", b.v[i]);
    }

  printf("\nSolution x:\n");

  call_dgesv(&A, &b);

  for(int i = 0; i < n; ++i){
    printf("%.2f\n", b.v[i]);
  }
}
