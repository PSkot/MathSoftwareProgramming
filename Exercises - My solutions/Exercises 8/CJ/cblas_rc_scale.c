#include <stdlib.h>
#include <math.h>
#include "cblas.h"

/* CBLAS_DAXPY (double a x plus y)
void cblas_daxpy(
    const int n,            // length of array
    const double alpha,     // scalar a
    const double *x,        // array x
    const int incx,         // array x, stride
    double *y,              // array y
    const int incy);        // array y, stride
*/

/** Adds alpha times row i to row j
 *
 * The input 'A' represents a two-dimensional row-major array of size m-by-n
 */
int add_row(double alpha, double **A, int m, int n, int i, int j) {
  int inc = 1;
  if (A==NULL || A[0]==NULL || m <= 0 || n <= 0) return -1;
  if (i == j || i < 0 || j < 0 || i >= m || j >= m) return -1;
  cblas_daxpy(n, alpha, A[i], inc, A[j], inc);
  return 0;
}

/** Adds alpha times column i to column j
 *
 * The input 'A' represents a two-dimensional row-major array of size m-by-n
 */
int add_column(double alpha, double **A, int m, int n, int i, int j) {
  int inc = n;
  if (A==NULL || A[0]==NULL || m <= 0 || n <= 0) return -1;
  if (i == j || i < 0 || j < 0 || i >= n || j >= n) return -1;
  cblas_daxpy(m, alpha, *A+i, inc, *A+j, inc);
  return 0;
}
