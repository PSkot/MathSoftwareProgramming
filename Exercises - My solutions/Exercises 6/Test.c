#include <stdio.h>
#include <float.h>
#include "sparse_triplet.h"

struct sparse_triplet * read_sparse(const char * filename);
void free_sparse(struct sparse_triplet * A);

int main(int argc, char const *argv[]) {
  struct sparse_triplet * A = read_sparse("myfile.txt");
  printf("%d", A->I[0]);
  return 0;
}

/* Reads a sparse matrix from a file.

Arguments
  filename    string (char array)

Return value
  The function returns a pointer to a struct sparse_triplet, and NULL is
  returned in case of failure.

Memory:
  The function allocates a struct sparse_triplet. It is the caller's
  responsibility to deallocate this using free_sparse().
*/
struct sparse_triplet * read_sparse(const char * filename) {

  FILE *fp;
  size_t i,m,n,nnz;
  struct sparse_triplet * A;

  // Open file and read dimensions
  if ((fp = fopen(filename, "r")) == NULL ) {
    perror("File error");
    return NULL;
  }
  if (fscanf(fp,"%d %d %d",&m,&n,&nnz) != 3) {
    fprintf(stderr, "Failed to read matrix dimensions.\n");
    fclose(fp);
    return NULL;
  }

  /* Allocate sparse_triplet structure */
  A = (struct sparse_triplet*)malloc(sizeof(struct sparse_triplet));
  if ( A == NULL ) {
    fprintf(stderr,"Memory allocation failed.\n");
    fclose(fp);
    return NULL;
  }
  A->m = m;
  A->n = n;
  A->nnz = nnz;
  A->I = (size_t*)malloc(nnz*sizeof(*(A->I)));
  A->J = (size_t*)malloc(nnz*sizeof(*(A->J)));
  A->V = (double*)malloc(nnz*sizeof(*(A->V)));
  if ( A->I == NULL || A->J == NULL || A->V == NULL ) {
    fprintf(stderr,"Memory allocation failed.\n");
    free_sparse(A);
    fclose(fp);
    return NULL;
  }

  /* Read triplets and subtract 1 from indices */
  for (i=0;i<nnz;i++) {
    if ( fscanf(fp,"%d %d %lf",A->I+i,A->J+i,A->V+i)==3 ) {
      A->I[i]--;
      A->J[i]--;
    }
    else {
      fprintf(stderr, "Failed to read entry on line %d.\n",i+2);
      free_sparse(A);
      fclose(fp);
      return NULL;
    }
  }

  /* Close file and return pointer to sparse_triplet structure */
  fclose(fp);
  return A;
}


void free_sparse(struct sparse_triplet * A) {
    if ( A == NULL ) return;
    free(A->I);
    free(A->J);
    free(A->V);
    free(A);
    return;
}
