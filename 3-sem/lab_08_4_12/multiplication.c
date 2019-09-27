#include "multiplication.h"
#include "input.h"
#include "allocation.h"
#include "output.h"

/**
 Выполняет проверки файлов перед умножением; выделяет и освобождает память; выводит результат сложения на экран и в файл.
 
 @param mtr1 [in]
 @param mtr2 [in]
 @param mult [in]
 
 @return ничего не возвращает.
 */
void multiplyMatrix(char *mtr1, char *mtr2, char *mult)
{
    FILE *in1, *in2, *out;
    int n1, m1, n2, m2;
    double **mat1, **mat2, **res = NULL;
    
    in1 = fopen(mtr1, "r");
    in2 = fopen(mtr2, "r");
    out = fopen(mult, "w");
    
    if (!in1 || !in2)
    {
        printf("File doesn't exist\n");
        fprintf(out, "File doesn't exist");
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
        
        else if (m1 == n2)
        {
            res = allocateMatrix(n1, m2);
            res = multiplication(mat1, mat2, res, n1, m1, n2, m2);
            printMatrix(res, n1, m2);
            printMatrixInFile(out, res, n1, m2);
            freeMatrix(res, n1);
        }
        
        else
        {
            printf("Multiplication error\n");
            fprintf(out, "Multiplication error");
        }
        
        freeMatrix(mat1, n1);
        freeMatrix(mat2, n2);
    }
    
    fclose(in1);
    fclose(in2);
    fclose(out);
}

/**
 Выполняет операцию умножения.
 
 @param mat1 [in]
 @param mat2 [in]
 @param res [in]
 @param n1 [in]
 @param m1 [in]
 @param n2 [in]
 @param m2 [in]
 
 @return ничего не возвращает.
 */
double **multiplication(double **mat1, double **mat2, double **res, int n1, int m1, int n2, int m2)
{
    double tmp;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m2; j++)
        {
            tmp = 0;
            for (int k = 0; k < m1; k++)
                tmp += mat1[i][k] * mat2[k][j];
            res[i][j] = tmp;
        }
    return res;
}
