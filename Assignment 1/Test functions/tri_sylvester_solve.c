#include <stdlib.h>
#include <math.h>
#include "matrix.h"

double* fwsubst(unsigned long n, double alpha, double **R, double *b);

int tri_sylvester_solve(const matrix_t *R, matrix_t *C){

  //Ensure correct dimensions and no NULL pointers
  if(
  (R == NULL) ||
  (C == NULL) ||
  !(C->n == C->m && R->n == R->m && C->n == R->n) ||
  (C->n == 0)
  )
  {
    return -2;
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
        return -1;
    }
  }

  //Success
  return 0;
}
