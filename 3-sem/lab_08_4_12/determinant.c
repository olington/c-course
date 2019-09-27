#include "determinant.h"
#include "allocation.h"
#include "input.h"

/**
 Находит определитель.
 
 @param mtr [in]
 @param res [in]
 
 @return ничего не возвращает.
 */
void determinant(char *mtr, char *res)
{
    FILE *in, *out;
    int n, m;
    double **mat, **matr1, **det;
    
    in = fopen(mtr, "r");
    out = fopen(res, "w");
    
    if (!in)
    {
        printf("File doesn't exist\n");
        fprintf(out, "File doesn't exist.");
    }
    
    else
    {
        mat = inputMatrixFromFile(in, &n, &m);
        
        if (!mat)
        {
            printf("Memory error\n");
            fprintf(out, "Memory error");
        }
        
        if (n < 1 || m <1)
        {
            printf("Unable to find determinant\n");
            fprintf(out, "Unable to find determinant");
        }
        else if (n == m)
        {
            **det = detMatrix(mat, n);
            printf("%lf\n", **det);
            fprintf(out, "%lf", **det);
        }
        
        else
        {
            printf("Inappropriate size of matrix: unable to find determinant\n");
            fprintf(out, "Inappropriate size of matrix: unable to to find determinant");
        }
    }
    
    fclose(in);
    fclose(out);
}

/**
 Вычисляет определитель.
 
 @param a [in]
 @param size [in]
 
 @return определитель матрицы.
 */
double detMatrix(double **a, int size)
{
    int i,j;
    int n2 = size - 1;
    double **matr1;
    double det = 0;
    
    if (size == 2)
        det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
    else if (size > 2)
    {
        matr1 = allocateMatrix(n2, n2);
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size - 1; j++)
            {
                if(j < i)
                    matr1[j] = a[j];
                else
                    matr1[j] = a[j + 1];
            }
            det += pow(-1.0,(i + j)) * detMatrix(matr1, size - 1) * a[i][size - 1];
        }
    }
    return det;
}
