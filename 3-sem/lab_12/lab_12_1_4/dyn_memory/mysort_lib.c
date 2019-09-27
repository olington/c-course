#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysort_lib.h"

/**
Сравнивает два числа.

@param p [in]
@param q [in]
@param *a-*b [out]

@return возвращает разницу между числами.
*/
MYSORT_DLL int MYSORT_DECL compare_int(const void* p, const void* q)
{
    const int *a = p;
    const int *b = q;
    return *a - *b;
}

/**
Сортирует массив.

@param pa [in, out]
@param pb [in, out]
@param size [in]
@param compar [in]

@return отсортированный массив.
*/
MYSORT_DLL void MYSORT_DECL mysort (void* pa, void* pb, size_t size, int (*compar)(const void*, const void*))
{
    void *newElement, *member = malloc(size * sizeof(void*)), *location, *base = pa;
    pa += size;
    for (; pa < pb; pa += size)
    {
        newElement = pa;
        memcpy(member, newElement, size);
        location = pa - size;
        while (location >= base && compar(location, newElement) > 0)
        {
            memcpy(member, newElement, size);
            memcpy(newElement, location, size);
            memcpy(location, member, size);
            location -= size;
            newElement -= size;
        }
    }
    free(member);
}