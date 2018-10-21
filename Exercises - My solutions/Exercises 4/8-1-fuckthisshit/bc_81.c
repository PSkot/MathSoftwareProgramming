/* bc_81.c */
#include <stdlib.h>
#include <stdio.h>
#include "read_input.h"
#include "avg.h"

int main(int argc, char const *argv[]) {
  double * x;
  size_t n;
  read_input(&x,&n); // This function handles memory allocation!
  if ((x==NULL)||(n==0)) return EXIT_FAILURE;
  printf("The average of the %lu numbers is: %.3f\n",n,avg(x,n));
  free(x);
  return 0;
}
