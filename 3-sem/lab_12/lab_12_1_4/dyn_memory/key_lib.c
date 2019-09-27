#include <malloc.h>
#include <stdio.h>
#include "main_func.h"
#include "key_lib.h"

/**
 Находит среднее значение массива, где pa - указатель на первый элементт, pb - указатель на элемент за последним.

 @param pa [in]
 @param pb [in]

 @return av - среднее арифметическое.
 */
KEY_DLL float KEY_DECL average(const int *pa, const int *pb)
{
    float sum, av;
    int size = pb - pa;

    for (; pa < pb; pa++)
        sum += *pa;

    av = sum / size;
    return av;
}

/**
 Находит число элементов массива (pa - указатель на первый элементт, pb - указатель на элемент за последним), которые больше среднего (average).

 @param pa [in]
 @param pb [in]
 @param average [in]

 @return длину нового массива, в который будут перезаписаны элементы, прошедшие фильтр.
 */
KEY_DLL int KEY_DECL newArraySize(const int *pa, const int *pb, int average)
{
    int new_size = 0;
    for (; pa < pb; pa++)
        if (*pa > average)
            new_size++;
    return new_size;
}

/**
 Копирует элементы массива src (pb_src - указатель на первый элементт, pe_src - указатель на элемент за последним) в массив dst (pb_dst - указатель на первый элементт, pe_dst - указатель на элемент за последним). Будут скопированы либо все элементы массива p_a, либо
     столько, сколько поместится в p_b (т.е. min(n_a, n_b)).

 @param pb_src, [in]
 @param pe_src [in]
 @param pb_dst [in, out]
 @param pr_dst [in, out]
 @param average [in]

 @return ничего не возвращает.
 */
KEY_DLL void KEY_DECL newArray(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst, float average)
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

/**
Переносит все числа массива до первого отрицательного в новый массив.

@param pb_src [in]
@param pe_src [in] 
@param pb_dst [in, out]
@param pe_dst [in, out]
@param flag [out]

@return если входные данные верны и программа работает корректно, то возвращает 0, иначе 1.
*/
KEY_DLL int KEY_DECL key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int k = 1;

    int src_size = pe_src - pb_src;
    float av;
    int dst_size = 0;
    *pb_dst = NULL;

    if (!src_size)
        k = -1;

    if (k == 1)
    {
        av = average(pb_src, pe_src);
        dst_size = newArraySize(pb_src, pe_src, av);

        if (!dst_size)
            k = -1;

        if (k == 1)
        {
            *pb_dst = (int*) malloc(dst_size * sizeof(int));
            if (*pb_dst)
                newArray(pb_src, pe_src, pb_dst, pe_dst, av);
            else
                k = -1;
        }
    }
    return k;
}