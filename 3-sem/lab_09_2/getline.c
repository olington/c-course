#include "getline.h"

/**
 Считывает строку из файла.
 
 @param lineptr [in]
 @param n [in]
 @param stream [in]
 
 @return размер считанной строки.
 */
ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
    if (!stream)
        return FILE_ERROR;
    
    size_t readed = 0;
    char buf[BUF_SIZE];
    *n = 0;
    
    while(fgets(buf, BUF_SIZE, stream) != 0)
    {
        int readed = strlen(buf);
        *lineptr = (char *)realloc(*lineptr, *n + readed + 1);
        memcpy(*lineptr + *n, buf, readed);
        *n += readed;
        (*lineptr)[(*n)] = 0;
        
        if ((*lineptr)[(*n) - 1] == '\n')
            break;
    }
    return *n;
}


