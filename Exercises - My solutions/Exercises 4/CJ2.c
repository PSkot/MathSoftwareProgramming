#include <math.h>
double feval(double x) {
  double x_abs = fabs(x);
  if (x_abs > 2.0)
    return x_abs*sqrt(1+pow(x,-2))-1;
  else{
    double x_sq = x*x;
    return x_sq/(sqrt(x_sq+1)+1);
    }
}
