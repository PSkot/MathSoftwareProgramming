#include "matrix_io.h"
#include <stdlib.h>
#include <stdio.h>

double **malloc_array2d(size_t n, size_t m);
int call_dgesv(matrix_t * A, vector_t * b);

int main(int argc, char const *argv[]) {
  const int n = 3;
  double **RE = malloc_array2d(n, n);
  double *BE = (double*)calloc(n, sizeof(double*));
  matrix_t A = {.m=n, .n=n, .A=RE};
  vector_t b = {.n=n, .v=BE};

  //Assign values to R

  for(size_t i = 0; i < n; ++i){
    for(size_t j = 0; j < n; ++j){
      A.A[i][j] = rand() % 100 + 1;
    }
  }

  for(size_t i = 0; i < n; ++i){
      b.v[i] = rand() % 100 + 1;
  }

  printf("Matrix A:\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%f\t", A.A[i][j]);
    }
    printf("\n");
  }

  printf("\nVector b:\n");
    for (int i = 0; i < n; i++) {
      printf("%f\n", b.v[i]);
    }

  printf("\nSolution x:\n");

  call_dgesv(&A, &b);

  for(int i = 0; i < n; ++i){
    printf("%.2f\n", b.v[i]);
  }
}


/* C prototype for LAPACK routine DGESV */
void dgesv_(const int *n,    /* columns/rows in A          */
            const int *nrhs, /* number of right-hand sides */
            double *A,       /* array A                    */
            const int *lda,  /* leading dimension of A     */
            int *ipiv,       /* pivoting array             */
            double *B,       /* array B                    */
            const int *ldb,  /* leading dimension of B     */
            int *info        /* status code                */
            );

/* call_dgesv : wrapper for LAPACK's DGESV routine

Purpose:
Solves system of equations A*x=b using LAPACK's DGESV routine
Upon exit, the input vector b is overwriten by the solution x.

Return value:
The function returns the output `info` from DGESV with the
following exceptions: the return value is

   -9 if the input A is NULL and/or the input B is NULL
   -10 if A is not a square matrix
   -11 if the dimensions of A and b are incompatible
   -12 in case of memory allocation errors.
*/
int call_dgesv(matrix_t * A, vector_t * b) {
  if(A == NULL || b == NULL){
    fprintf(stderr,"Matrix A and/or vector b is NULL\n");
    return -9;
  }

  if(A->m != A->n){
    fprintf(stderr,"A is not a square matrix\n");
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return -10;
  }

  if(A->n != b->n){
    fprintf(stderr,"Dimensions of A and b are incompatible\n");
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return -11;
  }

  if(A->A == NULL || A->A[0] == NULL || b->v == NULL){
    fprintf(stderr,"Memory allocation error\n");
    free_matrix(A);
    free_vector(b);
    A = NULL;
    b = NULL;
    return -12;
  }

  const int n = A->n, nrhs = 1, LDA = n, LDB = n;
  int info;
  int ipiv[n];

  matrix_t * A_trans = malloc_matrix(n, n);
  if(A_trans == NULL || A_trans->A == NULL || A_trans->A[0] == NULL){
    fprintf(stderr,"Memory allocation failure\n");
    free_matrix(A_trans);
    free_matrix(A);
    free_vector(b);
    A_trans = NULL;
    A = NULL;
    b = NULL;
    return EXIT_FAILURE;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++){
      A_trans->A[j][i] = A->A[i][j];
    }
  }

  free_matrix(A);
  A = NULL;

  dgesv_(&n, &nrhs, *A_trans->A, &LDA, ipiv, b->v, &LDB, &info);

  free_matrix(A_trans);
  A_trans = NULL;

  return info;
}


