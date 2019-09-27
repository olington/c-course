#include "main.h"

int main(int argc, const char * argv[])
{
    enum ERRORS status_work = OK;
    
    if (argc != 2)
    {
        printf("Invalid num of args in command line ./app.exe [file.txt]\n");
        return ERROR_COMMAND_LINE;
    }
    
    disk *head = NULL;
    LIST_HEAD(sort_by_year);
    LIST_HEAD(sort_by_genre);
    LIST_HEAD(sort_by_artist);
    struct list_head *mas_sort[MAX_SORT_INDX] = {&sort_by_year, &sort_by_genre, &sort_by_artist};
    
    LIST_HEAD(filter_by_year);
    LIST_HEAD(filter_by_genre);
    struct list_head *mas_filter[MAX_FILTER_INDX] = {&filter_by_year, &filter_by_genre};
    
    int menu, process = 1, imported = 0;
    while (process)
    {
        printf("\nMenu:\n"
               "1. Load from file\n"
               "2. Add new record\n"
               "3. Delete record by index\n"
               "4. Edit record by index\n"
               "5. Print table\n"
               "6. Sort by year\n"
               "7. Sort by genre\n"
               "8. Sort by artist name\n"
               "9. Filter by year after 1990\n"
               "10. Filter by genre 'Rock'\n"
               "11: Exit\n"
               "\nInput option: ");
        
        scanInt(&menu, "");
        
        switch(menu)
        {
            case 1:
                if (imported)
                    printf("List is already loaded from file\n");
                else
                {
                    head = importFromFile(argv[1], head, mas_sort, mas_filter);
                    imported = 1;
                }
                break;
            case 2:
                head = addRecord(head, mas_sort, mas_filter);
                break;
            case 3:
                head = deleteElem(head);
                break;
            case 4:
                editElem(head, mas_sort, mas_filter);
                break;
            case 5:
                outputTable(head);
                break;
            case 6:
                sortDisk(mas_sort, 0);
                break;
            case 7:
                sortDisk(mas_sort, 1);
                break;
            case 8:
                sortDisk(mas_sort, 2);
                break;
            case 9:
                filterDisk(mas_filter, 0);
                break;
            case 10:
                filterDisk(mas_filter, 1);
                break;
            case 11: process = 0;
                break;
                
            default: puts("Enter num from 0 to 10\n");
        }
    }
    
    scanInt(&menu, "Do you want to save changes in output file? 0 - no, 1 - yes\n");
    
    if (menu)
        saveData(argv[1], head);
    
    freeList(head);
    
    return status_work;
}
