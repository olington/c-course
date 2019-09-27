#include "list.h"
#include "main.h"

/**
 Считывает целое число, введенное пользователем
 
 @param num [in]
 @param mess [in]
 
 @return ничего не возвращает
 */
void scanInt(int *num, char mess[])
{
    int rc;
    char tmp;
    
    printf("%s", mess);
    
    while(((rc = scanf("%d%c", num, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
        printf("Input error  %s", mess);
        do
            rc = scanf("%c", &tmp);
        while(rc != EOF && tmp != '\n');
    }
}

/**
 Проверяет наличие файла
 
 @param f [in]
 
 @return OK - если ошибок не было, ERR_PARAM - ошибка открытия файла
 */
int checkFile(FILE *f)
{
    int err = 0;
    if (f != NULL)
    {
        fseek(f, 0, SEEK_END);
        long pos = ftell(f);
        
        if (!(pos > 1))
        {
            puts("File is empty");
            err = -1;
            fclose(f);
        }
        
        else
            rewind(f);
    }
    
    else
    {
        puts("No file");
        err = -2;
    }
    
    return err;
}

/**
 Считает кол-во строк в файле
 
 @param f [in]
 
 @return кол-во считанных строк
 */
int numStrings(FILE *f)
{
    int num = 0;
    char c;
    
    while(fscanf(f,"%c",&c) == 1)
        if (c == '\n')
            num++;
    
    rewind(f);
    
    return num;
}

/**
 Считывает числа из файла
 
 @param f [in]
 @param num [in]
 
 @return ничего не возвращает
 */
void readFromFile(FILE *f, int *num)
{
    char c;
    fscanf(f, "%d", num);
    
    do
    {
        fscanf(f, "%c", &c);
    } while (c != '\n');
    
}

/**
 Считывает строку из файла
 
 @param f [in]
 @param str [in]
 
 @return ничего не возвращает
 */
void readString(FILE *f, char *str)
{
    int k = 0, index_space = 0;
    char c;
    fscanf(f, "%c", &c);
    
    while (c == ' ')
        fscanf(f, "%c", &c);
    while(c != ';' && c != '\n')
    {
        if (c == ' ' && str[k-1] != ' ')
            index_space = k-1;
        str[k++] = c;
        fscanf(f, "%c", &c);
    }
    if (str[k-1] == ' ')
        str[index_space+1] = '\0';
    else
        str[k] = '\0';
}
