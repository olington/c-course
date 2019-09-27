#ifndef output_h
#define output_h

#include <stdio.h>

int notZeroElements(double **mat, int n, int m);
void printMatrix(double **mat, int n, int m);
void printMatrixInFile(FILE *f, double **mat, int n, int m);

#endif /* output_h */
