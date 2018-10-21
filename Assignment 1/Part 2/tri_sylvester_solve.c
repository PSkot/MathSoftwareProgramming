#include <stdlib.h>
#include <math.h>
#include "matrix.h"

int fwsubst(
  unsigned long n,
  double alpha,
  double **R,  /* two-dimensional array, row-major */
  double *b    /* one-dimensional array */
);

int tri_sylvester_solve(const matrix_t *R, matrix_t *C) {

  

  return 0;
}


int fwsubst(
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

    //Check for numerical failure, return -1 if failure
      for(size_t i = 0; i < n; ++i)
      {
        if(!isfinite(b[i]))
          return -1;
      }

    //Success
    return 0;
}
