#include <stdlib.h>

void dscal_(
const int * n, /* length of array */
const double * a, /* scalar a */
double * x, /* array x */
const int * incx /* array x, stride */
);

/* Scale the k'th row of a two-dimensional row-major array */
int scale_row(double alpha, double **A, int m, int n, int k) {
int incx = 1;
if ((A==NULL) || (m<0) || (n<0) || (k<0) || (k>=m)) return -1;
dscal_(&n,&alpha,A[k],&incx);
return 0;
}
/* Scale the k'th column of a two-dimensional row-major array */
int scale_column(double alpha, double **A, int m, int n, int k) {
int incx = n;
if ((A==NULL) || (m<0) || (n<0) || (k<0) || (k>=n)) return -1;
dscal_(&m,&alpha,*A+k,&incx);
return 0;
}
/* Scale the diagonal elements of a square two-dim. row-major array */
int scale_diag(double alpha, double **A, int m, int n) {
int incx = n+1;
if ((A==NULL) || (n!=m) || (m<0) || (n<0)) return -1;
dscal_(&n,&alpha,*A,&incx);
return 0;
}
