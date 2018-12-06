#include "matrix_io.h"

/* dot
Purpose:
  Computes the inner product of two vectors.

Arguments:
  px         a pointer to a vector_t
  py         a pointer to a vector_t
  xy         a pointer to a double

Return value:
  An int with one of the following values:
   - MATRIX_IO_SUCCESS if no error occured
   - MATRIX_IO_ILLEGAL_INPUT if an input is NULL
   - MATRIX_IO_DIMENSION_MISMATCH if the vectors have diff. len.
*/
int dot(const vector_t * px, const vector_t * py, double * xy) {

  if(px == NULL || py == NULL || xy == NULL || px->v == NULL || py->v == NULL)
    return MATRIX_IO_ILLEGAL_INPUT;

  if(px->n != py->n || px->n == 0 || py->n == 0)
    return MATRIX_IO_DIMENSION_MISMATCH;

  unsigned int n = px->n;
  *xy = 0.0;

  for (unsigned int i = 0; i < n; i++) {
    *xy += px->v[i]*py->v[i];
  }

  return MATRIX_IO_SUCCESS;

}
