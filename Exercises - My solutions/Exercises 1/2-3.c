#include <stdio.h>

int main(void){
  float price_t1 = 3.50f;
  float price_t2 = 5.50f;
  int t1 = 0;
  int t2 = 0;
  float TotalPrice = 0.0f;

  printf("Please enter quantity of type 1\n");
  scanf("%d", &t1);

  printf("Please enter quantity of type 2\n");
  scanf("%d", &t2);

  TotalPrice = (float)t1*price_t1+t2*price_t2;
  printf("Total price is:$%.2f\n", TotalPrice);

  return 0;
}
