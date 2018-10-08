#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <stdlib.h>


int main(void){

if (fesetround(FE_TOWARDZERO)) {
  fprintf(stderr, "Failed to set rounding mode\n");
  exit(EXIT_FAILURE);
}


  for (int k = 0; k <= 16; k++) {

    double x = pow(10, -k);
    printf("%e\t%d\tCos(x) = %e\t(1-Cos(x))/x^2 = %.16e\n",
    x, k, (double)cos(x), (double)(1-cos(x))/(x*x));


  }

}
