#include "read_list.h"

/**
 Считывает список из файла
 
 @param head in]
 @param f [in]
 
 @return указатель на голову списка
 */
node_t *readList (node_t **head, FILE *f)
{
    rewind(f);
    int i = 0;
    values_t *read = NULL;
    while(!feof(f))
    {
        int j = 0;
        fscanf(f, "%d", &j);
        push_val(&read, j);
        push(head, &(read->data));
        i++;
    }
    
    return *head;
}
