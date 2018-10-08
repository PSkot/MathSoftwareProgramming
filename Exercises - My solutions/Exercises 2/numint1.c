#include <stdio.h>
#include <math.h>
#include <fenv.h>

int main(void){

  float a, b = 0.0;
  int N, i, j, method = 0;

  printf("Please specify values of a, b and N, respectively:\n");
  scanf("%f %f %d", &a, &b, &N);

  printf("Please specify integration method (1 for rectangle, 2 for trapezoidal):\n");
  scanf("%d", &method);

  //Rectangle method
  if(method == 1){

    printf("\nN\tRectangle\n");

    for(i = 0; i <= N - 1; ++i){
      float h = (b-a)/(i+1);
      float sum = 0.0;
      printf("%d", i+1);

      for(j = 0; j <= i; ++j)
        sum += exp(-pow(a+0.5*h+j*h,2));

      printf("\t%.16e\n", h*sum);
    }
  }

  //Trapezoidal method
  else if(method == 2){

    float fa = exp(-(a*a));
    float fb = exp(-(b*b));

    printf("\nN\tTrapezoidal\n");

    for(i = 0; i <= N - 1; ++i){
      float h = (b-a)/(i+1);
      float sum = 0.0;
      printf("%d", i+1);

      for(j = 1; j <= i; ++j)
        sum += exp(-pow(a+j*h,2));

      printf("\t%.16e\n", h*(fa/2+sum+fb/2));
  }
}

//Terminate if incorrect pick
  else{
    printf("1 or 2 not selected, terminating program\n");
    return -1;
  }

  return 0;
}
