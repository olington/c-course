#ifndef LAB_14_QUEUE_H
#define LAB_14_QUEUE_H

#define MAX_SIZE 7

typedef struct queue queue_t;

void initQueue(queue_t **q);
void freeQueue(queue_t *q);
int emptyQueue(queue_t *q);
int enqueue(queue_t *q, int val);
int dequeue(queue_t *q);

#endif //LAB_14_QUEUE_H
