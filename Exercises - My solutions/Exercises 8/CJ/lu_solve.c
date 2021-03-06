#include <stdlib.h>
#include <math.h>

/** DTRSV
 *  BLAS level 2 routine for forward/back substitution
 *  Documentation: http://www.netlib.org/blas/#_level_2
 */
void dtrsv_(
  const char * uplo,  /* upper 'U' or lower 'L'               */
  const char * trans, /* not trans. 'N' or trans. 'T'         */
  const char * diag,  /* not unit diag. 'N' or unit diag. 'U' */
  const int * n,      /* dimension                            */
  const double * A,   /* column-major matrix of order n       */
  const int * lda,    /* leading dimension of A               */
  double * x,         /* right-hand side                      */
  const int * incx    /* stride for array x                   */
);


/** Solves system of equations L*U*x = b where
 *  L is unit lower triangular and U is upper triangular.
 *  The matrices L and U must be stored in a single array M
 *  of size n-by-n. On exit, the array b is overwritten by
 *  the solution x.
 *
 *  If successful, the function returns zero, and in case
 *  of an error, the return value is -1.
 *
 *  Inputs:
 *    n       the size of the array M
 *    M       dynamically allocated two-dimensional array of size n-by-n
 *    b       one-dimensional array of length n
 */
int lu_solve(int n, double ** M, double * b) {


  char uplo, trans, diag;
  int incx = 1;

  if(M == NULL || M[0] == NULL || b == NULL || n <= 0)  return -1;

  for (int i = 0; i < n; i++) {
    if(!isnormal(M[i][i])) return -1;
  }

  uplo = 'U';
  trans = 'T';
  diag = 'U';

  dtrsv_(&uplo, &trans, &diag, &n, *M, &n, b, &incx);

  uplo = 'L';
  trans = 'T';
  diag = 'N';

  dtrsv_(&uplo, &trans, &diag, &n, *M, &n, b, &incx);


  return 0;
}
