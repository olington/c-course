#include "func_lib.h"

/**
Создает массив длины n, состоящий из чисел Фибоначчи.

@param array [in, out]
@param n [in]

@return указатель на массив длины n из чисел Фибоначчи
*/
FUNC_DLL int* FUNC_DECL fib_arr(int *array, int n)
{
    array[0] = 1;
    array[1] = 1;
    for (int i = 2; i < n; i++)
        array[i] = array[i - 2] + array[i - 1];
    return array;
}

/**
Из одного массива помещает во второй массив первое вхождение каждого элемента первого массива

@param array [in]
@param n [in]
@param new_array [in]
@param len [out]

@return если программа выполнена успешно - количество элементов в итоговом массиве, иначе - 0.
*/
FUNC_DLL int FUNC_DECL del_reps(const int *array, int n, int *new_array)
{
    int flag = 0;
    int len = n;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (array[i] == new_array[j] && i != j)
            {
                len--;
                flag = 1;
            }
        }

        if (flag != 1)
        {
            new_array[count] = array[i];
            count++;
        }
    }

    if (len < 0)
        len = 0;

    return len;

}