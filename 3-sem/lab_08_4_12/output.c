#include "output.h"

/**
 Считает количество ненулевых элементов для вывода матрицы в файл.
 
 @param mat [in]
 @param n [in]
 @param m [in]
 
 @return количество ненулевых элементов.
 */
int notZeroElements(double **mat, int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            count++;
    return count;
}

/**
 Выводит матрицу на экран.
 
 @param mat [in]
 @param n [in]
 @param m [in]
 
 @return ничего не возвращает.
 */
void printMatrix(double **mat, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%f ", mat[i][j]);
        printf("\n");
    }
}

/**
 Печатает матрицу в файл.
 
 @param mat [in]
 @param n [in]
 @param m [in]
 
 @return ничего не возвращает.
 */
void printMatrixInFile(FILE *f, double **mat, int n, int m)
{
    fprintf(f, "%d %d %d\n", n, m, notZeroElements(mat, n, m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fprintf(f, "%d %d %f\n", i + 1, j + 1, mat[i][j]);
}
