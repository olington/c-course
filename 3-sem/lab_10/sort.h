#ifndef sort_h
#define sort_h

#include <stdio.h>
#include "list.h"
#include "push.h"
#include "pop.h"

int comparatorInt(const void *val1, const void *val2);
void insertSort(node_t **head, node_t *elem, int (*comparator)(const void *, const void *));
node_t* sort(node_t *head, int (*comparator)(const void *, const void *));

#endif /* sort_h */

