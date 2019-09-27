#include <stdio.h>
#define N 100

int minimum(int *pa, int *pb)
{
    int multiply, min = (*pa * *(pa + 1));
    for (; pa < (pb - 1); pa++)
    {
        multiply = (*pa * *(pa + 1));
        printf("%d * %d = %d \n", *pa, *(pa + 1), multiply);
        if(multiply < min)
            min = multiply;
    }
    return min;
}

int main(int argc, char** argv)
{
    FILE *f;
    int num, array[N], k = 0;
    if (argc != 2)
    {
        fprintf(stderr, "File error\n");
        return -1;
        
    }
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "File error\n");
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


