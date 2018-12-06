#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_dgemv_v1.h"
#include "my_dgemv_v2.h"
#include "array_2d.h"

#define NREPEAT 200
#define mytimer clock
#define delta_t(a,b) (1.0e3 * ((b) - (a)) / CLOCKS_PER_SEC)

  int main(int argc, char *argv[]) {

    int i, m, n, N = NREPEAT;
    double *x, *y, **A, tcpu1, tcpu2;
    clock_t t1, t2;

    printf("%4s %8s %8s\n", "n", "v1", "v2");
    for (m = 100; m <= 1000; m += 100) {
      n = m;

    /* Allocate memory */
    A = malloc_2d(m, n);
    x = malloc(n*sizeof(*x));
    y = malloc(m*sizeof(*y));
    if (A == NULL || x == NULL || y == NULL) {
    fprintf(stderr, "Memory allocation error..\n");
    free_2d(A); free(x); free(y);
    exit(EXIT_FAILURE);
    }


    /* CPU time for my_dgemv_v1 */
    t1 = mytimer();
    for (i = 0; i < N; i++)
      my_dgemv_v1(m, n, 1.0, A, x, 0.0, y);
    t2 = mytimer();
    tcpu1 = delta_t(t1,t2)/N;


    /* CPU time for my_dgemv_v2 */
    t1 = mytimer();
    for (i = 0; i < N; i++)
      my_dgemv_v2(m, n, 1.0, A, x, 0.0, y);
    t2 = mytimer();
    tcpu2 = delta_t(t1,t2)/N;

    /* Print n and results */
    printf("%4d %8.3e %8.3e\n", n, tcpu1, tcpu2);

    /* Free memory */
    free_2d(A);
    free(x);
    free(y);
  }

  return EXIT_SUCCESS;
}
