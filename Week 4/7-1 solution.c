#include <stdio.h>
#include <stdlib.h>
int main(void) {
int n = 0, N = 4;
double *data = NULL, *tmp = NULL, val = 0.0, avg = 0.0;
// Allocate storage for N doubles
data = (double *)malloc(N*sizeof(*data));
if (!data) {
fprintf(stderr,"Memory allocation failed\n");
return EXIT_FAILURE;
}
// Prompt user to enter data
printf("Please enter your data:\n>");
while (scanf("%lf", &val) == 1) {
if (n == N) {
// Request space for 4 additional doubles
N = N + 4;
tmp = (double *)realloc(data, N*sizeof(*data));
if (!tmp) {
// Reallocation failed
fprintf(stderr,"Memory reallocation failed\n");
free(data);
return EXIT_FAILURE;
}
data = tmp;
}
data[n++] = val;
printf(">");
}
// Compute and print average
printf("You entered %d values.\n", n);
for (size_t i = 0; i < n; i++) {
avg += data[i];
}
avg /= n;

printf("Average value: %g\n", avg);
// Free allocated memory and exit
free(data);
return EXIT_SUCCESS;
}
