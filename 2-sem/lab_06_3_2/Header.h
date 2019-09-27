#ifndef Header
#define Header

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

#endif /* Header */
