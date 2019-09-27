/*
 Функция-фильтр:
 В массиве остаются элементы, которые больше среднего арифметического всех элементов массива.
 
 Сортировка:
 Сортировка обменом (метод пузырька): последовательно сравниваются пары соседних элементов x[k] и x[k+1]
 (k = 0, 1, ... , n-2) и, если x[k] > x[k+1], то они переставляются; в результате наибольший элемент окажется на
 своем месте в конце массива; затем этот метод применяется ко всем элементам, кроме последнего, и т.д. */

#include "input.h"
#include "sort.h"
#include "key.h"
#include "output.h"
#include "constant.h"

status_work = OK;

int main(int argc, char * argv[])
{
    int flag = 0;
    int k;
    int arr_len = 0;
    int *array = NULL;
    int *array_end = NULL;
    int *filt = NULL;
    int *filt_end = NULL;
    int filter_flag = NO;
    
    FILE *f;
    if (argc < 4)
        status_work = ERROR_ARG;
    
    f = fopen(argv[1], "r");
    if (f == NULL)
        status_work = ERROR_OPEN_INPUT_FILE;
    
    if((strcmp(argv[3], "f")) == 0)
        filter_flag = YES;
    
    int checked_file = checkFile(&array, &arr_len, f);
    fclose(f);
    
    if (checked_file == -2)
    {
        fprintf(stderr, "Empty file\n");
        flag = -2;
    }
    
    else if (checked_file == -3)
        status_work = ERROR_MALLOC;
    
    if (flag == 0)
    {
        array_end = array + arr_len;
        printf("Original array:\n");
        printArray(array, array_end);
    
        if(filter_flag == YES)
        {
            k = key(array, array_end, &filt, &filt_end);
            if (k == 0)
            {
                printf("\nFiltered array:\n");
                printArray(filt, filt_end);
            }
        
            else if (k == -1)
                status_work = ERROR_EMPTY_FILE;
        
            else if (k == -2)
                status_work = ERROR_EMPTY_ARRAY;
        
            else if (k == -3)
                status_work = ERROR_MALLOC;
        }
        
        else
        {
            filt = array;
            filt_end = array_end;
        }
    
        mysort(filt, filt_end - filt, sizeof(int), compareInt);
    
        FILE *f_out = fopen(argv[2], "w");
        if (f_out == 0)
            status_work = ERROR_OPEN_OUTPUT_FILE;
        
        else
        {
            printInFile(filt, filt_end, f_out);
            fclose(f_out);
        }
    
        if(array != NULL)
            free(array);
    
        if(filter_flag == YES)
        {
            if(filt != NULL)
                free(filt);
        }
    }
    
    switch (status_work)
    {
        case ERROR_ARG:
            printf("Not enough arguments\n");
            break;
        case ERROR_OPEN_INPUT_FILE:
            printf("Unable to open input file\n");
            break;
        case ERROR_EMPTY_FILE:
            printf("File is empty\n");
            break;
        case ERROR_EMPTY_ARRAY:
            printf("Dst array is empty\n");
            break;
        case ERROR_MALLOC:
            printf("Malloc error\n");
            break;
        case ERROR_OPEN_OUTPUT_FILE:
            printf("Unable to open output file\n");
            break;
        case OK:
            printf("Successfully completed\n");
            break;
    }
    
    return status_work;
}
