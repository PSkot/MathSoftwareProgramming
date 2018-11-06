#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* Structure representing a sparse matrix in triplet form */
typedef struct sparse_triplet {
  size_t m; /* number of rows */
  size_t n; /* number of columns */
  size_t nnz; /* number of nonzeros */
  size_t * I; /* pointer to array with row indices */
  size_t * J; /* pointer to array with column indices */
  double * V; /* pointer to array with values */
} sparse_t;





sparse_t * read_sparse(const char * filename){

  FILE *fp;
  char buf[20];
  sparse_t* file = (sparse_t*)malloc(sizeof(sparse_t*));

  if ((fp = fopen(filename, "r")) == NULL) {
  fprintf(stderr,"Error opening file.\n");
  exit(EXIT_FAILURE);
  };

  

}
