#include "sparse_triplet.h"

/* Sparse matrix-vector product */
void sparse_triplet_mv(
    const struct sparse_triplet *A,
    const double *x,
    double *y)
{

    double* sum = (double*)calloc(A->m, sizeof(double*));

    for (size_t i = 0; i < A->nnz; i++) {
        sum[A->I[i]] += A->V[i]*x[A->J[i]];
      }

    for (size_t i = 0; i < A->m; i++) {
      y[i] += sum[i];
    }

}
