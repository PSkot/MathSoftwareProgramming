#include "avgarray.h"

double avgarray(double *x, size_t size){

  double sum = 0.0;

  for(size_t i = 0; i < size; i++)
    sum += x[i];

  return sum/size;

}
