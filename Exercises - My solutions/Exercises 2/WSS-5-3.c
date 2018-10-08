#include <stdio.h>
#include <math.h>

int main(void){

  float x, y, yt, xt, tmp = 0.0;

  printf("Please declare values of x and y, respectively:\n");
  scanf("%f %f", &x, &y);

  yt = fabs(y);
  xt = fabs(x);

  //Swap x and y if x is smaller
  if(yt > xt){
    tmp = yt;
    yt = xt;
    xt = tmp;
  }

  printf("%f\n", fabs(xt)*sqrt(1.0 + (yt/xt)*(yt/xt)));

}