/* Allocate two-dimensional array of doubles */
double **malloc_array2d(size_t m, size_t n) {

  // Check dimensions and check m*n for overflow
  if (m == 0 || n == 0 || m > SIZE_MAX / n)
    return NULL;
  // Allocate two-dimensional array
  double **B = (double**)malloc(m * sizeof(*B));
  if (B == NULL)
    return NULL;
  B[0] = (double*)malloc(m * n * sizeof(double));
  if (B[0] == NULL) {
    free(B);
    return NULL;
  }
  for (size_t i = 1; i < m; i++)
    B[i] = B[0] + i * n;
  return B;
  }

  #include "matrix_io.h"

  /************************************/
  /* Allocation/deallocation routines */
  /************************************/

  /* malloc_vector
  Purpose:
    Allocates memory for a vector of length n

  Arguments:
    n          length of vector

  Return value:
    A pointer to a vector_t, or NULL if an error occured
  */
  vector_t * malloc_vector(unsigned long n) {
  	vector_t * pv = malloc(sizeof(*pv));
  	if ( pv == NULL ) {
  		MEM_ERR;
  		return NULL;
  	}
  	pv->n = n;
  	pv->v = calloc(n,sizeof(*pv->v));
  	if ( pv->v == NULL ) {
  		MEM_ERR;
  		free(pv);
  		return NULL;
  	}
  	return pv;
  }

  /* free_vector
  Purpose:
    Deallocates a vector

  Arguments:
    pv         pointer to vector_t

  Return value:
    None
  */
  void free_vector(vector_t * pv) {
  	if ( pv == NULL ) return;
  	free(pv->v);
  	free(pv);
  }

  /* malloc_matrix
  Purpose:
    Allocates memory for a matrix of size m-by-n

  Arguments:
    m          number of rows
  	n          number of columns

  Return value:
    A pointer to a matrix_t, or NULL if an error occured
  */
  matrix_t * malloc_matrix(unsigned long m, unsigned long n) {
  	size_t i;
  	matrix_t * pm=NULL;
  	pm = malloc(sizeof(*pm));
  	if ( pm == NULL ) {
  		MEM_ERR;
  		return NULL;
  	}
  	pm->m = m;
  	pm->n = n;
  	pm->A = malloc(m*sizeof(*pm->A));
  	if ( pm->A == NULL ) {
  		MEM_ERR;
  		free(pm);
  		return NULL;
  	}
  	pm->A[0] = calloc(m*n,sizeof(*pm->A[0]));
  	if ( pm->A[0] == NULL ) {
  		MEM_ERR;
  		free(pm->A);
  		free(pm);
  		return NULL;
  	}
  	for (i=1; i<m; i++) pm->A[i] = pm->A[0] + i*n;
  	return pm;
  }

  /* free_matrix
  Purpose:
    Deallocates a matrix

  Arguments:
    pm         pointer to matrix_t

  Return value:
    None
  */
  void free_matrix(matrix_t * pm) {
  	if ( pm == NULL ) return;
  	free(pm->A[0]);
  	free(pm->A);
  	free(pm);
  	return;
  }

  /* malloc_sparse_triplet
  Purpose:
    Allocates memory for a sparse matrix in triplet form

  Arguments:
    m          number of rows
  	n          number of columns
  	nnz        number of nonzeros

  Return value:
    A pointer to a sparse_triplet_t, or NULL if an error occured
  */
  sparse_triplet_t * malloc_sparse_triplet(unsigned long m, unsigned long n, unsigned long nnz) {

  	/* Allocate sparse_triplet structure */
  	sparse_triplet_t * pst = malloc(sizeof(*pst));
  	if ( pst == NULL ) {
  		MEM_ERR;
  		return NULL;
  	}

  	/* Set dimensions and allocate storage */
  	pst->m = m;
  	pst->n = n;
  	pst->nnz = nnz;
  	pst->I = calloc(nnz,sizeof(*pst->I));
  	pst->J = calloc(nnz,sizeof(*pst->J));
  	pst->V = calloc(nnz,sizeof(*pst->V));

  	/* Check for errors and return */
  	if ( pst->I == NULL || pst->J == NULL || pst->V == NULL ) {
  		MEM_ERR;
  		free_sparse_triplet(pst);
  		return NULL;
  	}
  	return pst;
  }

  /* free_sparse_triplet
  Purpose:
    Deallocates a sparse matrix in triplet form

  Arguments:
    pst        pointer to sparse_triplet_t

  Return value:
    None
  */
  void free_sparse_triplet(struct sparse_triplet * pst) {
  	if ( pst == NULL ) return;
  	free(pst->I);
  	free(pst->J);
  	free(pst->V);
  	free(pst);
  	return;
  }

  /************************************/
  /* File input/output routines       */
  /************************************/

  /* read_vector
  Purpose:
    Reads a vector from a text file

  Arguments:
    filename   string with filename

  Return value:
    A pointer to a vector_t, or NULL if an error occured.
  */
  vector_t * read_vector(const char * filename) {

  	double v, *buf=NULL, *tmp=NULL;
  	size_t n=0, buf_size=0;
  	vector_t *pv=NULL;
  	FILE *fp;

  	/* Open file and read dimensions */
  	fp = fopen(filename, "r");
  	if ( fp == NULL ) {
  		FILE_ERR(filename);
  		return NULL;
  	}

  	/* Read vector from file */
  	while (fscanf(fp, "%lf", &v) == 1) {
  		if ( n == buf_size ) {
  			buf_size = (buf_size==0 ? 256 : 2*buf_size);
  			tmp = realloc(buf, buf_size*sizeof(*buf));
  			if ( tmp == NULL ) {
  				MEM_ERR;
  				free(buf);
  				fclose(fp);
  				return NULL;
  			}
  			buf = tmp;
  		}
  		buf[n++] = v;
  	}
  	fclose(fp);
  	if ( n == 0 ) return NULL;

  	/* Allocate vector and copy data from buffer */
  	pv = malloc_vector(n);
  	if ( pv == NULL ) {
  		free(buf);
  		return NULL;
  	}
  	memcpy(pv->v, buf, sizeof(*buf)*n);
  	free(buf);
  	return pv;
  }

  /* write_vector
  Purpose:
    Writes a vector to a text file

  Arguments:
    filename   string with filename
  	pv         pointer to vector_t

  Return value:
    MATRIX_IO_SUCCESS if successful, and MATRIX_IO_FILE_ERROR
  	if a file error occured
  */
  int write_vector(const char * filename, const vector_t * pv) {

  	unsigned long i;
  	FILE *fp;

  	/* Check that pv is not NULL */
  	if ( pv == NULL ) {
  		INPUT_ERR;
  		return MATRIX_IO_ILLEGAL_INPUT;
  	}

  	/* Open file for writing */
  	fp = fopen(filename,"w");
  	if ( fp == NULL ) {
  		FILE_ERR(filename);
  		return MATRIX_IO_FILE_ERROR;
  	}

  	/* Write vector to file */
  	for (i=0;i<pv->n;i++)
  		fprintf(fp,"%.17g\n",pv->v[i]);
  	fclose(fp);

  	return MATRIX_IO_SUCCESS;
  }

  /* read_matrix
  Purpose:
    Reads a matrix from a text file

  Arguments:
    filename   string with filename

  Return value:
    A pointer to a matrix_t, or NULL if an error occured
  */
  matrix_t * read_matrix(const char * filename) {

  	matrix_t *pm=NULL;
  	char *buf = NULL, *line, *tok, delim[] = " \n";
  	double *data=NULL, *tmp;
  	size_t sz=0, colcnt=0, sz_buf=0, nrows=0, ncols=0, sz_data=0;

  	/* Open file and find size */
  	FILE *fp = fopen(filename,"r");
  	if ( fp == NULL ) {
  		FILE_ERR(filename);
  		return NULL;
  	}
  	fseek(fp, 0L, SEEK_END);
  	sz_buf = ftell(fp);
  	fseek(fp, 0L, SEEK_SET);

  	/* Allocate char buffer */
  	buf = malloc(sz_buf);
  	if (buf == NULL) {
  		MEM_ERR;
  		fclose(fp);
  		return NULL;
  	}

  	/* Parse file */
  	while ((line = fgets(buf, sz_buf, fp))) {
  	  tok = strtok(line,delim);
  	  colcnt = 0;
  	  while (tok) {
  	    colcnt += 1;
  	    if (sz == sz_data) {
  	      /* Data array is too small; request more memory */
  				sz_data = (sz_data==0 ? 256 : 2*sz_data);
  	      tmp = realloc(data, sz_data*sizeof(double));
  	      if (tmp == NULL) {
  					MEM_ERR;
  					free(data);
  					free(buf);
  					fclose(fp);
  					return NULL;
  				}
  	      data = tmp;
  	    }
  	    data[sz++] = atof(tok);
  	    tok = strtok(NULL,delim);
  	  }
  	  nrows += 1;
  	  if (ncols == 0)
  	  	ncols = colcnt;
  	  else if (ncols != colcnt && colcnt > 0) {
  	    fprintf(stderr,"%s: different column counts encountered.\n",__func__);
  	    free(data); free(buf); fclose(fp);
  	    return NULL;
  	  }
  	}
    /* Free char buffer and close file */
    free(buf);
    fclose(fp);

  	/* Allocate matrix and copy data */
  	pm = malloc_matrix(nrows,ncols);
  	if ( pm == NULL ) {
  		free(data);
  		return NULL;
  	}
  	memcpy(pm->A[0], data, nrows*ncols*sizeof(*pm->A[0]));
  	free(data);
  	return pm;
  }

  /* write_matrix
  Purpose:
    Writes a matrix to a text file

  Arguments:
    filename   string with filename
  	pm         pointer to matrix_t

  Return value:
    MATRIX_IO_SUCCESS if successful, and MATRIX_IO_FILE_ERROR
  	if a file error occured
  */
  int write_matrix(const char * filename, const matrix_t * pm) {
  	size_t i,j;
    FILE *fp;
  	if ( pm == NULL ) {
  		INPUT_ERR;
  		return MATRIX_IO_ILLEGAL_INPUT;
  	}
  	fp = fopen(filename,"w");
    if ( fp == NULL ) {
  		FILE_ERR(filename);
  		return MATRIX_IO_FILE_ERROR;
  	}
    for (i=0;i<pm->m;i++) {
      for(j=0;j<pm->n;j++) {
        fprintf(fp,"%.17g ",pm->A[i][j]);
      }
      fprintf(fp,"\n");
    }
    fclose(fp);
    return MATRIX_IO_SUCCESS;
  }

  /* read_sparse_triplet
  Purpose:
    Reads a sparse matrix in triplet form from a text file

  Arguments:
    filename   string with filename

  Return value:
    A pointer to a sparse_triplet_t, or NULL if an error occured
  */
  sparse_triplet_t * read_sparse_triplet(const char * filename) {

  	FILE *fp;
  	unsigned long i,m,n,nnz;
  	struct sparse_triplet * pst;

  	/* Open file and read dimensions */
  	fp = fopen(filename, "r");
  	if ( fp == NULL ) {
  		FILE_ERR(filename);
  		return NULL;
  	}
  	if (fscanf(fp,"%lu %lu %lu",&m,&n,&nnz) != 3) {
  		fprintf(stderr, "%s: could not read matrix dimensions\n",__func__);
  		fclose(fp);
  		return NULL;
  	}

  	/* Allocate sparse_triplet structure */
  	pst = malloc_sparse_triplet(m,n,nnz);
  	if ( pst == NULL ) {
  		fclose(fp);
  		return NULL;
  	}

  	/* Read triplets and subtract 1 from indices */
  	for (i=0;i<nnz;i++) {
  		if (3 == fscanf(fp,"%lu %lu %lf",pst->I+i,pst->J+i,pst->V+i)) {
  			pst->I[i]--;
  			pst->J[i]--;
  		}
  		else {
  			fprintf(stderr, "%s: could not read triplet\n",__func__);
  			fclose(fp);
  			free_sparse_triplet(pst);
  			return NULL;
  		}
  	}

  	/* Close file and return pointer to sparse_triplet_t */
  	fclose(fp);
  	return pst;
  }

  /* write_sparse_triplet
  Purpose:
    Writes a sparse matrix in triplet form to a text file

  Arguments:
    filename   string with filename
  	pst        pointer to sparse_triplet_t

  Return value:
    MATRIX_IO_SUCCESS if successful, and MATRIX_IO_FILE_ERROR
  	if a file error occured
  */
  int write_sparse_triplet(const char * filename, const sparse_triplet_t * pst) {

  	unsigned long i;
  	FILE *fp;

  	/* Check that pst is not NULL */
  	if ( pst == NULL ) {
  		INPUT_ERR;
  		return MATRIX_IO_ILLEGAL_INPUT;
  	}

  	/* Open file for writing */
  	fp = fopen(filename,"w");
  	if ( fp == NULL ) {
  		FILE_ERR(filename);
  		return MATRIX_IO_FILE_ERROR;
  	}

  	/* Write sparse_triplet structure to file */
  	fprintf(fp,"%lu %lu %lu\n",pst->m,pst->n,pst->nnz);
  	for (i=0;i<pst->nnz;i++)
  		fprintf(fp,"%lu %lu %.17g\n",pst->I[i]+1,pst->J[i]+1,pst->V[i]);
  	fclose(fp);

  	return MATRIX_IO_SUCCESS;
  }

  /************************************/
  /* Printing routines                */
  /************************************/

  /* print_vector
  Purpose:
    Prints a vector

  Arguments:
  	pv         a pointer to a vector_t

  Return value:
    None
  */
  void print_vector(vector_t * pv) {
  	size_t i;
  	if ( pv == NULL ) return;
  	printf("<vector_t n=%lu>\n",pv->n);
  	for (i=0;i<pv->n;i++) {
  		printf("% 8.3e\n",pv->v[i]);
  	}
  	return;
  }

  /* print_matrix
  Purpose:
    Prints a matrix

  Arguments:
  	pm         a pointer to a matrix_t

  Return value:
    None
  */
  void print_matrix(matrix_t * pm) {
  	size_t i,j;
  	if ( pm == NULL ) return;
  	printf("<matrix_t m=%lu n=%lu>\n",pm->m,pm->n);
  	for (i=0;i<pm->m;i++) {
  		printf("[");
  		for (j=0;j<pm->n;j++) {
  			printf("% 8.3e ",pm->A[i][j]);
  		}
  		printf("]\n");
  	}
  	return;
  }

  /* print_sparse_triplet
  Purpose:
    Prints a sparse matrix in triplet form

  Arguments:
  	pst        a pointer to a sparse_triplet_t

  Return value:
    None
  */
  void print_sparse_triplet(sparse_triplet_t * pst) {
  	size_t i;
  	if ( pst == NULL ) return;
  	printf("<sparse_triplet_t m=%lu n=%lu nnz=%lu>\n",pst->m,pst->n,pst->nnz);
  	for (i=0;i<pst->nnz;i++) {
  		printf("%-4lu %-4lu % 8.3e\n",pst->I[i]+1,pst->J[i]+1,pst->V[i]);
  	}
  }
