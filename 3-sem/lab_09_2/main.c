#include <stdio.h>
#include "getline.h"
#include "replace.h"

int main(int argc, char *argv[])
{
    int code_error = 0;
    
    if (argc != 5)
    {
        printf("Argc error\n");
        code_error = -2;
    }
    
    FILE *f_in = fopen(argv[1], "r");
    
    if (!f_in)
    {
        printf("File doesn't exist\n");
        code_error = -3;
    }
    
    FILE *f_out = fopen(argv[2], "w");
    
    size_t str_size = 0;
    char *str = NULL;
    char *new_str = NULL;
    
    while (getline(&str, &str_size, f_in))
    {
        new_str = str_replace(str, argv[3], argv[4]);
        printf("%s", new_str);
        printf("\n");
        fprintf(f_out, "%s", new_str);
    }
    
    free(str);
    free(new_str);
    
    fclose(f_in);
    fclose(f_out);
    
    return code_error;
}
