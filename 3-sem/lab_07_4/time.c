#include "time.h"


unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d));
    return d;
}

void testing(const int *a_st, const int *a_end, const int sort_t)
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
