#include <stdio.h>

/**
Проверяет массивы на соответствие.

@param resa [in]
@param resb [in]
@param arr [in]
@param count [in]
@param flag [out]

@return 0 - если массивы одинаковы, 1 - иначе.
*/
int check(int *resa, int *resb, int *arr, int count)
{
    int i, flag = 0;

    for (i = 0; resa < resb; resa++, i++)
    {
        if (*resa != arr[i])
            flag = 1;
    }

    if (count != i)
        flag = 1;

    return flag;
}

/**
Формирует массивы, фильтрует и сортирует их.

@return результат сравнения массивов.
*/
void testKey(void)
{
    int arr1[7] = {2, 13, 7, 3, -5, 10, 0}, arr2[5] = {-1, -2, -3},
            arr3[6] = {1, -1, 2, -2, 3, -3, 4, -4, 5, -5, 6, -6, 7, -7, 8, -8, 9, -9},
            arr4[8] = {-6, 7, 0, 45, -23, 5, 1, 6, 5, 5, 2, 5, -1, -5, 8};
    int arr11[4] = {7, 10, 13}, arr22[2] = {-1}, arr33[3] = {1, 2, 3, 4, 5, 6, 7, 8, 9},
            arr44[8] = {5, 5, 5, 5, 6, 7, 8, 45};

    int *pa1 = arr1, *pb1 = pa1 + 7, *pa2 = arr2, *pb2 = pa2 + 3,
            *pa3 = arr3, *pb3 = arr3 + 16, *pa4 = arr4, *pb4 = pa4 + 15,
            *resa1 = pa1, *resb1 = pb1, *resa2 = pa2, *resb2 = pb2,
            *resa3 = pa3, *resb3 = pb3, *resa4 = pa4, *resb4 = pb4;

    int count[4] = {3, 1, 9, 8}, flag1 = 0, flag2, flag3, flag4;

    key(pa1, pb1, &resa1, &resb1);
    key(pa2, pb2, &resa2, &resb2);
    key(pa3, pb3, &resa3, &resb3);
    key(pa4, pb4, &resa4, &resb4);

    mysort(pa1, pb1, sizeof(int), compare_int);
    mysort(pa2, pb2, sizeof(int), compare_int);
    mysort(pa3, pb3, sizeof(int), compare_int);
    mysort(pa4, pb4, sizeof(int), compare_int);

    flag1 = check(resa1, resb1, arr11, count[0]);
    if (flag1 == 0)
        printf("PASSED");
    else
        printf("NOT PASSED");

    flag2 = check(resa2, resb2, arr22, count[1]);
    if (flag2 == 0)
        printf("PASSED");
    else
        printf("NOT PASSED");

    flag3 = check(resa3, resb3, arr33, count[2]);
    if (flag3 == 0)
        printf("PASSED");
    else
        printf("NOT PASSED");

    flag4 = check(resa4, resb4, arr44, count[3]);
    if (flag4 == 0)
        printf("PASSED");
    else
        printf("NOT PASSED");
}

int main(void)
{
    testKey();
    return 0;
}