#include "pop.h"

/**
 Возвращает значение головы списка
 
 @param head [in]
 @param data [out]
 
 @return значение головы списка
 */
void *popFront(node_t **head)
{
    node_t *cur = *head;
    while (cur->next->next != NULL)
        cur = cur->next;
    void *data = cur->next->data;
    cur->next = NULL;
    return data;
}

/**
 Возвращает значение хвоста списка
 
 @param head [in]
 @param data [out]
 
 @return значение хвоста списка
 */
void *popBack(node_t **head)
{
    node_t *temp = *head;
    void *data = temp->data;
    *head = temp->next;
    free(temp);
    return data;
}
