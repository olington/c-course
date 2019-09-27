#ifndef test_h
#define test_h

#include <stdio.h>
#include "list.h"
#include "read_list.h"
#include "push.h"
#include "pop.h"
#include "sort.h"
#include "append.h"
#include "output.h"

void popFrontTest(void);
void popBackTest(void);
int check(node_t **list, node_t **res);
void sortTest(void);
void appendTest(void);

#endif /* test_h */
