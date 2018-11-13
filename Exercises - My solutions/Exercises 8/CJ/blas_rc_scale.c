#include <stdlib.h>
#include <math.h>

/* DAXPY (double a x plus y)                          */
void daxpy_(
    const int * n,        /* length of arrays x and y */
    const double * a,     /* scalar a                 */
    const double * x,     /* array x                  */
    const int * incx,     /* array x, stride          */
    double * y,           /* array y                  */
    const int * incy      /* array y, stride          */
);

/** Adds alpha times row i to row j
 *
 * The input 'A' represents a two-dimensional row-major array of size m-by-n
 */
int add_row(double alpha, double **A, int m, int n, int i, int j) {
    /* Insert your code here */
    return 0;
}

/** Adds alpha times column i to column j
 *
 * The input 'A' represents a two-dimensional row-major array of size m-by-n
 */
int add_column(double alpha, double **A, int m, int n, int i, int j) {
    /* Insert your code here */
    return 0;
}
