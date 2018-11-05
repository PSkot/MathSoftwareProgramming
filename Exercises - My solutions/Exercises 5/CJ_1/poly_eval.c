#include "polynomial.h"
#include <math.h>

double poly_eval(poly_t *p, double x) {

  if(p == NULL)
    return NAN;

  double v = 0.0;

  for(int i = p->n; i >= 0; --i){
    v = p->coef[i] + v*x;
  }

  return v;

}
