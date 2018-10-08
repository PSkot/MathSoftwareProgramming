#include <stdio.h>

int main(void){

  double data[100];
  double sum = 0;
  int i;
  int j = 2;

  for(i = 0; i < 100; ++i){
    data[i] = 1.0/((i+j)*(i+j+1)*(i+j+2));
    j += 1;
  }

  for(i = 0; i < 100; ++i){
    if((i+2) % 2 == 0)
      sum += data[i];
    else
      sum -= data[i];
  }

    printf("%.10lf\n", 4.0*sum+3.0);

}
