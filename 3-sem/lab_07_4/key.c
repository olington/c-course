#include "key.h"

float average(const int *pa, const int *pb)
{
    float sum, av;
    int size = pb - pa;
    
    for (; pa < pb; pa++)
        sum += *pa;
    
    av = sum / size;
    return av;
}

int newArraySize(const int *pa, const int *pb, int average)
{
    int new_size = 0;
    for (; pa < pb; pa++)
        if (*pa > average)
            new_size++;
    return new_size;
}

void newArray(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, float average)
{
    int *cur = *pb_dst;
    
    for (; pb_src < pe_src; pb_src++)
    {
        if (*pb_src > average)
        {
            *cur = *pb_src;
            cur++;
        }
    }
    *pe_dst = cur;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int error = 0;
    int k = 0;
    
    int src_size = pe_src - pb_src;
    float av;
    int dst_size = 0;
    *pb_dst = NULL;
    
    if (!src_size)
        k = -1;
    
    if (!k)
    {
        av = average(pb_src, pe_src);
        dst_size = newArraySize(pb_src, pe_src, av);
        
        if (!dst_size)
            k = -2;
        
        if (!k)
        {
            *pb_dst = (int*) malloc(dst_size * sizeof(int));
            if (*pb_dst)
                newArray(pb_src, pe_src, pb_dst, pe_dst, av);
            else
                k = -3;
        }
    }
    return k;
}


