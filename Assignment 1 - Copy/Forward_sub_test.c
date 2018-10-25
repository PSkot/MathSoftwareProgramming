#include <math.h>
#include <stdint.h>
#include <stdlib.h>

int main(void){
  unsigned long n = 5;
  double alpha;
  double **R;
  double *b;

    //Check positive dimensions and check for overflow
    if (n <= 0 || n*n > SIZE_MAX)
      return NULL;

    //Allocate memory to R and b
    R = (double**)malloc(n * sizeof(R));
    R[0] = (double*)malloc(n*n*sizeof(double));
    if (R[0] == NULL) {
      free(R);
      return NULL;
    }
    for (size_t i = 1; i < n; i++)
      R[i] = R[0] + i * n;

    b = (double*)malloc(n*sizeof(double));


    //Calculate first solution element x (overwriting b)
    b[0] /= alpha + R[0][0];

    //Calculate the remaining x's

    for(size_t k = 1; k < n; ++k){
      double sum = 0.0;
      for(size_t i = 0; i <= k - 1; ++i){
        if(i > k)
          R[k][i] = 0;
        sum += b[i]*R[i][k];
      }
      b[k] = (b[k] - sum)/(alpha + R[k][k]);
    }

    //Check for numerical failure, return -1 if failure
      for(size_t i = 0; i < n; ++i)
      {
        if(fabs(b[i]) == INFINITY || fabs(b[i]) == NAN)
          return -1;
      }

    //Success
    return 0;
}
