#include "my_string.h"

/**
 Переворачивает строку
 
 @param str [in]
 
 @return ничего не возвращает
 */
void reverseStr(char *str)
{
    for (int i = 0; i < my_strlen(str)/2; i++)
    {
        char c = str[i];
        str[i] = str[my_strlen(str) - i - 1];
        str[my_strlen(str) - i - 1] = c;
    }
}

/**
 Находит длину строки
 
 @param str [in]
 @param len[out]
 
 @return длина строки
 */
int my_strlen(char *str)
{
    int len = 0;
    for (int i = 0; str[i]; i++)
        len++;
    
    return len;
}

/**
 Обрезает строку
 
 @param str [in]
 @param max_size [in]]
 
 @return ничего не возвращает
 */
void strcut(char *str, int max_size)
{
    for (int i = my_strlen(str)-1; i >= 0; i--)
        if (i+1 >= max_size)
            str[i] = '\0';
}

/**
Слияние двух строк
 
 @param str1 [in]
 @param i [in]]
 @param str2 [in]]
 
@return ничего не возвращает
 */
void my_strcat(char *str1, int *i, char *str2)
{
    for (int j = 0; str2[j]; j++)
        str1[(*i)++] = str2[j];
    str1[*i] = '\0';
}



/**
 Переводит число из десятичной системы счисления в восьмeричную
 
 @param num [in]
 
 @return число в восьмеричной системе счисления
 */
int octal(int num)
{
    int octal_num = 0, i = 1;
    
    while (num != 0)
    {
        octal_num += (num % 8) * i;
        num /= 8;
        i *= 10;
    }
    
    return octal_num;
}

/**
 Переводит число из десятичной системы счисления в шестнадцатеричную
 
 @param num [in]
 
 @return число в шестнадцатеричной системе счисления
 */
void hexdecimal(int num)
{
    char hex_digits[100];
    int i = 0;
    while(num != 0)
    {
        int temp  = 0;
        temp = num % 16;
        if(temp < 10)
        {
            hex_digits[i] = temp + 48;
            i++;
        }
        
        else
        {
            hex_digits[i] = temp + 55;
            i++;
        }
        
        num = num  /16;
    }
}

/**
 Конвертирует число int в строку
 
 @param num [in]
 
 @return указатель на строку
 */
char* convertToStr(int num)
{
    char *result = malloc(100 * sizeof(char));
    
    int j = 0;
    int sign = 0;
    
    if (num < 0)
    {
        num = -num;
        sign = 1;
    }
    
    for (int i = 0; num > 0; i++, j++)
    {
        result[j] = (num % 10) + '0';
        num /= 10;
    }
    
    if (sign)
        result[j++] = '-';
    
    if (!j)
        result[j++] = '0';
    
    result[j] = '\0';
    
    reverseStr(result);
    
    return result;
}
