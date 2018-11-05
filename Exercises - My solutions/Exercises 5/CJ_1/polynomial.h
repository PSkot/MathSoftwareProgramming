#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
#include <stdlib.h>
#include <stdio.h>

/* Data structure that represents a polynomial of degree n */
typedef struct {
    unsigned int n;
    double *coef;
} poly_t;

/* Allocation and deallocation routines */
poly_t * poly_new(unsigned int n);
void poly_del(poly_t * p);

/* Display polynomial as a string */
void poly_print(poly_t * p);

#endif
