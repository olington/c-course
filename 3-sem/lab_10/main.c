#include "list.h"
#include "read_list.h"
#include "push.h"
#include "pop.h"
#include "sort.h"
#include "append.h"
#include "output.h"

int main(int argc, char **argv)
{
    int status_work = 0;
    
    if (argc <= 3)
        printf("Arg error\n");
    
    else
    {
        FILE *fin = fopen(argv[2], "r");
        FILE *fout = fopen(argv[3], "w");
        
        node_t *list = NULL;
        list = readList(&list, fin);
        
        if (argc == 4 && !strcmp(argv[1], "f"))
        {
            int *x = popFront(&list);
            printf("%d\n", *x);
            fprintf(fout, "%d\n", *x);
        }
        
        else if (argc == 4 && !strcmp(argv[1], "b"))
        {
            int *x = popBack(&list);
            printf("%d\n", *x);
            fprintf(fout, "%d\n", *x);
        }
        
        else if (argc == 4 && !strcmp(argv[1], "s"))
        {
            node_t *sorted = NULL;
            sorted = sort(list, comparatorInt);
            printFromHead(sorted, 0);
            printFromHeadToFile(sorted, 0, fout);
        }
        
        else if (argc == 5 && !strcmp(argv[1], "a"))
        {
            FILE *fin2 = fopen(argv[4], "r");
            
            if (fin2)
            {
                node_t *list2 = NULL;
                readList(&list2, fin2);
                appendList(&list, &list2);
                printFromHead(list, 0);
                printFromHeadToFile(list, 0, fout);
            }
            
            fclose(fin2);
        }
        
        else if (argc == 5 && !strcmp(argv[1], "t"))
        {
            FILE *fin2 = fopen(argv[4], "r");
            
            if (fin2)
            {
                node_t *list2 = NULL;
                readList(&list2, fin2);
                appendList(&list, &list2);
                node_t *sorted = NULL;
                sorted = sort(list, comparatorInt);
                printFromHead(sorted, 0);
                printFromHeadToFile(sorted, 0, fout);
            }
            
            fclose(fin2);
        }
        
        else
            status_work = -1;
        
        fclose(fin);
        fclose(fout);
    }
    
    return status_work;
}
