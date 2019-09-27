#include "test.h"

/**
 Тестирование функции сортировки

 @return код ошибки
 */
int testSort()
{
    enum ERRORS err = OK;
    
    LIST_HEAD(sort_by_year);
    LIST_HEAD(sort_by_genre);
    LIST_HEAD(sort_by_artist);
    struct list_head *mas_sort[MAX_SORT_INDX] = {&sort_by_year, &sort_by_genre, &sort_by_artist};
    
    LIST_HEAD(sort_by_year1);
    LIST_HEAD(sort_by_genre1);
    LIST_HEAD(sort_by_artist1);
    struct list_head *mas_sort1[MAX_SORT_INDX] = {&sort_by_year1, &sort_by_genre1, &sort_by_artist1};
    
    LIST_HEAD(filter_by_year);
    LIST_HEAD(filter_by_genre);
    struct list_head *mas_filter[MAX_FILTER_INDX] = {&filter_by_year, &filter_by_genre};
    
    disk *head_to_sort = NULL, *head_result = NULL;
    head_to_sort = importFromFile("/Users/olga/Documents/in2.txt", head_to_sort, mas_sort, mas_filter);
    head_result = importFromFile("/Users/olga/Documents/out2.txt", head_result, mas_sort1, mas_filter);
    
    struct list_head *iter;
    disk *cur_to_sort = NULL, *cur_result = head_result;
    list_for_each(iter, mas_sort[0])
    {
        cur_to_sort = list_entry(iter, disk, sort[0]);
        if (cur_to_sort->year != cur_result->year)
            err = ERROR_TESTING_SORT;
        if (cur_result->next)
            cur_result = cur_result->next;
    }
    
    return err;
}

/**
 Тестирование функции фильтра

 @return код ошиюки
 */
int testFilter()
{
    enum ERRORS err = OK;
    LIST_HEAD(sort_by_year);
    LIST_HEAD(sort_by_genre);
    LIST_HEAD(sort_by_artist);
    struct list_head *mas_sort[MAX_SORT_INDX] = {&sort_by_year, &sort_by_genre, &sort_by_artist};
    
    LIST_HEAD(filter_by_year);
    LIST_HEAD(filter_by_genre);
    struct list_head *mas_filter[MAX_FILTER_INDX] = {&filter_by_year, &filter_by_genre};
    
    LIST_HEAD(filter_by_year1);
    LIST_HEAD(filter_by_genre1);
    struct list_head *mas_filter1[MAX_FILTER_INDX] = {&filter_by_year1, &filter_by_genre1};
    
    disk *head_to_filter = NULL, *head_result = NULL;
    head_to_filter = importFromFile("/Users/olga/Documents/in3.txt", head_to_filter, mas_sort, mas_filter);
    head_result = importFromFile("/Users/olga/Documents/out3.txt", head_result, mas_sort, mas_filter1);
    
    struct list_head *iter;
    disk *cur_to_sort = NULL, *cur_result = head_result;
    list_for_each(iter, mas_filter[0])
    {
        cur_to_sort = list_entry(iter, disk, filter[0]);
        if (cur_to_sort->year != cur_result->year)
            err = ERROR_TESTING_FILTER;
        if (cur_result->next)
            cur_result = cur_result->next;
    }
    
    return err;
}

int main(void)
{
    enum ERRORS err = OK;

    err = testSort();
    if (!err)
        printf("Tests are passed\n");
    else
        printf("Tests are not passed\n");
    printf("\n");

    err = testFilter();
    if (!err)
        printf("Tests are passed\n");
    else
        printf("Tests are not passed\n");
    printf("\n");
    
    return err;
}
