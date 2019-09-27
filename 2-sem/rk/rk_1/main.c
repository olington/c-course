#include <stdio.h>
#include <stdlib.h>

int sum_of_numerals(int num)
{
    int first_num, last_num, sum_num;
    if (abs(num) < 10)
        printf("Error. You can't input single-valued number.\n");
    else
        if (num < 0)
            num *= -1;
    last_num = num % 10;
    while (num > 0)
    {
        first_num = num % 10;
        num /= 10;
    }
    sum_num = first_num + last_num;
    return sum_num;
}

int sequence()
{
    int num = 0, s = 0, mx = -1000;
    while (num != 349)
    {
        printf("num: ");
        scanf("%d", &num);
        if ((abs(num) > 99) && (abs(num) < 1000))
        {
            if (num < 0)
            {
                s += num;
                if ((num > mx) && (num % 2 != 0))
                    mx = num;
            }
        }
        else printf("Error\n");
    }
    printf("Sum of negative numbers: %d\n", s);
    printf("Max negative number: %d\n", mx);
    return 0;
}

void multiples_of_seven()
{
    FILE *f = NULL;
    f = fopen("file.txt", "r+");
    if (f == NULL)
    {
        printf("Could not open file.");
        return;
    }
    printf("\nMultiples of seven");
    int num;
    while (fscanf(f, "%d", &num) != EOF)
        if (num % 7 == 0)
            printf("%d", num);
    fclose(f);
}

int main()
{
    int nat_num;
    printf("Input natural number: ");
    scanf("%d", &nat_num);
    printf("Sum: %d\n", sum_of_numerals(nat_num));
    sequence();
    multiples_of_seven();
    return 0;
}

