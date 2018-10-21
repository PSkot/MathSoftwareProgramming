#include <math.h>

double softplus(double x) {
  if (x > 0)
    return x + log1p(exp(-x));
  else
    return log1p(exp(x));
}
