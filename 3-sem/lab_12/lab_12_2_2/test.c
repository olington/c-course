#include <stdio.h>
#include <stdlib.h>
#include "func_lib.h"
#include "test.h"

/**
 Сравнивает массив с файлом.

 @param f [in]
 @param arr [in]
 @param num_test [in]

 @return 1, если тест пройден, 0 - иначе.
 */
int compareArr(int *arr, FILE *f, int num_test)
{
    rewind(f);
    int flag = 1, x = 0, i = 0;

    while (!feof(f))
    {
        fscanf(f, "%d", &x);
        if (arr[i] != x)
        {
            printf("Test %d: %d %d\n", num_test, x, arr[i]);
            flag = 0;
        }
        i++;
    }

    return flag;
}

int main()
{
    FILE *f1 = fopen("out1.txt", "r");
    FILE *f2 = fopen("out2.txt", "r");
    FILE *f3 = fopen("out3.txt", "r");
    FILE *f4 = fopen("out4.txt", "r");

    int *arr = malloc(10 * sizeof(int));
    int arr_1[8] = {5, 6, 5, 7, 8, 7, 5, 6}, arr_2[8] = {1, 1, 2, 1, 2, 3, 1, 5};
    int *arr_3 = malloc(10 * sizeof(int)), *arr_4 = malloc(10 * sizeof(int));
    int n1 = 8, n2 = 6, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0;

    fib_arr(arr, n1);
    flag1 = compareArr(arr, f1, 1);

    fib_arr(arr, n2);
    flag2 = compareArr(arr, f2, 2);

    n1 = del_reps(arr_1, 8, arr_3);
    flag3 = compareArr(arr_3, f3, 3);

    n1 = del_reps(arr_2, 8, arr_4);
    flag4 = compareArr(arr_4, f4, 4);

    if (flag1 && flag2 && flag3 && flag4)
        printf("Tests are passed\n");

    else
        printf("Tests are not passed\n");

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    free(arr);
    free(arr_3);
    free(arr_4);
}