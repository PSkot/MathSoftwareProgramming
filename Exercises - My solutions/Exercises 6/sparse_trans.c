#include "sparse_triplet.h"

/* Sparse matrix-vector product */
void sparse_triplet_trans(struct sparse_triplet *A) {


    size_t a;
    a = A->n;
    A->n = A->m;
    A->m = a;

    for (size_t i = 0; i < A->nnz; i++) {
      a = A->I[i];
      A->I[i] = A->J[i];
      A->J[i] = a;
    }
}
