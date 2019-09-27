#include "allocation.h"

/**
 Выделяет память (массив указателей на строки).
 
 @param n [i]
 @param m [in]
 
 @return массив указателей на строки.
 */
double** allocateMatrix(int n, int m)
{
    double **data = calloc(n, sizeof(double*));
    if (data)
    {
        for (int i = 0; i < n; i++)
        {
            data[i] = malloc(m * sizeof(double));
            if (!data[i])
                freeMatrix(data, n);
        }
    }
    return data;
}
    
/**
 Освобождает память.
 
 @param data [in]
 @param n [in]
 
 @return ничего не возвращает.
 */

void freeMatrix(double **data, int n)
{
    for (int i = 0; i < n; i++)
        free(data[i]);
    free(data);
}
