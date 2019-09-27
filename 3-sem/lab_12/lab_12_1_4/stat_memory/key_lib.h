#ifndef __KEY__H__
#define __KEY__H__

float average(const int *pa, const int *pb);
int newArraySize(const int *pa, const int *pb, int average);
void newArray(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, float average);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif