#include <stdio.h>
#include "Header.h"
#define N 100


int main(int argc, char** argv)
{
    FILE *f;
    int num, array[N], k = 0;
    if (argc != 2)
    {
        fprintf(stderr, "num_reader.exe <file-name>\n");
        return -1;
        
    }
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "I/O error\n");
        return -2;
    }
    else
    {
        while ((fscanf(f, "%d", &num) == 1) && (k <= N))
        {
            array[k] = num;
            k++;
        }
    }
    
    int *pa = &array[0];
    int *pb = &array[--k] + 1;
    
    printf("min = %d\n", minimum(pa, pb));
    fclose(f);
    return 0;
}


