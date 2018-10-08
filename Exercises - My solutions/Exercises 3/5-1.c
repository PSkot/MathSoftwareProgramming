#include <stdio.h>

int main(void){
  double x[5], y[5], sum;
  int i = 0;

  printf("Please enter grades:\n");

  for(i = 0; i < 5; ++i){
    printf("%d>", i + 1);
    scanf("%lf", &x[i]);
    y[i] = 1.0/x[i];
  }

  for(i = 0; i < 5; ++i){
    printf("Reciprocal %d>%.2lf\n", i+1, y[i]);
    sum += y[i];
  }

  printf("Sum of reciprocals: %.4lf\n", sum);

  return 0;

}
