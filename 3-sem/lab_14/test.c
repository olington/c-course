#include <stdio.h>
#include "queue.h"
#include "test_queue.h"

int main()
{
    if (!testDequeue() && !testEnqueueDequeue() && !testEnqueue())
        printf("Tests are passed\n");

    else
        puts("Tests are not passed\n");

    return 0;
}
