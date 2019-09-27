#ifndef key_h
#define key_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

float average(const int *pa, const int *pb);
int newArraySize(const int *pa, const int *pb, int average);
void newArray(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, float average);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif /* key_h */
