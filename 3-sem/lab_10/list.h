#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node_t;
struct node {
    void *data;
    node_t *next;
};

typedef struct node_val values_t;
struct node_val
{
    int data;
    values_t *next;
};

#endif /* list_h */
