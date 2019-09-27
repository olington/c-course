#ifndef my_snprintf_h
#define my_snprintf_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include "my_string.h"

int my_snprintf(char *buffer, int buf_size, char *format, ...);

#endif /* my_snprintf_h */
