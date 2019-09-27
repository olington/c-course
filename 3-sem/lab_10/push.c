#include "push.h"

/**
 Добавляет элемент в список
 
 @param head [in]
 @param elem [in]
 
 @return ничего не возвращает
 */
void push(node_t **head, void *elem)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = elem;
    node->next = *head;
    *head = node;
}

/**
 Добавляет элемент в список
 
 @param head [in]
 @param elem [in]
 
 @return ничего не возвращает
 */
void push_val(values_t **head, int elem)
{
    values_t *node = (values_t *)malloc(sizeof(values_t));
    node->data = elem;
    node->next = *head;
    *head = node;
}
