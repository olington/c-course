#ifndef output_h
#define output_h

#include <stdio.h>
#include "list.h"

void printFromHead(const node_t *head, int count);
void printFromHeadToFile(const node_t *head, int count, FILE *f);

#endif /* output_h */
