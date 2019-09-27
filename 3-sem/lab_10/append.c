#include "append.h"

/**
 Добавляет второй список в конец первого, очищая при этом второй список
 
 @param head_first [in]
 @param head_second [in]
 
 @return ничего не возвращает
 */
void appendList(node_t **head_first, node_t **head_second)
{
    node_t *tmp = *head_second;
    
    while (tmp->next)
    {
        void *x = popFront(&tmp);
        push(head_first, x);
    }
    
    void *x = popBack(&tmp);
    push(head_first, x);
    *head_second = NULL;
}
