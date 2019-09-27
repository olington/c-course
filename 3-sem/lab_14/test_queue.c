#include "test_queue.h"

/**
 Тестирует enqueue

 @return 0, если тест пройден успешно, 1 - иначе
 */
int testEnqueue()
{
    int res = 0;
    int val = 7;

    queue_t *q;
    initQueue(&q);

    if (q == NULL)
    {
        puts("Creating queue error\n");
        res = 1;
    }

    for (int i = 0; i < MAX_SIZE; i++)
    {
        int res = enqueue(q, val);
        if (res != 0)
        {
            puts("Testing enqueue error\n");
            freeQueue(q);
            res = 1;
        }
    }
    int result = enqueue(q, val);
    freeQueue(q);

    if (result != MAX_SIZE)
    {
        puts("Testing enqueue error\n");
        res = 1;
    }
    return res;
}

/**
 Тестирует dequeue

 @return 0, если тест пройден успешно, 1 - иначе
 */
int testDequeue()
{
    int res = 0;

    queue_t *q;
    initQueue(&q);

    if (q == NULL)
    {
        puts("Creating queue error\n");
        res = 1;
    }

    dequeue(q);
    freeQueue(q);

    if (!emptyQueue(q))
    {
        puts("Empty queue\n");
        res = 1;
    }
    return res;
}

/**
 Тестирует enqueue и dequeue

 @return 0, если тест пройден успешно, 1 - иначе
 */
int testEnqueueDequeue()
{
    int res = 0;
    int pushed = 7, popped = 0, result_push = 0;
    queue_t *q;
    initQueue(&q);
    if (q == NULL)
    {
        puts("Creating queue error\n");
        res = 1;
    }

    result_push = enqueue(q, pushed);
    popped = dequeue(q);
    freeQueue(q);

    if (result_push != 0 || pushed != popped)
    {
        puts("Testing enqueue and dequeue error\n");
        res = 1;
    }

    return res;
}