#ifndef input_h
#define input_h

#include <stdio.h>

void zeroMatrix(double **mat, int n, int m);
double **inputMatrixFromFile(FILE *f, int *n, int *m);

#endif /* input_h */
