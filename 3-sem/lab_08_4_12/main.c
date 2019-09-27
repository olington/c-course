#include <stdio.h>
#include <string.h>
#include "constant.h"
#include "allocation.h"
#include "input.h"
#include "determinant.h"
#include "addition.h"
#include "multiplication.h"

int main(int argc, char * argv[])
{
    int status_work = OK;
    
    if (argc == 2 && !strcmp(argv[1], "h"))
        printf(HELP_INFO);
    
    else if (argc == 4 && !strcmp(argv[1], "o"))
        determinant(argv[2], argv[3]);
    
    else if (argc == 5 && !strcmp(argv[1], "a"))
        addMatrix(argv[2], argv[3], argv[4]);
    
    else if (argc == 5 && !strcmp(argv[1], "m"))
        multiplyMatrix(argv[2], argv[3], argv[4]);
    
    else
        status_work = ERROR_ARG;

    return status_work;
}

