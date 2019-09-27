#include "output.h"

/**
 Печатает список с головы
 
 @param head [in]
 @param count [in]
 
 @return ничего не возвращает
 */
void printFromHead(const node_t *head, int count)
{
    if (head)
    {
        printFromHead(head->next, ++count);
        int *x = head->data;
        printf("%d ", *x);
    }
    
    else
    {
        if (count == 0)
            puts("\nList is empty\n");
    }
}

/**
 Печатает список с головы в файл
 
 @param head [in]
 @param count [in]
 @param f [in]
 
 @return ничего не возвращает
 */
void printFromHeadToFile(const node_t *head, int count, FILE *f)
{
    if (head)
    {
        printFromHeadToFile(head->next, ++count, f);
        int *x = head->data;
        fprintf(f, "%d ", *x);
    }
    
    else
    {
        if (count == 0)
            puts("\nList is empty\n");
    }
}
