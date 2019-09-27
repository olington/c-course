#include <stdio.h>
#include "key_lib.h"

/**
Проверяет массивы на соответствие.

@param resa [in]
@param resb [in]
@param arr [in]
@param count [in]
@param flag [out]

@return возвращает флаг правильного и неправильного выполнения программы.
*/
int check(int *resa, int *resb, int *arr, int count)
{
    int i, flag = 0;
    for (i = 0; resa < resb; resa++, i++)
    {
        if (*resa != arr[i])
        {
            flag = 1;
        }
    }
    if (count != i)
    {
        flag = 1;
    }
    return flag;
}

/**
Формирует массивы. 

@param flag [out]

@return возвращает 0 если функция работает верно, 1 если нет.
*/
int keytest(void)
{
    int arr1[7] = {1, 45, 234, 3, -34, 0, -100}, arr2[5] = {100, 200, -300, 400, -500},
            arr3[6] = {12, 5, 4, -3, 665, 43}, arr4[8] = {10, 9, 8, 7, 6, 5, 4, 3};
    int arr11[4] = {1, 45, 234, 3}, arr22[2] = {100, 200},
            arr33[3] = {12, 5, 4}, arr44[8] = {10, 9, 8, 7, 6, 5, 4, 3};

    int *pa1 = arr1, *pb1 = pa1 + 7, *pa2 = arr2, *pb2 = pa2 + 5,
            *pa3 = arr3, *pb3 = arr3 + 6, *pa4 = arr4, *pb4 = pa4 + 8,
                    *resa1 = pa1, *resb1 = pb1, *resa2 = pa2, *resb2 = pb2,
                            *resa3 = pa3, *resb3 = pb3, *resa4 = pa4, *resb4 = pb4;

    int count[4] = {4, 2, 3, 8}, flag1 = 0, flag2, flag3, flag4;

    key(pa1, pb1, &resa1, &resb1);
    key(pa2, pb2, &resa2, &resb2);
    key(pa3, pb3, &resa3, &resb3);
    key(pa4, pb4, &resa4, &resb4);
    flag1 = check(resa1, resb1, arr11, count[0]);
    flag2 = check(resa2, resb2, arr22, count[1]);
    flag3 = check(resa3, resb3, arr33, count[2]);
    flag4 = check(resa4, resb4, arr44, count[3]);
    
    int flag = flag1 || flag2 || flag3 || flag4;
    return flag;
}