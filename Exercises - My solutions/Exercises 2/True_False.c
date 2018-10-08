#include <stdio.h>

int main(void){
  double a = 1.0, b = 1e-16, c = -1.0;
  printf("a*(b*c) = %.4e\n", a*(b*c));
  printf("(a*b)*c = %.4e\n", (a*b)*c);
  printf("a*(b+c) = %.4e\n", a*(b+c));
  printf("a*b + a*c = %.4e\n", a*b + a*c);
  printf("(a + b) + c = %.4e\n",(a+b)+c);
  printf("a + (b + c) = %.4e\n",a+(b+c));
  return 0;
}
