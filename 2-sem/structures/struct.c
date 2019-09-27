#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int file_func() {
    FILE *f = fopen("struct.txt", "w+");
    char str[100] = "", pars_string[100] = "", copy[3] = "", ch[10] = "how many ";
    int i = 0, k = 0, flag = 0;
    gets(str);
    for (i = 0; i < 9; i++)
    {
        pars_string[i] = str[i];
        str[i] = ' ';
    }
    if (strcmp(pars_string, ch))
        return 0;
    while (str[i] != ' ')
    {
        copy[k] = str[i];
        str[i] = ' ';
        k++;
        i++;
    }
    if ((strcmp(copy, "cm")) && (strcmp("ml", copy)))
        return 0;
    else if (!(strcmp("cm", copy)))
        flag = 1;
    else if (!(strcmp("ml", copy)))
        flag = 2;
    strcpy(pars_string, " ");
    k = 0;
    i++;
    while (str[i] != ' ')
    {
        pars_string[k] = str[i];
        str[i] = ' ';
        k++;
        i++;
    }
    if (!(pars_string[0] == 'i' && pars_string[1] == 'n' && strlen(pars_string) == 2))
        return 0;
    strcpy(pars_string, " ");
    i++;
    k = 0;
    while (str[i] != ' ')
    {
        pars_string[k] = str[i];
        str[i] = ' ';
        k++;
        i++;
    }
    int num = (int)strtol(pars_string, NULL, 10);
    strcpy(pars_string, " ");
    k = 0;
    for (i = strlen(str); i > strlen(str) - 2; i--)
        pars_string[k] = str[i];
    if (!((flag == 1 && !(strcmp(pars_string, "m"))) || (flag == 2 && !(strcmp(pars_string, "l")))))
        return 0;
    else if (flag == 1 && !(strcmp(pars_string, "m")))
        fprintf(f, "%d cm\n", num * 100);
    else
        fprintf(f, "%d ml\n", num * 1000);
    return 1;
}

int main()
{
    if (!file_func())
        printf("Error!");
    return 0;
}
