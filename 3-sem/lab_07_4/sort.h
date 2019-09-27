#ifndef sort_h
#define sort_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

int compareInt(const void *val1, const void *val2);
void swap (int *pa,int *pb);
void mysort(void *mas, const size_t n, const size_t size, int (*compar)(const void *, const void *));
void testing(const int *a_st, const int *a_end, const int sort_t);

#endif /* sort_h */
