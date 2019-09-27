#include "test.h"
#include "input.h"
#include "addition.h"

/**
 Сравнивает два файла.
 
 @param f1 [in]
 @param f2 [in]
 
 @return ничего не возвращает.
 */
void compareFiles(FILE *f1, FILE *f2)
{
    int err = 0;
    
    char ch1, ch2;

    if ((f1 == NULL && f2 != NULL) || (f1 != NULL && f2 == NULL))
        err = 1;
    else if (f1 == NULL && f2 == NULL)
        err = 0;
    else
        while (1)
        {
            ch1 = getc(f1);
            ch2 = getc(f2);
            
            if (feof(f1) && feof(f2))
                break;
            
            else if (feof(f1) || feof(f2) || ch1 != ch2)
            {
                err = 1;
                break;
            }
        }
    if (err == 0)
        printf("Test: PASSED\n");
    else
        printf("Test: NOT PASSED\n");
}

/**
 Проверка сложения.
 
 @return ничего не возвращает.
 */
void additionTest()
{
    FILE *in11_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/in11.txt", "r");
    FILE *in12_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/in12.txt", "r");
    FILE *out11_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/out11.txt", "w");
    FILE *res11_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/res11.txt", "r");
    FILE *in21_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/in21.txt", "r");
    FILE *in22_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/in22.txt", "r");
    FILE *out21_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/out12.txt", "w");
    FILE *res21_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/res12.txt", "r");
    FILE *in31_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/in31.txt", "r");
    FILE *in32_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/in32.txt", "r");
    FILE *out31_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/out13.txt", "w");
    FILE *res31_f = fopen("/Users/olga/Documents/C/3-sem/lab_08_4_12/lab_08_4_12/files/res13.txt", "r");
    
    double **in11 = inputMatrixFromFile(in11_f, 3, 3);
    double **in12 = inputMatrixFromFile(in12_f, 3, 3);
    addMatrix(in11, in12, out11_f);
    compareFiles(out11_f, res11_f);
    
    double **in21 = inputMatrixFromFile(in21_f, 5, 5);
    double **in22 = inputMatrixFromFile(in22_f, 5, 5);
    addMatrix(in21, in22, out21_f);
    compareFiles(out21_f, res21_f);
    
    double **in31 = inputMatrixFromFile(in31_f, 10, 10);
    double **in32 = inputMatrixFromFile(in32_f, 10, 10);
    addMatrix(in31, in32, out31_f);
    compareFiles(out31_f, res31_f);
}

/**
 Проверка умножения.
 
 @return ничего не возвращает.
 */
void multiplicationTest()
{
    FILE *in11_f = fopen("in11.txt", "r");
    FILE *in12_f = fopen("in12.txt", "r");
    FILE *out12_f = fopen("out21.txt", "r");
    FILE *res12_f = fopen("res21.txt", "r");
    FILE *in21_f = fopen("in21.txt", "r");
    FILE *in22_f = fopen("in22.txt", "r");
    FILE *out22_f = fopen("out22.txt", "r");
    FILE *res22_f = fopen("res22.txt", "r");
    FILE *in31_f = fopen("in31.txt", "r");
    FILE *in32_f = fopen("in32.txt", "r");
    FILE *out32_f = fopen("out23.txt", "r");
    FILE *res32_f = fopen("res23.txt", "r");
    
    double **in11 = inputMatrixFromFile(in11_f, 3, 3);
    double **in12 = inputMatrixFromFile(in12_f, 3, 3);
    multiplyMatrix(in11, in12, out12_f);
    compareFiles(out12_f, res12_f);
    
    double **in21 = inputMatrixFromFile(in21_f, 5, 5);
    double **in22 = inputMatrixFromFile(in22_f, 5, 5);
    multiplyMatrix(in21, in22, out22_f);
    compareFiles(out22_f, res22_f);
    
    double **in31 = inputMatrixFromFile(in31_f, 10, 10);
    double **in32 = inputMatrixFromFile(in32_f, 10, 10);
    multiplyMatrix(in31, in32, out32_f);
    compareFiles(out32_f, res32_f);
}

/**
 Проверка вычисления определителя.
 
 @return ничего не возвращает.
 */
void determinantTest()
{
    FILE *in11_f = fopen("in11.txt", "r");
    FILE *out31_f = fopen("out31.txt", "r");
    FILE *res31_f = fopen("res31.txt", "r");
    FILE *in21_f = fopen("in21.txt", "r");
    FILE *out32_f = fopen("out32.txt", "r");
    FILE *res32_f = fopen("res32.txt", "r");
    FILE *in31_f = fopen("in31.txt", "r");
    FILE *out33_f = fopen("out33.txt", "r");
    FILE *res33_f = fopen("res33.txt", "r");
    
    double **in11 = inputMatrixFromFile(in11_f, 3, 3);
    determinant(in11, out31_f);
    compareFiles(out31_f, res31_f);
    
    double **in21 = inputMatrixFromFile(in21_f, 5, 5);
    determinant(in21, out32_f);
    compareFiles(out32_f, res32_f);
    
    double **in31 = inputMatrixFromFile(in31_f, 10, 10);
    determinant(in31, out33_f);
    compareFiles(out33_f, res33_f);
}

int main()
{
    printf("Adittion tests\n");
    additionTest();
    printf("Multiplication tests\n");
    multiplicationTest();
    printf("Determinant tests\n");
    determinantTest();
}
