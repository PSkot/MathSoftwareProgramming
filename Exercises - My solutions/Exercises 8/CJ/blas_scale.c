#include <stdlib.h>
#include <ctype.h>

/* DSCAL (scale double array)                      */
void dscal_(
    const int * n,          /* length of array     */
    const double * a,       /* scalar a            */
    double * x,             /* array x             */
    const int * incx        /* array x, stride     */
);

/* Scale the k'th row of a two-dimensional row-major array */
int scale_row(double alpha, double **A, int m, int n, int k) {
    int incx = 1;
    if(k<0 || m<0 || n<0  || k>=n || A == NULL)
      return -1;

    dscal_(&n, &alpha, A[k], &incx);
    return 0;
}

/* Scale the k'th column of a two-dimensional row-major array */
int scale_column(double alpha, double **A, int m, int n, int k) {
    int incx = n;
    if(k<0 || m<0 || n<0 || k>=n || A == NULL)
      return -1;

    dscal_(&m, &alpha, *A+k, &incx);
    return 0;
}

/* Scale the diagonal elements of a square two-dimensional row-major array */
int scale_diag(double alpha, double **A, int m, int n) {
    if(m!=n || n<0 || m<0 || A == NULL)
      return -1;
    int incx = n+1;
    dscal_(&m, &alpha, *A, &incx);
    return 0;
}
