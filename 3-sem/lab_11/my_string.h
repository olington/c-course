#ifndef my_string_h
#define my_string_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(char *str);
void reverseStr(char *str);
char* convertToStr(int num);
void my_strcat(char *str1, int *i, char *str2);
void strcut(char *str, int max_size);
int octal(int num);
void hexdecimal(int num);

#endif /* my_string_h */
