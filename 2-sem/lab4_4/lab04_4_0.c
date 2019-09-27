#include <stdio.h>
#define N 10

void bubble_sort(int a[N])
{
    for(int i = 0 ; i < N - 1; i++)
    {
        for(int j = 0; j < N - i - 1; j++)
        {
            if(a[j] > a[j+1])
            {
                int tmp = a[j];
                a[j] = a[j+1] ;
                a[j+1] = tmp;
            }
        }
    }
}


int main()
{
    int array[N];
    for (int i = 0; i < N; i++)
    {
        printf("Input element: ");
        scanf("%d", &array[i]);
    }
    bubble_sort(array);
    printf("Sorted array: ");
    for (int i = 0; i < N; i++)
        printf("%d ", array[i]);
}

