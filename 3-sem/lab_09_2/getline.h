#ifndef getline_h
#define getline_h

#include <stdio.h>

#define BUF_SIZE 100

#define FILE_ERROR -1
#define MEMORY_ERROR -2

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif /* getline_h */
