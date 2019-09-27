#include <stdio.h>

int dist_between_max(int dist)
{
    int num2 = 0, rc = 0, num1 = 0, num3 = 0, num = 0, k = 0, maximum;
    char tmp;
    while (((rc = scanf("%d%c", &num, &tmp)) != 2 && rc != EOF)
           || (tmp != '\n'))
    {
        if (k == 0)
        {
            k++;
            num1 = num;
            maximum = num1;
        }
        else if (k == 1)
        {
            k++;
            num2 = num;
            if (num2 > num1)
                maximum = num2;
        }
        else
        {
            num3 = num;
            if ((num3 > num2) && (num3 > num1))
                maximum = num3;
            if (maximum == num1)
            {
                if (num3 == num1)
                    dist += 2;
                else if (num2 == num1)
                    dist++;
            }
            else if (maximum == num2)
            {
                if (num3 == num2)
                    dist++;
            }
            num1 = num2;
            num2 = num3;
        }
    }
    num3 = num;
    if ((num2 > num1) && (num2 > num3))
    {
        dist++;
    }
    return dist;
}

int main()
{
    int dist = 0;
    printf("Distance between two local maximus: %d\n", dist_between_max(dist));
    return 0;
}
