#include "matrix_io.h"
#include <math.h>

/* norm_fro
Purpose:
  Computes the Frobenius norm of a matrix.

Arguments:
  pA         a pointer to a matrix_t
  nrm        a pointer to a double

Return value:
  An int with one of the following values:
   - MATRIX_IO_SUCCESS if no error occured
   - MATRIX_IO_ILLEGAL_INPUT if an input is NULL
   - MATRIX_IO_DIMENSION_MISMATCH if one of the matrix dim. is 0
*/
int norm_fro(const matrix_t * pA, double * nrm) {

  if(pA == NULL || nrm == NULL || pA->A == NULL || pA->A[0] == NULL)
    return MATRIX_IO_ILLEGAL_INPUT;

  if(pA->n == 0 || pA->m == 0)
    return MATRIX_IO_DIMENSION_MISMATCH;

  unsigned int n = pA->n;
  unsigned int m = pA->m;
  *nrm = 0.0;

  for (unsigned int i = 0; i < m; i++){
    for (unsigned int j = 0; j < n; j++) {
    *nrm += pA->A[i][j]*pA->A[i][j];
    }
  }

  *nrm = sqrt(*nrm);

  return MATRIX_IO_SUCCESS;

}
