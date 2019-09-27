#ifndef input_h
#define input_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

void fileLength(int *array_length, FILE *file);
void readFfromFile(int *array, int *array_end, FILE *file);
int checkFile(int **array, int *array_length, FILE *file);
void printArray(const int *array, const int *array_end);

#endif /* input_h */
