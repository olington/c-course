#include <stdio.h>
#include <math.h>
#define size_full 32
#define size_part 8

int input_error()
{
    int x, rc;
    char tmp;
    
    while (((rc = scanf("%d%c", &x, &tmp)) != 2 && rc != EOF) || tmp != '\n')
    {
        printf("Input error. Enter an integer: ");
        do
        {
            rc = scanf("%c", &tmp);
        }
        while(rc != EOF && tmp != '\n');
    }
    return x;
}

int check(int val, char* message, int low, int up)
{
    val = input_error();
    while ((val > up) || (val < low))
    {
        printf(message);
        val = input_error();
    }
    return val;
}

int bin_to_ten(int* adress, size_t beg)
{
    int res = 0, val = 7;
    for (size_t i = beg; i < beg + 8; ++i)
    {
        res += adress[i]*pow(2, val--);
    }
    
    return res;
}

void bin(int* ip, int part, size_t i)
{
    while (part > 0)
    {
        ip[i--] = part % 2;
        part /= 2;
    }
}

void ip_array(int p1, int p2, int p3, int p4, int* ip)
{
    bin(ip, p4, size_part * 4 - 1);
    bin(ip, p3, size_part * 3 - 1);
    bin(ip, p2, size_part * 2 - 1);
    bin(ip, p1, size_part - 1);
}

void bit_multiply(int* mask, int* ip, int* adress)
{
    for (size_t i = 0; i < size_full; ++i)
        adress[i] = mask[i]*ip[i];
}

void mask_array(int mask, int* mask_a)
{
    for (int i = 0; i < mask; ++i)
        mask_a[i] = 1;
}

int main()
{
    FILE *f;
    char pos = 'y';
    char resp = 'y';
    int p1, p2, p3, p4, mask;
    int mask_a[size_full] = {0}, ip[size_full] = {0}, adress[size_full] = {0};
    int a_p1, a_p2, a_p3, a_p4;
    
    f = fopen("ip_adress.txt", "w");
    if (f != NULL)
    {
        while (resp == pos)
        {
            
            printf("Input first part: ");
            p1 = check(p1, "Error. Input first part: ", 0, 255);
            printf("Input second part: ");
            p2 = check(p2, "Error. Input second part: ", 0, 255);
            printf("Input third part: ");
            p3 = check(p3, "Error. Input third part: ", 0, 255);
            printf("Input fourth opart: ");
            p4 = check(p4, "Error. Input fourth part: ", 0, 255);
            printf("Input mask: ");
            mask = check(p1, "Error. Input mask: ", 0, 32);
            fprintf(f, "%d.%d.%d.%d/%d\n", p1, p2, p3, p4, mask);
            printf("Do you want to continue? y/n: ");
            scanf("\n");
            scanf("%c", &resp);
        }
        
    }
    else
    {
        printf("Couldn't open file.\n");
    }
    
    fclose(f);
    
    f = fopen("ip_adress.txt", "r");
    if (f != NULL)
    {
        while (!feof(f))
        {
            fscanf(f, "%d.%d.%d.%d/%d\n", &p1, &p2, &p3, &p4, &mask);
            mask_array(mask, mask_a);
            ip_array(p1, p2, p3, p4, ip);
            bit_multiply(mask_a, ip, adress);
            a_p1 = bin_to_ten(adress, 0);
            a_p2 = bin_to_ten(adress, 8);
            a_p3 = bin_to_ten(adress, 16);
            a_p4 = bin_to_ten(adress, 24);
            
            printf("\nNetwork adress: %d.%d.%d.%d\n", a_p1, a_p2, a_p3, a_p4);
        }
    }
    else
    {
        printf("Couldn't open file.\n");
    }
    fclose(f);
    return 0;
}
