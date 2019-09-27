#include <stdio.h>
#include "list.h"

/**
 Функция сравнения года выпуска альбома
 
 @param pa [in]
 @param pb [in]
 
 @return разница двух чисел
 */
int comporator_year(const void *pa, const void *pb)
{
    const disk *a = pa;
    const disk *b = pb;
    return  a->year - b->year;
}

/**
 Функция сравнения жанров
 
 @param pa [in]
 @param pb [in]
 
 @return результат сравнение двух слов
 */
int comporator_genre(const void *pa, const void * pb)
{
    const disk *a = pa;
    const disk *b = pb;
    return strcmp(a->genre, b->genre);
}

/**
 Функция сравнения исполнителей
 
 @param pa [in]
 @param pb [in]
 
 @return результат сравнение двух слов
 */
int comporator_artist(const void *pa, const void * pb)
{
    const disk *a = pa;
    const disk *b = pb;
    return strcmp(a->artist, b->artist);
}

/**
 Добавляет в односвязный список новый элемент
 
 @param head [in]
 @param new_elem [in]
 
 @return указатель на голову списка
 */
disk *addToList(disk *head, disk *new_elem)
{
    if (head)
    {
        disk *cur = NULL;
        for (cur = head; cur->next; cur = cur->next)
            ;
        cur->next = new_elem;
    }
    
    else
        head = new_elem;
    
    return head;
}

/**
 Добавляет новый элемент в отсортированный список
 
 @param data [in]
 @param head [in]
 @param comporator [in]
 
 @return ничего не возвращает
 */
void listAddSort(disk *data, struct list_head *head, int (*comporator)
                                 (const void *, const void *), int type_of_sort)
{
    struct list_head *cur_head;
    disk *cur = NULL;
    
    struct list_head *new = &data->sort[type_of_sort];
    
    list_for_each(cur_head, head)
    {
        cur = list_entry(cur_head, disk, sort[type_of_sort]);
        if (comporator(cur, data) > 0)
        {
            new->prev = cur_head->prev;
            cur_head->prev->next = new;
            new->next = cur_head;
            cur_head->prev = new;
            break;
        }
        
        else if (cur_head->next == head)
        {
            list_add_tail(new, head);
            break;
        }
    }
    
    if (!cur)
        list_add_tail(new, head);
}

/**
 Находит и выделяет целое число в строке
 
 @param str [in]
 @param substr [in]
 
 @return 0 - если вхождение найдено
 */
int stringSearch(char str[], char substr[])
{
    int k = 0;
    
    for (int i = 0; str[i] && substr[k] && (int)strlen(substr) - k; i++)
        if (str[i] == substr[k])
            k++;
        else
            k = 0;
    
    return (int)strlen(substr) - k;
}

/**
 Добавляет новый элемент в списки сортировки и фильтрации
 
 @param new_elem [in]
 @param mas_sort [in]
 @param mas_filter [in]
 
 @return ничего не возвращает
 */
void addSortAndFilter(disk *new_elem, struct list_head **mas_sort, struct list_head **mas_filter)
{
    listAddSort(new_elem, mas_sort[0], comporator_year, 0);
    listAddSort(new_elem, mas_sort[1], comporator_genre, 1);
    listAddSort(new_elem, mas_sort[2], comporator_artist, 2);
    
    if (new_elem->year >= YEAR)
        list_add_tail(&new_elem->filter[0], mas_filter[0]);
    
    if (!stringSearch(new_elem->genre, GENRE))
        list_add_tail(&new_elem->filter[1], mas_filter[1]);
}

/**
 Выводит отсортированный список
 
 @param mas_sort [in]
 @param sort_type [in]
 
 @return ничего не возвращает
 */
void sortDisk(struct list_head **mas_sort, int sort_type)
{
    struct list_head *cur_head;
    disk *cur = NULL;
    
    printf("\n%15s\t%12s\t%5s\n"
           "──────────────────────────────────────\n",
           "Genre", "Artist", "Year");
    int i = 0;
    list_for_each(cur_head, mas_sort[sort_type])
    {
        cur = list_entry(cur_head, disk, sort[sort_type]);
        printf("%2d. %11s\t%12s\t%5d\n", i++, cur->genre,
               cur->artist, cur->year);
    }
    if (!cur)
        printf("Error! List is empty\n");
}

/**
 Выводит отфильтрованный список
 
 @param mas_filter [in]
 @param filt_type [in]
 
 @return ничего не возвращает
 */
void filterDisk(struct list_head **mas_filter, int filt_type)
{
    struct list_head *iter;
    disk *cur = NULL;
    
    printf("\n%15s\t%12s\t%5s\n"
           "──────────────────────────────────────\n",
           "Genre", "Artist", "Year");
    
    int i = 0;
    
    list_for_each(iter, mas_filter[filt_type])
    {
        cur = list_entry(iter, disk, filter[filt_type]);
        printf("%2d. %11s\t%12s\t%5d\n", i++, cur->genre,
               cur->artist, cur->year);
    }
    
    if (!cur)
        printf("\nEmpty list\n");
}

/**
 Считывает данные из файла и добавляет в список
 
 @param filename [in]
 @param head [in]
 @param mas_sort [in]
 @param mas_filter [in]
 
 @return указатель на голову списка
 */
