/* read_input.c */
#include "read_input.h"
void read_input(double ** x, size_t * length) {
size_t n=0, N=4;
double val, *data=NULL, *tmp=NULL;
*x = NULL;
*length = 0;
// Allocate storage for N doubles
data = (double *)malloc(N*sizeof(*data));
if (!data) {
  fprintf(stderr,"Memory allocation failed\n");
  return;
}
// Prompt user to enter data
printf("Please enter your data "
"(terminate with any non-numeric input):\n>");
while (scanf("%lf", &val) == 1) {
if (n == N) {
// Request space for 4 additional doubles
N = N + 4;
tmp = (double *)realloc(data, N*sizeof(*data));
if (!tmp) {
// Reallocation failed
fprintf(stderr,"Memory reallocation failed\n");
free(data);
return;
}
data = tmp;
}
data[n++] = val;
printf(">");
}
*length = n;
*x = data;
return;
}
