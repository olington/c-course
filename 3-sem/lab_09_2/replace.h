#ifndef replace_h
#define replace_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0;
#define MALLOC_ERROR -1;

char* str_replace(const char *source, const char *search, const char *replace);
int oneReplace(char **string, const char *search, const char *replace, int * ind);

#endif /* replace_h */
