#include <stdlib.h>
#include "cblas.h"

/* CBLAS_DSCAL (scale array)
void cblas_dscal(
    const int n,           // length of array
    const double a,        // scalar a
    double * x,            // array x
    const int incx         // array x, stride
);
*/

/* Scale the k'th row of a two-dimensional row-major array */
int scale_row(double alpha, double **A, int m, int n, int k) {
    int incx = 1;
    if(m<0 || n<0 || k<0 || A == NULL || k >= n)
      return -1;
    cblas_dscal(n, alpha, A[k], incx);
    return 0;
}

/* Scale the k'th column of a two-dimensional row-major array */
int scale_column(double alpha, double **A, int m, int n, int k) {
  int incx = n;
  if(m<0 || n<0 || k<0 || A == NULL || k >= n)
    return -1;
  cblas_dscal(m, alpha, *A+k, incx);
  return 0;
}

/* Scale the diagonal elements of a square two-dimensional row-major array */
int scale_diag(double alpha, double **A, int m, int n) {
  int incx = n+1;
  if(m<0 || n<0 || m!=n || A == NULL)
    return -1;
  cblas_dscal(m, alpha, *A, incx);
  return 0;
}
