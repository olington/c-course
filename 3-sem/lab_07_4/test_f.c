#include "test_f.h"

#include "input.h"
#include "sort.h"
#include "key.h"
#include "output.h"
#include "test.h"

#define GOOD 0
#define BAD -1
#define EPS 0.001
#define STR_LEN 50

#define N 100

int testMemcmp(void *p1_st, void *p1_end,void *p2_st,void *p2_end)
{
    if((p1_end - p1_st)!= (p1_end - p1_st))
        return BAD;
    if(memcmp(p1_st, p2_st ,p1_end - p1_st) != 0)
        return BAD;
    return GOOD;
}

char *answer(int val)
{
    char *answer = "FAIL";
    if (val == GOOD)
        answer = "PASSED";
    else
        answer = "FAILED";
    return answer;
}

int testKey(int *in, int in_n, int *answer, int ans_n)
{
    int res = GOOD;
    int *ans = NULL;
    int *ans_end = NULL;
    key(in, in + in_n, &ans, &ans_end);
    res = testMemcmp(ans, ans_end, answer, answer+ans_n);
    free(ans);
    return res;
}

void testKeySortFirstTest()
{
    FILE *fin;
    FILE *fout;
    fin = fopen("/Users/olga/Documents/in1.txt", "r");
    int a[7];
    int num1;
    for (int i = 0; i < 7; i++)
    {
        fscanf(fin, "%d", &num1);
        a[i] = num1;
    }
    
    fout = fopen("/Users/olga/Documents/out1.txt", "r");
    int b[3];
    int num2;
    for (int j = 0; j < 3; j++)
    {
        fscanf(fout, "%d", &num2);
        b[j] = num2;
    }
    
    printf("test 1 \t%s\n", answer(testKey(a, 7, b, 3)));
}

void testKeySortSecondTest()
{
    FILE *fin;
    FILE *fout;
    fin = fopen("/Users/olga/Documents/in2.txt", "r");
    int a[3];
    int num1;
    for (int i = 0; i < 3; i++)
    {
        fscanf(fin, "%d", &num1);
        a[i] = num1;
    }
    
    fout = fopen("/Users/olga/Documents/out2.txt", "r");
    int b[3];
    int num2;
    for (int j = 0; j < 3; j++)
    {
        fscanf(fout, "%d", &num2);
        b[j] = num2;
    }
    
    printf("test 2 \t%s\n", answer(testKey(a, 3, b, 3)));
}

void testKeySortThirdTest()
{
    FILE *fin;
    FILE *fout;
    fin = fopen("/Users/olga/Documents/in3.txt", "r");
    int a[18];
    int num1;
    for (int i = 0; i < 18; i++)
    {
        fscanf(fin, "%d", &num1);
        a[i] = num1;
    }
    
    fout = fopen("/Users/olga/Documents/out3.txt", "r");
    int b[9];
    int num2;
    for (int j = 0; j < 9; j++)
    {
        fscanf(fout, "%d", &num2);
        b[j] = num2;
    }
    
    printf("test 3 \t%s\n", answer(testKey(a, 18, b, 9)));
}

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d));
    return d;
}

void testTime()
{
    unsigned long long t_st, t_end, full_time = 0;
    
    FILE *f;
    f = fopen("/Users/olga/Documents/in4.txt", "r");
    
    int len = 0;
    int *pa = NULL;
    
    int n = checkFile(&pa, &len, f);

    printf("\nBubble sort\n\n");
    for (int i = 0; i <= N; ++i)
    {
        int *filtered = malloc(sizeof(int) * len);
        
        memcpy(filtered, pa, len * sizeof(int));

        t_st = tick();
        mysort(filtered, len, 4, compareInt);
        t_end = tick();
        
        printf("test  %d 'time': \t%llu\n", i, (t_end - t_st));
        full_time = full_time + (t_end - t_st);
        
        free(filtered);
    }
    printf("\nAverage  time : \t%llu\n", full_time / N);
    
    printf("\nQsort\n\n");
    for (int i = 0; i <= N; ++i)
    {
        int *filtered = malloc(sizeof(int) * len);
        
        memcpy(filtered, pa, len * sizeof(int));
        
        t_st = tick();
        qsort(filtered, len, 4, &compareInt);
        t_end = tick();
        
        printf("test  %d 'time': \t%llu\n", i, (t_end - t_st));
        full_time = full_time + (t_end - t_st);
        
        free(filtered);
    }
    printf("\nAverage  time : \t%llu\n", full_time / N);
}


int main(int argc, char const *argv[])
{
    testKeySortFirstTest();
    testKeySortSecondTest();
    testKeySortThirdTest();
    testTime();
    return 0;
}
