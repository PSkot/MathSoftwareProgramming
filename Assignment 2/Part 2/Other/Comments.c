//Check for NULL pointers A and b
/*if((A == NULL) || (b == NULL)){
  fprintf(stderr,"Input A or b is NULL\n");
  free_matrix(A);
  free_vector(b);
  return EXIT_FAILURE;
}

//Check for memory allocation
if((A->A == NULL) || (A->A[0] == NULL) || (b->v == NULL)){
  fprintf(stderr,"Memory allocation error\n");
  free_matrix(A);
  free_vector(b);
  A = NULL;
  b = NULL;
  return EXIT_FAILURE;
}

//Check dimensions and overflow of n*m
if((A->n == 0) || (A->m == 0) || (A->m > SIZE_MAX / A->n)){
  fprintf(stderr,"Zero dimensions or overflow\n");
  free_matrix(A);
  free_vector(b);
  A = NULL;
  b = NULL;
  return EXIT_FAILURE;
}

//Check whether A is a square matrix
if(A->m != A->n){
  fprintf(stderr,"A is not a square matrix\n");
  free_matrix(A);
  free_vector(b);
  A = NULL;
  b = NULL;
  return EXIT_FAILURE;
}

//Check whether dimensions of A and b are compatible
if(A->n != b->n){
  fprintf(stderr,"Dimensions of A and b are incompatible\n");
  free_matrix(A);
  free_vector(b);
  A = NULL;
  b = NULL;
  return EXIT_FAILURE;
}

//Check for numerical errors/invalid input in A
for (unsigned int i = 0; i < A->n; i++) {
  for (unsigned int j = 0; j < A->m; j++) {
    if(!isfinite(A->A[i][j])){
      fprintf(stderr,"Numerical error in matrix A\n");
      free_matrix(A);
      free_vector(b);
      A = NULL;
      b = NULL;
      return EXIT_FAILURE;
    }
  }
}

//Check for numerical errors/invalid input in b
for (unsigned int i = 0; i < b->n; i++) {
  if(!isfinite(b->v[i])){
    fprintf(stderr,"Numerical error in vector b\n");
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return EXIT_FAILURE;
  }
}*/

//Check NULL input from Call_dgesv
/*if(info == -9){
  fprintf(stderr,"Call_dgesv: Input A or b is NULL\n");
  free_matrix(A);
  free_vector(b);
  A = NULL;
  b = NULL;
  return EXIT_FAILURE;
}

//Check if A is square from Call_dgesv
if(info == -10){
  fprintf(stderr,"Call_dgesv: A is not a square matrix\n");
  free_matrix(A);
  free_vector(b);
  A = NULL;
  b = NULL;
  return EXIT_FAILURE;
}

//Check if dimensions of A and b are compatible from Call_dgesv
if(info == -11){
  fprintf(stderr,"Call_dgesv: Dimensions of A and b are incompatible\n");
  free_matrix(A);
  free_vector(b);
  A = NULL;
  b = NULL;
  return EXIT_FAILURE;
}

//Check for memory allocation errors from Call_dgesv
if(info == -12){
  fprintf(stderr,"Call_dgesv: Memory allocation error\n");
  free_matrix(A);
  free_vector(b);
  A = NULL;
  b = NULL;
  return EXIT_FAILURE;
}*/
