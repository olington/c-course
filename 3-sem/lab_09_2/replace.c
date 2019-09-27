#include "replace.h"

/**
 Выполняет одну замену.
 
 @param string [in]
 @param search [in]
 @param replace [in]
 @param ind [in]
 
 @return 0, если все замены выполнены.
 */
char* str_replace(const char *source, const char *search, const char *replace)
{
    char* linetmp = strdup(source);
    int code_error = OK;
    int ind = 0;
    
    while((code_error = oneReplace(&linetmp, search, replace, &ind)) != 0);
    
    if (code_error == -1)
        printf("Malloc error\n");

    return linetmp;
}

/**
 Выполняет одну замену.
 
 @param string [in]
 @param search [in]
 @param replace [in]
 @param ind [in]
 
 @return 0, если все замены выполнены.
 */
int oneReplace(char **string, const char *search, const char *replace, int * ind)
{
    int err = 1;
    
    int string_len = strlen(*string);
    int search_len = strlen(search);
    int replace_len = strlen(replace);
    char* replace_start = NULL;
    
    if ((*ind > string_len) || ((replace_start = strstr(*string + *ind, search)) == NULL))
        return 0;
    
    int left_len = replace_start - *string;

    char *new_string = malloc(sizeof(char) * (string_len + replace_len - search_len + 1));

    if(new_string == NULL)
        err = 1;
    
    new_string[string_len + replace_len - search_len] = '\0';

    memcpy(new_string, *string, left_len);
    memcpy(new_string + left_len, replace, replace_len);

    char *ptr1 = new_string + left_len + replace_len;
    char *ptr2 = *string + left_len + search_len;

    memcpy(ptr1, ptr2, *string + string_len - ptr2 + 1);

    if (*string)
        free(*string);

    *string = new_string;
    *ind= left_len + replace_len;

    return err;
}
