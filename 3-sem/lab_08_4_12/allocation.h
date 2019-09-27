#ifndef allocation_h
#define allocation_h

#include <stdio.h>
#include <stdlib.h>

double** allocateMatrix(int n, int m);
void freeMatrix(double **data, int n);

#endif /* allocation_h */
