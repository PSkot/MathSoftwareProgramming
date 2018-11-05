#include "polynomial.h"
#include <math.h>

poly_t * poly_mul(const poly_t * p1, const poly_t * p2) {
    if (p1 == NULL || p2 == NULL)
      return NULL;

    poly_t * p = poly_new(p1->n+p2->n);

    for (int i = p1->n; i >= 0; --i){
      for (int j = p2->n; j >= 0; --j){
        p->coef[i+j] += p2->coef[j]*p1->coef[i];
      }
    }

  return p;

}