disk *importFromFile(const char filename[], disk *head, struct list_head **mas_sort,
                     struct list_head **mas_filter)
{
    disk *new_elem = NULL;
    
    FILE *file = fopen(filename, "r");
    
    if (!checkFile(file))
    {
        for (int i = 0, n = numStrings(file); i < n; i++)
        {
            new_elem = malloc(sizeof(disk));
            new_elem->next = NULL;
            readString(file, new_elem->genre);
            readString(file, new_elem->artist);
            readFromFile(file, &new_elem->year);
            head = addToList(head, new_elem);
            addSortAndFilter(new_elem, mas_sort, mas_filter);
        }
    }
    fclose(file);
    
    return head;
}

/**
 Добавляет в список новый элемент
 
 @param head [in]
 @param mas_sort [in]
 @param mas_filter [in]
 
 @return указатель на голову списка
 */
disk *addRecord(disk *head, struct list_head **mas_sort, struct list_head **mas_filter)
{
    disk *new_elem = malloc(sizeof(disk));
    new_elem->next = NULL;
    
    printf("Input genre: ");
    readString(stdin, new_elem->genre);
    
    printf("Input artist name: ");
    readString(stdin, new_elem->artist);
    
    scanInt(&new_elem->year, "Input year: ");
    
    head = addToList(head, new_elem);
    addSortAndFilter(new_elem, mas_sort, mas_filter);
    
    return head;
}

/**
 Выводит список
 
 @param head [in]
 
 @return ничего не возвращает
 */
void outputTable(disk *head)
{
    if (head)
    {
        printf("\n%15s\t%12s\t%5s\n"
               "──────────────────────────────────────\n",
               "Genre", "Artist", "Year");
        
        int i = 0;
        
        for (disk *cur = head; cur; cur = cur->next, i++)
            printf("%2d. %11s\t%12s\t%5d\n", i, cur->genre,
                   cur->artist, cur->year);
    }
    else
        printf("List is empty\n");
}

/**
 Поиск элемента в списке по индексу
 
 @param head [in]
 @param index [in]
 
 @return указатель на найденный элемент
 */
disk *searchByIndex(disk *head, int index)
{
    int i = 0;
    disk *cur = NULL;
    for (cur = head; cur->next && i < index; cur = cur->next, i++)
        ;
    
    return cur;
}

/**
 Удаляет элемент из списка сортировки
 
 @param cur [in]
 
 @return ничего не возвращает
 */
void deleteElemFromSort(disk *cur)
{
    for (int i = 0; i < MAX_SORT_INDX; i++)
        list_del(&cur->sort[i]);
}

/**
 Удаляет элемент из списка фильтра
 
 @param cur [in]
 
 @return ничего не возвращает
 */
void deleteElemFromFilter(disk *cur)
{
    for (int i = 0; i < MAX_FILTER_INDX; i++)
    {
        if (cur->filter[i].next)
            list_del(&cur->filter[i]);
    }
}

/**
 Удаляет элемент из списка
 
 @param head [in]
 @return [in]
 
 @return ничего не возвращает
 */
disk *deleteElem(disk *head)
{
    if (head)
    {
        int index, i = 0;
        
        disk *cur = NULL, *prev = NULL;
        
        scanInt(&index, "Input index to delete from list: ");
        
        for (cur = head; cur->next && i < index; cur = cur->next, i++)
            prev = cur;

        if (i == index)
        {
            deleteElemFromSort(cur);
            deleteElemFromFilter(cur);
            
            if (prev)
                prev->next = cur->next;
            else
                head = cur->next;
            free(cur);
        }
        else
            printf("Index not found\n");
    }
    else
        printf("List is empty\n");
    
    return head;
}

/**
 Изменение элемента списка
 
 @param head [in]
 @param mas_sort [in]
 @param mas_filter [in]
 
 @return ничего не возвращает
 */
void editElem(disk *head, struct list_head **mas_sort, struct list_head **mas_filter)
{
    if (head)
    {
        int choice, index;
        
        scanInt(&index, "Enter index to edit element from list: ");
        
        disk *cur = searchByIndex(head, index);
        
        do
            scanInt(&choice, "Select what to edit: \n1.Genre\n2.Artist\n3.Year\n");
        while (choice < 1 || choice > 3);
        
        deleteElemFromSort(cur);
        deleteElemFromFilter(cur);
        
        if (choice == 1)
        {
            printf("Input genre: ");
            readString(stdin, cur->genre);
        }
        
        else if (choice == 2)
        {
            printf("Input artist: ");
            readString(stdin, cur->artist);
        }
        
        else
            scanInt(&cur->year, "Input year: ");
        
        addSortAndFilter(cur, mas_sort, mas_filter);
    }
    
    else
        printf("Empty list\n");
}

/**
 Освобождает память
 
 @param head [in]
 
 @return ничего не возвращает
 */
void freeList(disk *head)
{
    if (head)
        for (disk *cur = head, *next = NULL; cur; cur = next)
        {
            next = cur->next; 
            free(cur);
        }
}

/**
 Сохраняет список в файле
 
 @param filename [in]
 @param head [in]
 
 @return ничего не возвращает
 */
void saveData(const char filename[], disk *head)
{
    FILE *file = fopen(filename, "w");
    
    for (disk *cur = head; cur; cur = cur->next)
        fprintf(file, "%s; %s; %d\n", cur->genre, cur->artist, cur->year);
    
    fclose(file);
}
