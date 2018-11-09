#include <stdlib.h>

void my_dgemv_v2(
    int m,         /* number of rows                   */
    int n,         /* number of columns                */
    double alpha,  /* scalar                           */
    double ** A,   /* two-dim. array A of size m-by-n  */
    double * x,    /* one-dim. array x of length n     */
    double beta,   /* scalar                           */
    double * y     /* one-dim. array x of length m     */
){

  double* sum = (double*)calloc(m, sizeof(double*));

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
      sum[i] += A[i][j]*x[j];

    }
  }

  for (int i = 0; i < m; i++) {
    y[i] = alpha*sum[i]+beta*y[i];
  }
}
