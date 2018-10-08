#include <stdio.h>
#include <math.h>

int main(void){
  float xpt, xp, xm, b, a, c = 0.0;

  printf("Declare a, b and c, respectively:\n");
  scanf("%f %f %f", &a, &b, &c);

if(b*b - 4*a*c < 0)
  printf("There are no real roots\n");

else if (b*b - 4*a*c == 0)
  printf("The solution to x is %.2f\n", (-b - sqrt(b*b - 4*a*c))/(2*a));

else{

  xm = (-b - sqrt(b*b - 4*a*c))/(2*a);
  xp = (c/a)/xm;
  xpt = (-b + sqrt(b*b - 4*a*c))/(2*a);


  printf("The solutions to x are %.2f and %.2f, respectively \n", xm, xp);
  printf("This is a drill: %.2f\n", xpt);
  }
}
