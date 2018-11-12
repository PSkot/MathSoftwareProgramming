#include <stdlib.h>

/* DSCAL (scale double array)                      */
void dscal_(
    const int * n,          /* length of array     */
    const double * a,       /* scalar a            */
    double * x,             /* array x             */
    const int * incx        /* array x, stride     */
);

/* Scale the k'th row of a two-dimensional row-major array */
int scale_row(double alpha, double **A, int m, int n, int k) {
    /* Insert your code here */
    return 0;
}

/* Scale the k'th column of a two-dimensional row-major array */
int scale_column(double alpha, double **A, int m, int n, int k) {
    /* Insert your code here */
    return 0;
}

/* Scale the diagonal elements of a square two-dimensional row-major array */
int scale_diag(double alpha, double **A, int m, int n) {
    /* Insert your code here */
    return 0;
}
