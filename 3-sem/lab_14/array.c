#include <stdlib.h>
#include "queue.h"

struct queue
{
    int val[MAX_SIZE];
    int head;
    int tail;
};

/**
 Инициализирует очередь.

 @param q [in]

 @return ничего не возвращает
 */
void initQueue(queue_t **q)
{
    queue_t *q_new;
    q_new = malloc(sizeof(queue_t));
    q_new->head = 0;
    q_new->tail = 0;
    *q = q_new;
}

/**
 Добавляет элемент в очередь.

 @param q [in]
 @param val [in]
 @param size [out]

 @return длину очереди
 */
int enqueue(queue_t *q, int val)
{
    int size = 0;
    if ((q->tail - q->head) == MAX_SIZE)
        size = MAX_SIZE;

    else if (q->tail == MAX_SIZE)
    {
        for (int i = q->head; i < q->tail; i++)
            q->val[i] = q->val[i + q->tail - q->head];

        if ((q->tail - q->head) == MAX_SIZE)
            size = MAX_SIZE;
    }

    if (size != MAX_SIZE)
    {
        q->val[q->tail] = val;
        q->tail++;
    }
    return size;
}

/**
 Удаляет элемент из очереди

 @param q [in]
 @param val [out]

 @return удаленное значение
 */
int dequeue(queue_t *q)
{
    int value = 0;

    if (q->tail != q->head)
    {
        value = q->val[q->head];
        (q->head)++;

        if (q->tail != q->head)
        {
            q->head = 0;
            q->tail = 0;
        }
    }
    return value;
}

/**
 Создает пустую очередь (начало и конец совпадают)

 @param q [in]
 @param q->tail [out]

 @return указатель на конец очереди
 */
int emptyQueue(queue_t *q)
{
    return q->tail == q->head;
}

/**
Освобождает очередь

 @param q [in]

 @return ничего не возвращает
 */
void freeQueue(queue_t *q)
{
    free(q);
}
