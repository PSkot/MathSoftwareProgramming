#include <stdlib.h>
#include <stdio.h>

/* DGESV prototype */
extern void dgesv_( int* n, int* nrhs, double* a, int* lda, int* ipiv,
                double* b, int* ldb, int* info );
/* Auxiliary routines prototypes */
extern void print_matrix( char* desc, int m, int n, double* a, int lda );
extern void print_int_vector( char* desc, int n, int* a );

/* Parameters */
#define N 3
#define NRHS 1
#define LDA N
#define LDB N

/* Main program */
int main() {
        /* Locals */
        int n = N, nrhs = NRHS, lda = LDA, ldb = LDB, info;
        /* Local arrays */
        int ipiv[N];
        double a[LDA*N] = {
            42,1,79,68,70,59,35,25,63
        };
        double b[LDB*NRHS] = {
            65,6,46
        };
        /* Executable statements */
        printf( " DGESV Example Program Results\n" );
        /* Solve the equations A*X = B */
        dgesv_( &n, &nrhs, a, &lda, ipiv, b, &ldb, &info );
        /* Check for the exact singularity */
        if( info > 0 ) {
                printf( "The diagonal element of the triangular factor of A,\n" );
                printf( "U(%i,%i) is zero, so that A is singular;\n", info, info );
                printf( "the solution could not be computed.\n" );
                exit( 1 );
        }
        /* Print solution */
        print_matrix( "Solution", n, nrhs, b, ldb );
        /* Print details of LU factorization */
        print_matrix( "Details of LU factorization", n, n, a, lda );
        /* Print pivot indices */
        print_int_vector( "Pivot indices", n, ipiv );
        exit( 0 );
} /* End of DGESV Example */

/* Auxiliary routine: printing a matrix */
void print_matrix( char* desc, int m, int n, double* a, int lda ) {
        int i, j;
        printf( "\n %s\n", desc );
        for( i = 0; i < m; i++ ) {
                for( j = 0; j < n; j++ ) printf( " %6.2f", a[i+j*lda] );
                printf( "\n" );
        }
}

/* Auxiliary routine: printing a vector of integers */
void print_int_vector( char* desc, int n, int* a ) {
        int j;
        printf( "\n %s\n", desc );
        for( j = 0; j < n; j++ ) printf( " %6i", a[j] );
        printf( "\n" );
}
