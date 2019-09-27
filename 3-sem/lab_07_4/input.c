#include "input.h"

void fileLength(int *arr_len, FILE *file)
{
    int tmp;
    while ((fscanf(file, "%d", &tmp) != EOF))
        *arr_len = *arr_len + 1;
}

void readFromfile(int *array, int *array_end, FILE *file)
{
    
    for (; array < array_end; array++)
        fscanf(file, "%d", array);
}

int checkFile(int **array, int *array_length, FILE *file)
{
    *array_length = 0;
    int flag = 0;
    fileLength(array_length, file);
    rewind(file);
    if (*array_length == 0)
        flag = -2;
    else
    {
        *array = (int *)malloc(*array_length * sizeof(int));
        if (*array != NULL)
        {
            int *p_end;
            p_end = *array + *array_length;
            rewind(file);
            readFromfile(*array, p_end, file);
        }
        else
            flag = -3;
    }
    return flag;
}

void printArray(const int *array, const int *array_end)
{
    while (array != array_end)
    {
        printf("%d ", *array);
        array++;
    }
    printf("\n");
}
