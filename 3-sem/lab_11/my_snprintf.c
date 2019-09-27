#include "my_snprintf.h"

/*
 Запись чисел со спецификаторами %c %o %x %ho %hx в строку
 
 @param buffer [in]
 @param buf_size [in]
 @param format [in]
 
 @return длина строки
 */
int my_snprintf(char *buffer, int buf_size, char *format, ...)
{
    int readed = 0;
    int prc = 0;
    
    va_list vl;
    va_start(vl, format);
    
    if (buf_size < 0)
        readed = -1;
    
    else
    {
        int i = 0, j = 0;
        
        if (!buf_size || buf_size == 1)
            buffer[0] = '\0';
        
        while (buf_size > 0 && format[i] && readed >= 0)
        {
            if (prc)
            {
                prc = 0;
                if (format[i] == '%')
                {
                    buffer[j++] = format[i];
                    readed++;
                }
                
                else
                {
                    if (format[i] == 'c')
                    {
                        //buffer[j++] = va_arg(vl, int);
                        int num = va_arg(vl, int);
                        char *s = "1";
                        my_strcat(buffer, &j, s);
                    }
                    
                    else if (format[i] == 'o')
                    {
                        int num = va_arg(vl, int);
                        int num1 = octal(num);
                        char *s = convertToStr(num1);
                        my_strcat(buffer, &j, s);
                        free(s);
                    }
                    
                    else if (format[i] == 'x')
                    {
                        int num = va_arg(vl, int);
                        hexdecimal(num);
                        char *s = convertToStr(num);
                        my_strcat(buffer, &j, s);
                        free(s);
                    }
                    
                    else if (format[i] == 'h' && format[i+1] == 'o')
                    {
                        short int num = va_arg(vl, int);
                        short int num1 = octal(num);
                        char *s = convertToStr(num1);
                        my_strcat(buffer, &j, s);
                        i++;
                        free(s);
                    }
                    
                    else if (format[i] == 'h' && format[i+1] == 'x')
                    {
                        short int num = va_arg(vl, int);
                        hexdecimal(num);
                        char *s = convertToStr(num);
                        my_strcat(buffer, &j, s);
                        i++;
                        free(s);
                    }
                    
                    else
                        readed = -3;
                }
            }
            
            else if (format[i] == '%')
                prc = 1;
            
            else
                buffer[j++] = format[i];
            
            i++;
        }
        buffer[j] = '\0';
    }
    va_end(vl);
    if (!readed)
        readed = my_strlen(buffer);
    
    strcut(buffer, buf_size);
    
    return readed;
}
