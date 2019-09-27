#include "input.h"
#include "allocation.h"

/**
 Создание матрицы, состооящей из нулей.
 
 @param mat [in]
 @param n [in]
 @param m [in]
 
 @return ничего не возвращает.
 */
void zeroMatrix(double **mat, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = 0.0;
}

/**
 Считывает матрицу из файла (координатный формат).
 
 @param f [in]
 @param n [in]
 @param m [in]
 
 @return возвращает матрицу.
 */
double **inputMatrixFromFile(FILE *f, int *n, int *m)
{
    int i = 0, j = 0, zero_num = 0;
    double **mat = NULL;
    
    if (f)
    {
        fscanf(f, "%d %d %d", n, m, &zero_num);
        mat = allocateMatrix(*n, *m);
        zeroMatrix(mat, *n, *m);
        for(int h = 0; h < zero_num; h++)
        {
            fscanf(f, "%d %d", &i, &j);
            fscanf(f, "%lf", &(mat[i - 1][j - 1]));
        }
    }
    return mat;
}

