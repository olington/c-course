#include <stdio.h>
#include "my_snprintf.h"

/*
 
 %c     Одиночный символ
 %o     Восьмеричное число без знака
 %x     Шестнадцатеричное число без знака

 %ho %hx
 */

void test1()
{
    size_t n = 100;
    char *str1 = malloc((n + 1) * sizeof(char));
    char *str2 = malloc((n + 1) * sizeof(char));
    
    int num = snprintf(str1, n, "%c%c%c%x%c%x%c", -5000, 5000, 500,0,0,0,0);
    int num1 = my_snprintf(str2, n, "%c%c%c%x%c%x%c", -5000, 5000, 500,0,0,0,0);
    
    if (num == num1)
        printf("Test 1: PASSED\n");
    else
        printf("Test 1: NOT PASSED\n");
    
    free(str1);
    free(str2);
}

void test2()
{
    size_t n = 100;
    char *str1 = malloc((n + 1) * sizeof(char));
    char *str2 = malloc((n + 1) * sizeof(char));

    int num = snprintf(str1, n, "%o %o %o", 0, 500, 5000);
    int num1 = my_snprintf(str2, n, "%o %o %o", 0, 500, 5000);
    
    if (num == num1)
        printf("Test 2: PASSED\n");
    else
        printf("Test 2: NOT PASSED\n");
}

void test3()
{
    size_t n = 100;
    char *str1 = malloc((n + 1) * sizeof(char));
    char *str2 = malloc((n + 1) * sizeof(char));
    
    int num = snprintf(str1, n, "%x %x %x", 0, 500, 5000);
    int num1 = my_snprintf(str2, n, "%x %x %x", 0, 500, 5000);
    
    if (num == num1)
        printf("Test 3: PASSED\n");
    else
        printf("Test 3: NOT PASSED\n");
}

void test4()
{
    size_t n = 100;
    char *str1 = malloc((n + 1) * sizeof(char));
    char *str2 = malloc((n + 1) * sizeof(char));
    
    int num = snprintf(str1, n, "%ho %ho %ho", (unsigned short)0, (unsigned short)500, (unsigned short)5000);
    int num1 = my_snprintf(str2, n, "%ho %ho %ho", (unsigned short)0, (unsigned short)500, (unsigned short)5000);
    
    if (num == num1)
        printf("Test 4: PASSED\n");
    else
        printf("Test 4: NOT PASSED\n");
}

void test5()
{
    size_t n = 100;
    char *str1 = malloc((n + 1) * sizeof(char));
    char *str2 = malloc((n + 1) * sizeof(char));
    
    int num = snprintf(str1, n, "%hx %hx %hx", (unsigned short)0, (unsigned short)500, (unsigned short)5000);
    int num1 = my_snprintf(str2, n, "%hx %hx %hx", (unsigned short)0, (unsigned short)500, (unsigned short)5000);
    
    if (num == num1)
        printf("Test 5: PASSED\n");
    else
        printf("Test 5: NOT PASSED\n");
}

void test6()
{
    size_t n = 100;
    char *str1 = malloc((n + 1) * sizeof(char));
    char *str2 = malloc((n + 1) * sizeof(char));
    
    int num = snprintf(str1, n, "%c %o %x %ho %hx", -5000, 5000, 5000, (unsigned short)5000, (unsigned short)5000);
    int num1 = my_snprintf(str2, n, "%c %o %x %ho %hx", -5000, 5000, 5000, (unsigned short)5000, (unsigned short)5000);
    
    if (num == num1)
        printf("Test 6: PASSED\n");
    else
        printf("Test 6: NOT PASSED\n");
}

int main(int argc, const char * argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    
    return 0;
}
