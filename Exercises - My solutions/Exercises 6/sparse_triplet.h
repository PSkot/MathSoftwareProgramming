#ifndef SPARSE_TRIPLET_H
#define SPARSE_TRIPLET_H

#include <stdlib.h>

struct sparse_triplet {
   size_t m;   /* number of rows     */
   size_t n;   /* number of columns  */
   size_t nnz; /* number of nonzeros */
   size_t * I; /* pointer to array with row indices    */
   size_t * J; /* pointer to array with column indices */
   double * V; /* pointer to array with values         */
};

#endif
