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
  if(A == NULL || b == NULL){
    fprintf(stderr,"Matrix A and/or vector b is NULL\n");
    return -9;
  }

  if(A->m != A->n){
    fprintf(stderr,"A is not a square matrix\n");
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return -10;
  }

  if(A->n != b->n){
    fprintf(stderr,"Dimensions of A and b are incompatible\n");
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return -11;
  }

  if(A->A == NULL || A->A[0] == NULL || b->v == NULL){
    fprintf(stderr,"Memory allocation error\n");
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return -12;
  }

  const int n = A->n, nrhs = 1, LDA = n, LDB = n;
  int info;
  int ipiv[n];

  matrix_t * A_trans = malloc_matrix(n, n);
  if(A_trans == NULL || A_trans->A == NULL || A_trans->A[0] == NULL){
    fprintf(stderr,"Memory allocation failure\n");
    free_matrix(A_trans);
    free_matrix(A);
    free_vector(b);
    A_trans = NULL;
    A = NULL;
    b = NULL;
    return -12;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++){
      A_trans->A[j][i] = A->A[i][j];
    }
  }

  free_matrix(A);
  A = NULL;

  dgesv_(&n, &nrhs, *A_trans->A, &LDA, ipiv, b->v, &LDB, &info);

  free_matrix(A_trans);
  A_trans = NULL;

  return info;
}
