#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include "mysort_lib.h"
#include "main_func.h"
#include "key_lib.h"

/**
Определяет количество чисел в файле.

@param fin [in]
@param count [out]
 
@return возвращает количество чисел в файле, либо ошибку ввода -1.
*/
int arrayLen(FILE *fin)
{
    int elem = 0, count = 0, rc = 0;
    char tmp;
    while (1)
    {
        while ((rc = fscanf(fin, "%d%c", &elem, &tmp)) != 2 && rc != EOF)
        {
            if (feof(fin))
                break;

            if (rc != EOF)
            {
                printf("Incorrect symbols in file");
                count = -1;
                break;
            }
        }
        count++;

        if (feof(fin))
            break;

        if (count == -1)
            break;

        if (tmp != ' ' && tmp != '\n')
        {
            printf("Incorrect symbols in file");
            count = -1;
            break;
        }
    }
    return count;
}

/**
Считывает числа из файла в массив.

@param fi [in]
@param pa [in]
@param count [in]

@return ничего не возвращает
*/
void readFromFile(FILE *fin, int *pa, int count)
{
    int *num = pa;

    for (int i = 0; i < count; i++)
    {
        fscanf(fin, "%d", num);
        if (!i)
            pa = num;
        num++;
    }
}

/**
 Записывает массив в файл

 @param array [in]
 @param array_end [in]
 @param file [in, out]

 @return ничего не возвращает.
 */
void printInFile(const int *array, const int *array_end, FILE *file)
{
    while (array != array_end)
    {
        fprintf(file, "%d ", *array);
        array++;
    }
}

/**
Получает массив из файла, редактирует его и выводит результат в другой файл.

@param fin [in]
@param fout [in]
@param pa [in]
@param pb [in]
@param f [in]
@param flag_big [out]
 
@return 0, если программа работает верно: иначе - код ошибки.
*/
int editArray(int *pa, int *pb, FILE *fin, FILE *fout, char *f)
{
    int *filt = NULL;
    int *filt_end = NULL;

    int count = arrayLen(fin), flag_big = 0;

    if (count != 1 && count != -1)
    {
        rewind(fin);
        readFromFile(fin, pa, count);
        pb = pa + count;

        /*if (f && strcmp(f, "f") == 0)
        {
            //int *pe = pa, *ps = pb;
            int flag = key(pa, pb, &filt, &filt_end);
            //pa = pe;
            //pb = ps;
            if (flag)
            {
                printf("Empty file");
                flag_big = -2;
            }
        }*/

        int flag = key(pa, pb, &filt, &filt_end);
        if (flag != 1)
        {
            printf("Empty file");
            flag_big = -2;
        }

        if (flag_big >= 0)
            mysort(filt, filt_end, sizeof(int), compare_int);

        printInFile(filt, filt_end, fout);
    }

    else if (count != -1)
    {
        printf("Empty file");
        flag_big = -1;
    }

    return flag_big;
}

/**
Освобождает всю использованную память.

@param fin [in]
@param fout [in]
@param pa [in]

@return ничего не возвращает
*/
void freeAll(FILE *fin, FILE *fout, int *pa)
{
    free(pa);
    fclose(fin);
    fclose(fout);
}