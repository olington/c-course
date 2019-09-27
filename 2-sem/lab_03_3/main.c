#include <stdio.h>

void bubble_sort(FILE *f)
{
    int n, i, j;
    int a[100];
    // считываем количество чисел n
    scanf_s("%d", &n);
    
    // формируем массив n чисел
    for(i = 0 ; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
    for(i = 0 ; i < n - 1; i++) {
        // сравниваем два соседних элемента.
        for(j = 0 ; j < n - i - 1 ; j++) {
            if(a[j] > a[j+1]) {
                // если они идут в неправильном порядке, то
                //  меняем их местами.
                int tmp = a[j];
                a[j] = a[j+1] ;
                a[j+1] = tmp;
            }
        }
    }
}

void get_number_by_pos(FILE *f)
{
    int number;
    long int pos;
    size_t read;
    int rc;
    pos = ftell(f);
    printf("ftell: pos = %ld\n", pos);
    read = fread(&number, sizeof(int), 1, f);
    printf("fread: %s (%d)\n", read == 1 ? "OK" : "ERROR", number);
    pos = ftell(f);
    printf("ftell: pos = %ld\n", pos);
    rc = fseek(f, 0, SEEK_SET);
    printf("fseek: %s\n", rc == 0 ? "OK" : "ERROR");
    pos = ftell(f);
    printf("ftell: pos %ld\n", pos);
    read = fread(&number, sizeof(int), 1, f);
    printf("fread: %s (%d)\n", read == 1 ? "OK" : "ERROR", number);
}

void write_random_numbers(FILE *file)
{
    size_t wrote;
    int a = 0 + rand() % 100;
    wrote = fwrite(&a, sizeof(int), 1, file);
}

void output_numbers(FILE *file)
{
    int num;
    //FILE * file = fopen("file.dat", "rb");
    while (fscanf(file, "%d", &num) == 1)
        printf("%d\n", num);
}

int main()
{
    FILE * f1 = fopen("file.dat", "wb");
    write_random_numbers(f1);
    FILE * f2 = fopen("file.dat", "rb");
    output_numbers(f2);
    fclose(f1);
}
