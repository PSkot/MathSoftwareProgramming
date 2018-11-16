#include "matrix_io.h"

/* C prototype for LAPACK routine DGESV */
void dgesv_(const int *n,    /* columns/rows in A          */
            const int *nrhs, /* number of right-hand sides */
            double *A,       /* array A                    */
            const int *lda,  /* leading dimension of A     */
            int *ipiv,       /* pivoting array             */
            double *B,       /* array B                    */
            const int *ldb,  /* leading dimension of B     */
            int *info        /* status code                */
            );

/* call_dgesv : wrapper for LAPACK's DGESV routine

Purpose:
Solves system of equations A*x=b using LAPACK's DGESV routine
Upon exit, the input vector b is overwriten by the solution x.

Return value:
The function returns the output `info` from DGESV with the
following exceptions: the return value is

   -9 if the input A is NULL and/or the input B is NULL
   -10 if A is not a square matrix
   -11 if the dimensions of A and b are incompatible
   -12 in case of memory allocation errors.
*/
int call_dgesv(matrix_t * A, vector_t * b) {
  if(A == NULL || b == NULL) return -9;
  if(A->m != A->n) return -10;
  if(A->n != A->m || A->n || b->n) return -11;
  if(A->A == NULL || A->A[0] == NULL || b->v == NULL) return -12;

  const int n = A->n, nrhs = 1, LDA = A->n, LDB = b->n;
  int info;
  int ipiv[A->n];
  double* vec_b = (double*)calloc(n, sizeof(double*));
  vec_b = b->v;

  matrix_t * A_trans = malloc_matrix(n, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++){
      A_trans->A[j][i] = A->A[i][j];
    }
  }

  dgesv_(&n, &nrhs, *A_trans->A, &LDA, ipiv, vec_b, &LDB, &info);

  free_matrix(A_trans);

  return info;
}
