#include "input.h"
#include "sort.h"
#include "key.h"
#include "output.h"
#include "test.h"
#include "time.h"

#define GOOD 0
#define BAD -1
#define EPS 0.001
#define STR_LEN 50

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d));
    return d;
}

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
        answer = "OK";
    else
        answer = "NOT OK";
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

void testKeySort()
{
    int in1[] = { 4, 1, 2 };
    int ans1[] = { 4, 2 };
    printf("test 1 \t%s\n", answer(testKey(in1, 3, ans1, 2)));
    int in2[] = { 1, 2, 3 };
    int ans2[] = { 3 };
    printf("test 2 \t%s\n", answer(testKey(in2, 3, ans2, 1)));
    int in3[] = { 10, 5, 2 };
    int ans3[] = { 10, 5, 2 };
    printf("test 3 \t%s\n", answer(testKey(in3, 3, ans3, 3)));
}

int testSort(int *in, int *in2, int in_n)
{
    
    mysort(in, in_n, sizeof(int), compareInt);
    qsort(in2, in_n, sizeof(int), compareInt);
    if(memcmp(in, in2, in_n) == 0) return GOOD;
    else return BAD;
}

void testMysort()
{
    {
        int in11[] = {5, 4, 3, 2, 1};
        int in12[] = {5, 4, 3, 2, 1};
        int n = sizeof(in11)/sizeof(in11[0]);
        printf("sort 1 \t%s\n", answer(testSort(in11, in12, n)));
    }
    
    {
        int in11[] = {1, 2, 3, 4, 5};
        int in12[] = {1, 2, 3, 4, 5};
        int n = sizeof(in11)/sizeof(in11[0]);
        printf("sort 2 \t%s\n", answer(testSort(in11, in12, n)));
    }
    
    
    {
        int in11[] = {1};
        int in12[] = {1};
        int n = sizeof(in11)/sizeof(in11[0]);
        printf("sort 3 \t%s\n", answer(testSort(in11, in12, n)));
    }
    
    {
        int in11[] = {2, 1};
        int in12[] = {2, 1};
        int n = sizeof(in11)/sizeof(in11[0]);
        printf("sort 5 \t%s\n", answer(testSort(in11, in12, n)));
    }
    
    {
        int in11[] = {-5, 6 -7, 1, 0};
        int in12[] = {-5, 6 -7, 1, 0};
        int n = sizeof(in11) / sizeof(in11[0]);
        printf("sort 6 \t%s\n", answer(testSort(in11, in12, n)));
    }
    
    {
        int in11[] = {4, 4, 1, 2, 1};
        int in12[] = {4, 4, 1, 2, 1};
        int n = sizeof(in11) / sizeof(in11[0]);
        printf("sort 6 \t%s\n", answer(testSort(in11, in12, n)));
    }
}

void testTime(const int *a_st, const int *a_end, const int sort_t)
{
    
    unsigned long long t_st, t_end, full_time = 0;
    int size = a_end - a_st;
    
    if (sort_t == 0)
        printf("\nBubble sort\n\n");
    else
        printf("\nQsort\n\n");
    
    for (int i = 0; i < N; ++i)
    {
        int *filtered = malloc(sizeof(int) * size);
        
        memcpy(filtered, a_st, size * sizeof(int));
        
        if (sort_t == 0)
        {
            t_st = tick();
            mysort(filtered, size, 4, compareInt);
            t_end = tick();
        }
        
        else
        {
            t_st = tick();
            qsort(filtered, size, 4, &compareInt);
            t_end = tick();
        }
        
        printf("test  %d 'time': \t%llu\n", i, (t_end - t_st));
        full_time = full_time + (t_end - t_st);
        
        free(filtered);
    }
    printf("\nAverage  time : \t%llu\n", full_time / N);
}

int main(int argc, char const *argv[])
{
    testKeySort();
    printf("\n");
    testMysort();
    return 0;
}
