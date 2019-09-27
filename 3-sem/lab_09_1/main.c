#include <stdio.h>
#include <string.h>

#include "header.h"

int main()
{
    testStrcspn("abcd", "c", 1);
    testStrcspn("hhh", "h", 2);
    testStrcspn("qwerty", "ytr",  3);
    testStrcspn("", "1", 4);
    testStrcspn("1", "", 5);
    return 0;
}

/**
Реализация функции strcspn.

@param str1 [in]
@param str2 [in]

@return кол-во элементов в первой строке, которые не принадлежат второй строке.
*/
int my_strcspn( const char *str1, const char *str2)
{
    int i = 0;
    int j = 0;
    
    while(str1[i] != '\0')
    {
        j = 0;
        while(str2[j] != '\0')
        {
            if(str1[i] == str2[j])
                return i;
            ++j;
        }
        ++i;
    }
    return i;
}

/**
 Выполняет тестирование функции my_strcspn.
 
 @param str1[] [in]
 @param str2[] [in]
 @param ind [in]
 
 @return ничего не возвращает.
 */
void testStrcspn(char str1[], char str2[], int ind)
{
    
    int *str_res = strcspn(str1, str2);
    int *my_res = my_strcspn(str1, str2);
    
    if (str_res == my_res)
        printf("Test %d PASSED\n", ind);
    else
        printf("Test %d FAILED\n", ind);
}
