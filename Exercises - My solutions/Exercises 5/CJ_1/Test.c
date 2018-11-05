#include <stdio.h>


int main(void) {

  if(p == NULL)
    return NAN;

  double v = 0.0;

  for(size_t i = n; i >= 0; --i){
    v = (double)p->coef[i] + v*x;
  }

  return v;

}
