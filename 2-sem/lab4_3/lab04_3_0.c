#include <stdio.h>
#define N 10

int pal(int n)
{
    int p, k, m;
    p = 0;
    m = n;
    while (m > 0)
    {
        k = m % 10;
        m = m / 10;
        p = p * 10 + k;
    }
    return p;
}

void f3(int a[N])
{
    for (int i = 0; i < N; i++)
    {
        if (a[i] != pal(a[i]))
            a[i] = NULL;
    }
    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
}

int main()
{
    int array[N];
    for (int i = 0; i < N; i++)
    {
        printf("Input element: ");
        scanf("%d", &array[i]);
    }
    f3(array);
}
