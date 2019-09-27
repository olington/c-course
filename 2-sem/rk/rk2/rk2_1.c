#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
#include <time.h>

void printf_matr(int n, char m[n][n])
{
    int n1 = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n1; j++)
            printf("%c", m[i][j]);
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    int n = 0, sep = 0,  matr[n][n], count_low[n], count_up[n];
    assert(scanf("%d", &n));
    for (int i = 0; i < n; i++)
        count_low[i] = count_up[i] = 0;
    char **a = malloc((n + 1) * (n + 1) * sizeof(char));
    for (int i = 0; i < n; i++)
        a[i] = malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) {
        assert(scanf("%d", &sep));
        assert(sep < n);
        for (int j = 0; j < n; j++)
        {
            if (j == sep)
                a[i][j] = '#';
            else
            {
                matr[i][j] = 0 + rand() % 2;
                if (matr[i][j])
                {
                    a[i][j] = 'a' + rand() % 25;
                    if (j < sep)
                        count_low[i]++;
                }
                else
                {
                    a[i][j] = 'A' + rand() % 25;
                    if (j < sep)
                        count_up[i]++;
                }
            }
        }
    }
    
    if (count_low == 0)
        printf("No strings to deete");
    else
    {
        int i;
        for (i = 0; i < n - 1; i++)
        {
            if (count_low[i] < count_up[i])
            {
                char t[100] = "";
                strcpy(t, a[i]);
                strcpy(a[i], a[i + 1]);
                strcpy(a[i + 1], t);
                free(a[n - 1]);
                n--;
                int p1 = count_low[i];
                count_low[i] = count_low[i + 1];
                count_low[i + 1] = p1;
                int p2 = count_up[i];
                count_up[i] = count_up[i + 1];
                count_up[i + 1] = p2;
                i--;
            }
        }
        i++;
        if (count_low[i] > count_up[i])
        {
            char t[100] = "";
            free(a[n - 1]);
            n--;
        }
        printf_matr(n, a);
    }
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
    return 0;
}
