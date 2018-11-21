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
  matrix_t* A = read_matrix("A.txt");
  vector_t* b = read_vector("b.txt");

  //Call function call_dgesv and store return value (info) for error checking
  int info = call_dgesv(A, b);

  //Check for illegal values through info argument in dgesv_
  if(info < 0 && info > -9){
    fprintf(stderr,"Call_dgesv: Argument %d had an illegal value\n", -info);
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return EXIT_FAILURE;
  }

  //Check for singularity of U through info argument in dgesv_
  if(info > 0){
    fprintf(stderr,"Call_dgesv: Factor U is exactly singular. Solution could not be computed\n");
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return EXIT_FAILURE;
  }

  //Check for file errors when writing solution to x
  if(write_vector("x.txt", b) != MATRIX_IO_SUCCESS){
    fprintf(stderr,"File error occured\n");
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return EXIT_FAILURE;
  }

  for (unsigned int i = 0; i < b->n; i++) {
    if(!isfinite(b->v[i])){
      fprintf(stderr,"Numerical error in solution x\n");
      free_matrix(A);
      free_vector(b);
      A = NULL;
      b = NULL;
      return EXIT_FAILURE;
    }
  }

  //Free pointers
  free_matrix(A);
  free_vector(b);
  A = NULL;
  b = NULL;

  return EXIT_SUCCESS;
}
