#include "sort.h"

/**
 Сравнивает два элемента val1 и val2.
 
 @param val1 [in]
 @param val2 [in]
 
 @return возвращает разность val1 и val2.
 */

int comparatorInt(const void *val1, const void *val2)
{
    const int *a = val1;
    const int *b = val2;
    return *a - *b;
}

/**
 Определяет, куда нужно вставить элемент (elem) в упорядоченный список (head)
 
 @param head [in]
 @param elem [in]
 @param comparator [in]
 
 @return ничего не возвращает
 */
void insertSort(node_t **head, node_t *elem, int (*comparator)(const void *, const void *))
{
    node_t *ptr = NULL;
    node_t *tmp = NULL;
    unsigned char flag = 0;
    void *x = elem->data;
    
    if (comparator(elem->data, (*head)->data) >= 0)
    {
        ptr = (node_t *)malloc(sizeof(node_t));
        ptr->data = x;
        ptr->next = (*head);
        *head = ptr;
    }
    
    else
    {
        tmp = (*head);
        while ((flag == 0) && (tmp->next != NULL))
        {
            if (comparator(tmp->data, tmp->next->data) >= 0 &&
                comparator(elem->data, tmp->next->data) > 0)
                flag = 1;
        
            if (flag != 1)
                tmp = tmp->next;
            
        }
        if (flag == 0)
        {
            ptr = malloc(sizeof(node_t));
            ptr->data = x;
            ptr->next = NULL;
            tmp->next = ptr;
        }
        
        else
        {
            ptr = malloc(sizeof(node_t));
            ptr->data = x;
            ptr->next = tmp->next;
            tmp->next = ptr;
        }
    }
}

/**
 Сортировка вставками. Упорядочивает список по возрастанию, используя функцию insertSort.
 
 @param head [in]
 @param comparator [in] - функция сравнения
 @param sorted [out] - упорядоченный список
 
 @return упорядоченный список
 */
node_t* sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *sorted = NULL;
    if (head != NULL)
    {
        void *first = popBack(&head);
        int flag = 0;
        push(&sorted, first);
        
        if (head->next == NULL)
            flag = 1;
        
        while (head->next)
        {
            node_t *next = head;
            insertSort(&sorted, next, comparator);
            head = head->next;
        }
        
        if (flag != 1)
        {
            node_t *next = head;
            insertSort(&sorted, next, comparator);
        }
    }
    return sorted;
}
