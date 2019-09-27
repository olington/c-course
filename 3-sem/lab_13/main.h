#ifndef main_h
#define main_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SORT_INDX 3
#define MAX_FILTER_INDX 2
#define SIZE 200
#define YEAR 1990
#define GENRE "Rock"

#include "list.h"
#include "file_funcs.h"

enum ERRORS {ERROR_TESTING_FILTER, ERROR_TESTING_SORT, ERROR_COMMAND_LINE, ERROR_FILE, OK};

#endif
