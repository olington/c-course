#include <stdlib.h>
#include "queue.h"

typedef struct node
{
    int elem;
    struct node *next;
}node_t;

struct queue
{
    node_t *head;
    node_t *tail;
    int size;
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
    q_new->tail = NULL;
    q_new->head = q_new->tail;
    q_new->size = 0;
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
    if (q->size == MAX_SIZE)
        size = MAX_SIZE;

    if (q->size == 0)
    {
        q->tail = malloc(sizeof(node_t));
        q->head = q->tail;
    }

    else
    {
        q->tail->next = malloc(sizeof(node_t));
        q->tail = q->tail->next;
    }

    q->tail->elem = val;
    q->tail->next = NULL;
    (q->size)++;

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
    int val = 0;

    if (q->size != 0)
    {
        val = q->head->elem;
        node_t *tmp = q->head;
        q->head = q->head->next;
        free(tmp);
        (q->size)--;
    }
    return val;
}

/**
 Создает пустую очередь (начало и конец совпадают)

 @param q [in]
 @param q->tail [out]

 @return указатель на конец очереди
 */
int emptyQueue(queue_t *q)
{
    return q->size == 0;
}

/**
Освобождает очередь

 @param q [in]

 @return ничего не возвращает
 */
void freeQueue(queue_t *q)
{
    while (q->size != 0)
        dequeue(q);

    free(q);
}