#include <stdlib.h>
#ifdef _OPENMP
#include <omp.h>
#endif

void omp_dgemv_v1(
    int m,         /* number of rows                   */
    int n,         /* number of columns                */
    double alpha,  /* scalar                           */
    double ** A,   /* two-dim. array A of size m-by-n  */
    double * x,    /* one-dim. array x of length n     */
    double beta,   /* scalar                           */
    double * y     /* one-dim. array x of length m     */
){

  double* sum = (double*)calloc(m, sizeof(double*));


  for (int i = 0; i < m; i++) {
    #pragma omp parallel for
    for (int j = 0; j < n; j++) {
      sum[i] += A[i][j]*x[j];
    }
    y[i] = alpha*sum[i]+beta*y[i];
  }
  return;
}
