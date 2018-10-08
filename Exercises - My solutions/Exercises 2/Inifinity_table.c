#include <stdio.h>
#include <math.h>
#define xstr(s) str(s)
#define str(s) #s
#ifndef op
#define op *
#endif

int main(void){
  int i, j;
  double arr[7] = {-INFINITY, -1.0, -0.0, 0.0, 1.0, INFINITY, NAN};

  printf("op: %2s | ", xstr(op));

  for (i = 0; i < 7; ++i)
  printf("%6.1f", arr[i]);
  putchar('\n');

  for (i=0;i<57;i++)
  putchar('-');
  putchar('\n');

  for (i = 0; i < 7; ++i) {
    printf("%6.1f | ", arr[i]);
    for(j = 0; j < 7; ++j){
      printf("%6.0f", (double) arr[i] op arr[j]);
    }
      putchar('\n');
  }

}
