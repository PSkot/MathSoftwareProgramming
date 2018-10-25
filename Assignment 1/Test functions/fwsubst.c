#include <stdlib.h>
#include "matrix.h"

//Forward substitution function
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
