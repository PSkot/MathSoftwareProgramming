#include <stdio.h>
#include <math.h>
#define N 6
#ifndef fp_t
#define fp_t float
#endif

int main(void){
  fp_t arr[N] = {34124.75, 34124.48, 34124.90, 34125.31, 34125.05, 34124.98};
  fp_t sum = 0.0;
  fp_t var_1 = 0.0;
  fp_t var_2 = 0.0;
  fp_t sum_sq = 0.0;
  fp_t mean = 0.0;

  int i;


  //One-pass variance

  for(i = 0; i < N; ++i){
    sum_sq += arr[i]*arr[i];
    sum += arr[i];

  }

  mean = sum/N;
  var_1 = (sum_sq - N * mean * mean)/(N-1);

  //Two-pass variance
  for(i = 0; i < N; ++i)
    var_2 += (arr[i] - mean)*(arr[i]-mean);

  var_2 /= N-1;

  printf("The one-pass variance is %20.16g\n", var_1);
  printf("The two-pass variance is %20.16g\n", var_2);

  return 0;

}
