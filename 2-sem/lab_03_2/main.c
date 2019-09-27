#include <stdio.h>
#include <math.h>

int arithmetical_mean(int summ, int kol, int nm)
{
    float x_average, ar_average;
    x_average = summ / kol;
    ar_average = sqrt((nm - x_average)*(nm - x_average)/(kol - 1));
    return ar_average;
}

int three_sigmas_rule(int file)
{
    int num2 = 0, rc = 0, num1 = 0, num3 = 0, num = 0, y = 0, k = 0, s = 0, sqrt_average, arith_average;
    char tmp;
    while (((rc = fscanf(file, "%d%c", &num, &tmp)) != 2 && rc != EOF)
           || (tmp != '\n'))
    {
        if (k == 0)
        {
            k++;
            num1 = num;
            s += num;
            sqrt_average = sqrt(s / k);
            arith_average = arithmetical_mean(s, k, num1);
        }
        else if (k == 1)
        {
            k++;
            num2 = num;
            s += num;
            sqrt_average = s / k;
            arith_average = arithmetical_mean(s, k, num2);
        }
        else
        {
            k++;
            num3 = num;
            s += num;
        
            num1 = num2;
            num2 = num3;
            sqrt_average = sqrt(s / k);
            arith_average = arithmetical_mean(s, k, num3);
        }
    }
    if (arith_average > 3 * sqrt_average)
        y = 1;
    return y;
}

int main()
{
    int y;
    FILE *file;
    file=fopen("numbers.txt","r");
    y = three_sigmas_rule(y);
    if (y == 1)
        printf("Three sigmas rule is met");
    else
        printf("Three sigmas rule isn't met");
    int fclose(FILE *f);
    return 0;
}
