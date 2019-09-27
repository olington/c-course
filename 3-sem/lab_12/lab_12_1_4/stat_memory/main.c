#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include "main_func.h"

int main(int argc, char* argv[])
{
    FILE *fin = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");

    int *pa = (int*)malloc(1000 * sizeof(int)),
        *pb = NULL, flag_big = 0;

    if (!fin || !fout)
    {
        printf("File error");
        flag_big = -3;
    }

    else

        {
            char *f = malloc(10 * sizeof(char));
            flag_big = editArray(pa, pb, fin, fout, argv[3]);
            free(f);
        }

    freeAll(fin, fout, pa);
    return flag_big;
}