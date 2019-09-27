#include <stdio.h>
#include "mysort_lib.h"

/**
Сравнивает два числа.

@param p [in]
@param q [in]
@param *a-*b [out]

@return возвращает разницу между числами.
*/
int compare_double(const void* p, const void* q)
{
    const double *a = p;
    const double *b = q;
    return (int)(*a - *b); // return *(int*)p - *(int*)q;
}

/**
Сравнивает два числа.

@param p [in]
@param q [in]
@param *a-*b [out]

@return возвращает разницу между числами.
*/
int compare_char(const void* p, const void* q)
{
    const char *a = p;
    const char *b = q;
    return (int)(*a - *b); // return *(int*)p - *(int*)q;
}

/**
Сравнивает два числа.

@param p [in]
@param q [in]
@param *a-*b [out]

@return возвращает разницу между числами.
*/
int compare_long(const void* p, const void* q)
{
    const long *a = p;
    const long *b = q;
    return (int)(*a - *b); // return *(int*)p - *(int*)q;
}

/**
Проверяет массивы на соответствие.
 
@param pa [in]
@param pb [in]
@param pa1 [in]
@param pb1 [in]
@param size [in]
@param compar [in]
@param flag [out]
 
@return возвращает 1 если программа работает неверно, 0 если верно.
*/
int test_sort(void *pa, void *pb, void *pa1, void *pb1, size_t size,
              int (*compar)(const void *, const void*))
{
    int flag = 0;
    for (; pa1 < pb1; pa += size, pa1 += size) {
        if (compar(pa1, pa) != 0) {
            printf("Mistake!\n");
            flag = 1;
        }
    }
    return flag;
}

/**
Заполняет массивы.
 
@param flag [out]
 
@return возвращает 1 если программа работает неверно, 0 если верно.
*/
int mysorttest(void)
{
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;
    int arr1[7] = {1, 45, 234, 3, -34, 0, -100};
    int *pa1 = arr1, *pb1 = pa1 + 7;
    double arr2[5] = {-100.57, 200.56, -300.4564, 400.4564, -500.456};
    double *pa2 = arr2, *pb2 = pa2 + 5;
    char arr3[6] = {'a', 'z', 'f', 'd', 'o', 'e'};
    char *pa3 = arr3, *pb3 = arr3 + 6;
    long int arr4[8] = {1067, 967, 867, 7555, 64, 55, 4, 3};
    long int *pa4 = arr4, *pb4 = pa4 + 8;

    int arr11[7] = {-100, -34, 0, 1, 3, 45, 234};
    int *pa11 = arr11, *pb11 = arr11 + 7;
    double arr22[5] = {-500.456, -300.4564, -100.57, 200.56, 400.4564};
    double *pa22 = arr22, *pb22 = arr22 + 5;
    char arr33[6] = {'a', 'd', 'e', 'f', 'o', 'z'};
    char *pa33 = arr33, *pb33 = arr33 + 6;
    long int arr44[8] = {3, 4, 55, 64, 867, 967, 1067, 7555};
    long int *pa44 = arr44, *pb44 = arr44 + 8;

    mysort(pa1, pb1, sizeof(int), compare_int);
    mysort(pa2, pb2, sizeof(double), compare_double);
    mysort(pa3, pb3, sizeof(char), compare_char);
    mysort(pa4, pb4, sizeof(long int), compare_long);

    flag1 = test_sort(pa1, pb1, pa11, pb11, sizeof(int), compare_int);
    flag2 = test_sort(pa2, pb2, pa22, pb22, sizeof(double), compare_double);
    flag3 = test_sort(pa3, pb3, pa33, pb33, sizeof(char), compare_char);
    flag4 = test_sort(pa4, pb4, pa44, pb44, sizeof(long int), compare_long);

    return flag1 || flag2 || flag3 || flag4;
}