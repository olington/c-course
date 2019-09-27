#ifndef file_funcs_h
#define file_funcs_h

#include <stdio.h>
#include "list.h"
#include "main.h"

void scanInt(int *num, char mes[]);
int checkFile(FILE *f);
int numStrings(FILE *f);
void readFromFile(FILE *f, int *num);
void readString(FILE *, char *str);

#endif
