#include "output.h"

void printInFile(const int *array, const int *array_end, FILE *file)
{
    while (array != array_end)
    {
        fprintf(file, "%d ", *array);
        array++;
    }
}
