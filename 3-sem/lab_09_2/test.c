#include "test.h"
#include "replace.h"

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
        while (feof(f1) && feof(f2))
        {
            ch1 = getc(f1);
            ch2 = getc(f2);
            
            if (feof(f1) || feof(f2) || ch1 != ch2)
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
 Выполняет тестирование замены строки.
 
 @param void [in]
 
 @return ничего не возвращает.
 */
void testReplacing()
{
    FILE *in1_f = fopen("in1.txt", "r");
    FILE *out1_f = fopen("out1.txt", "w");
    FILE *res1_f = fopen("res1.txt", "r");
    FILE *in2_f = fopen("in2.txt", "r");
    FILE *out2_f = fopen("out2.txt", "w");
    FILE *res2_f = fopen("res2.txt", "r");
    FILE *in3_f = fopen("in3.txt", "r");
    FILE *out3_f = fopen("out3.txt", "w");
    FILE *res3_f = fopen("res3.txt", "r");
    
    char *str1 = NULL;
    char *new_str1 = NULL;
    new_str1 = str_replace(str1, "aa", "b");
    fprintf(out1_f, "%s", new_str1);
    compareFiles(out1_f, res1_f);
    
    char *str2 = NULL;
    char *new_str2 = NULL;
    new_str2 = str_replace(str2, "abc", "Q");
    fprintf(out2_f, "%s", new_str2);
    compareFiles(out2_f, res2_f);
    
    char *str3 = NULL;
    char *new_str3 = NULL;
    new_str3 = str_replace(str3, "Jack", "Tom");
    fprintf(out3_f, "%s", new_str3);
    compareFiles(out3_f, res3_f);
}

