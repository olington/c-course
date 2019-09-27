#include "addition.h"
#include "allocation.h"
#include "input.h"
#include "output.h"

/**
 Выполняет проверки файлов перед сложением; выделяет и освобождает память; выводит результат сложения на экран и в файл.
 
 @param mtr1 [in]
 @param mtr2 [in]
 @param res [in]
 
 @return ничего не возвращает.
 */
void addMatrix(char *mtr1, char *mtr2, char *res)
{
    FILE *in1, *in2, *out;
    int n1, m1, n2, m2;
    double **mat1, **mat2;
    
    in1 = fopen(mtr1, "r");
    in2 = fopen(mtr2, "r");
    out = fopen(res, "w");
    
    if (!in1 || !in2)
    {
        printf("File doesn't exist\n");
        fprintf(out, "File doesn't exist.");
    }
    
    else
    {
        mat1 = inputMatrixFromFile(in1, &n1, &m1);
        mat2 = inputMatrixFromFile(in2, &n2, &m2);
        
        if (!mat1 || !mat2)
        {
            printf("Memory error\n");
            fprintf(out, "Memory error");
        }
        
        else if (n1 == n2 && m1 == m2)
        {
            mat1 = addition(mat1, mat2, n1, m2);
            printMatrix(mat1, n1, m1);
            printMatrixInFile(out, mat1, n1, m1);
        }
    
        else
        {
            printf("Inappropriate size of matrix: unable to perform an addition\n");
            fprintf(out, "Inappropriate size of matrix: unable to perform an addition");
        }
    
        freeMatrix(mat1, n1);
        freeMatrix(mat2, n2);
    }
    
    fclose(in1);
    fclose(in2);
    fclose(out);
}

/**
 Выполняет операцию сложения.
 
 @param mat1 [in]
 @param mat2 [in]
 @param n [in]
 @param m [in]
 
 @return ничего не возвращает.
 */
double **addition(double **mat1, double **mat2, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat1[i][j] += mat2[i][j];
    return mat1;
}
