#include <stdio.h>

void dscal_( /* Prototype for BLAS dscal */
  const int * n, /* length of array */
  const double * a, /* scalar a */
  double * x, /* array x */
  const int * incx /* array x, stride */
);

int main(void) {
  int i,incx,n;
  double a, x[5] = {2.0,2.0,2.0,2.0,2.0};
  n = 5; a = 3.0; incx = 1;
  dscal_(&n, &a, x, &incx); // Scale the vector x by 3.0

  for(i = 0; i < n; i++)
    printf("%f\n", x[i]);

  return 0;
}
