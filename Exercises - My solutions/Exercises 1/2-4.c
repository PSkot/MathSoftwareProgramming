#include <stdio.h>
#include <math.h>

int main(void){

  float hours = 0.0f;
  float pay = 0.0f;
  float average_rate = 0.0f;

  printf("Please enter your weekly pay in dollars:\n");
  scanf("%f", &pay);

  printf("Please enter your hours worked\n");
  scanf("%f", &hours);

  average_rate = pay/hours;

  printf("Your average hourly pay rate is %d dollars and %.0f cents\n",
  (int)average_rate, (average_rate-floor(average_rate))*100);

  return 0;

}
