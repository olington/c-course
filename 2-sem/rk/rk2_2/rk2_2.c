#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

struct contact
{
    char surname[30];
    char adress[30];
    char tel[16];
};

void contact1(char *p1, char *p2)
{
    int i = 0;
    while ((*(p2+i) != '\n') && (*(p2+i) != '\0'))
    {
        *(p1+i) = *(p2+i);
        i++;
    }
}

void check_sur(char *p1, char *p2)
{
    int c = 0;
    int k = 0;
    while ((*(p1+k) != '\n') && (*(p1+k) != '\0'))
    {
        for (int j = 0; j < 52; j++)
        {
            if (*(p1+k) == *(p2+j))
                c = 1;
        }
        assert (c == 1);
        c = 0;
        k++;
    }
}

void check_tel(char *p)
{
    int c = 1;
    char tel[16] = "8-495-***-**-**\0";
    for (int i = 0; i < 16; i++)
    {
        if ((*(p+i) != tel[i]) && (tel[i] != '*'))
        {
            c = 0;
            break;
        }
        else if ((tel[i] == '*') && (isdigit(*(p+i)) == 0))
        {
            c = 0;
            break;
        }
    }
    assert(c == 1);
}

int main()
{
    char lit[52];
    char a = 'a';
    char A = 'A';
    for (int i = 0; i < 26; i++)
    {
        lit[i] = a++;
        lit[i+26] = A++;
    }
    
    int rc, n;
    char c[10];
    printf("Input number of contacts: ");
    rc = scanf("%d", &n);
    assert((rc == 1) && (n > 0));
    struct contact contact[n];
    char surname[30], adress[30], tel[16];
    
    for (int i = 0; i < n; i++)
    {
        for (int m = 0; m < 30; m++)
        {
            surname[m] = '\0';
            adress[m] = '\0';
            contact[i].surname[m] = '\0';
            contact[i].adress[m] = '\0';
        }
        for (int m = 0; m < 16; m++)
        {
            tel[m] = '\0';
            contact[i].tel[m] = '\0';
        }
        
        gets(c);
        printf("\nInput username: ");
        fgets(surname, 30, stdin);
        fflush(stdin);
        printf("Input adress: ");
        fgets(adress, 30, stdin);
        fflush(stdin);
        printf("Input phone number: ");
        fgets(tel, 16, stdin);
        fflush(stdin);
        check_sur(surname, lit);
        check_tel(tel);
        contact1(contact[i].surname, surname);
        contact1(contact[i].adress, adress);
        contact1(contact[i].tel, tel);
    }
    
    FILE *file = fopen("test.txt", "w");
    for (int i = 0; i < n; i++)
    {
        fputs(contact[i].surname, file);
        fputs(" ", file);
        fputs(contact[i].adress, file);
        fputs(" ", file);
        fputs(contact[i].tel, file);
        fputs("\n", file);
    }
}
