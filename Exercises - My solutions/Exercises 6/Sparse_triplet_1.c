#include <stdlib.h>
#include <string.h>

/* Structure representing a sparse matrix in triplet form */
typedef struct sparse_triplet {
  size_t m; /* number of rows */
  size_t n; /* number of columns */
  size_t nnz; /* number of nonzeros */
  size_t * I; /* pointer to array with row indices */
  size_t * J; /* pointer to array with column indices */
  double * V; /* pointer to array with values */
} sparse_t;





sparse_t * read_sparse(const char * filename);

  sparse_t* q = (sparse_t*)malloc(sizeof(*q));
  
