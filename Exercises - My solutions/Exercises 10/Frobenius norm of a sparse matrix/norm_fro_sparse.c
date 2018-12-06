#include "matrix_io.h"
#include <math.h>

/* norm_fro_sparse
Purpose:
  Computes the Frobenius norm of a sparse matrix in triplet form.

Arguments:
  pA         a pointer to a matrix_t
  nrm        a pointer to a double

Return value:
  An int with one of the following values:
   - MATRIX_IO_SUCCESS if no error occured
   - MATRIX_IO_ILLEGAL_INPUT if an input is NULL
   - MATRIX_IO_DIMENSION_MISMATCH if one of the matrix dim. is 0
*/
int norm_fro_sparse(const sparse_triplet_t * pA, double * nrm) {

  if(pA == NULL || nrm == NULL || pA->I == NULL || pA->J == NULL || pA->V == NULL)
    return MATRIX_IO_ILLEGAL_INPUT;

  if(pA->n == 0 || pA->m == 0 || pA->nnz == 0)
    return MATRIX_IO_DIMENSION_MISMATCH;

  unsigned int nnz = pA->nnz;
  *nrm = 0.0;

  for (unsigned int i = 0; i < nnz; i++)
    *nrm += pA->V[i]*pA->V[i];

  *nrm = sqrt(*nrm);

  return MATRIX_IO_SUCCESS;

}
