#include <stdio.h>
#define N 10

int f2_1(int a[N])
{
    int s = 0, average;
    for (int i = 0; i < N; i++)
        s += a[i];
    average = s / N;
    return average;
}

void f2_2(int a[N])
{
    int av, b[N];
    av = f2_1(a);
    for (int i = 0; i < N; i++)
    {
        if (a[i] > av)
            b[i] = a[i];
    }
    for (int i = 0; i < N; i++)
        printf("%d", b[i]);
}

int main()
{
    int array[N];
    for (int i = 0; i < N; i++)
    {
        printf("Input element: ");
        scanf("%d", &array[i]);
    }
    f2_2(array);
}

