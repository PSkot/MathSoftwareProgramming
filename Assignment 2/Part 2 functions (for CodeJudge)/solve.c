#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "matrix_io.h"

int call_dgesv(matrix_t * A, vector_t * b);

int main(int argc, char *argv[]) {

  if (argc != 4) {
    fprintf(stderr,"Usage: %s A b x\n", argv[0]);
    return EXIT_FAILURE;
  }

  //Read Matrix A and vector b from files b.txt and A.txt
  matrix_t* A = read_matrix(argv[1]);
  vector_t* b = read_vector(argv[2]);

  int info = call_dgesv(A, b);

  //Check NULL input from Call_dgesv
  if(info == -9){
    fprintf(stderr,"Call_dgesv: Input A or b is NULL\n");
    free_matrix(A);
    free_vector(b);
    return EXIT_FAILURE;
  }

  //Check if A is square from Call_dgesv
  if(info == -10){
    fprintf(stderr,"Call_dgesv: A is not a square matrix\n");
    free_matrix(A);
    free_vector(b);
    return EXIT_FAILURE;
  }

  //Check if dimensions of A and b are compatible from Call_dgesv
  if(info == -11){
    fprintf(stderr,"Call_dgesv: Dimensions of A and b are incompatible\n");
    free_matrix(A);
    free_vector(b);
    return EXIT_FAILURE;
  }

  //Check for memory allocation errors from Call_dgesv
  if(info == -12){
    fprintf(stderr,"Call_dgesv: Memory allocation error\n");
    free_matrix(A);
    free_vector(b);
    return EXIT_FAILURE;
  }

  //Check for illegal values through info argument in dgesv_
  if(info < 0){
    fprintf(stderr,"Call_dgesv: Argument %d had an illegal value\n", -info);
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return EXIT_FAILURE;
  }

  //Check for singularity of U through info argument in dgesv_
  if(info > 0){
    fprintf(stderr,"Call_dgesv: Factor U is exactly or near singular. Solution could not be computed\n");
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return EXIT_FAILURE;
  }

  //Check for non numeric output in solution x
  for (unsigned int i = 0; i < b->n; i++) {
    if(!isfinite(b->v[i])){
      fprintf(stderr,"Numerical error in solution x\n");
      free_matrix(A);
      free_vector(b);
      return EXIT_FAILURE;
    }
  }

  //Check for file errors when writing solution to x
  if(write_vector(argv[3], b) != MATRIX_IO_SUCCESS){
    fprintf(stderr,"File error occured\n");
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return EXIT_FAILURE;
  }

  //Free pointers
  free_matrix(A);
  free_vector(b);
  A = NULL;
  b = NULL;

  return EXIT_SUCCESS;
}
