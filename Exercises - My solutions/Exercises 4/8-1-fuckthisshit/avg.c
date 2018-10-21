/* avg.c */
#include "avg.h"
double avg(double * x, size_t n) {
double sum = 0.0;
if(x==NULL) return NAN;
for (size_t i = 0; i < n; i++) {
  sum += x[i];
}
return sum/n;
}
