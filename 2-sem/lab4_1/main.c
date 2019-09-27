#include <stdio.h>
#include <stdlib.h>
#define N 10

int f1(int a[N])
{
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] % 2 == 0)
            s += a[i];
    }
    return s;
}

int main()
{
    int array[N];
    for (int i = 0; i < N; i++)
    {
        printf("Input element: ");
        scanf("%d", &array[i]);
    }
    printf("%d\n", f1(array));
}
