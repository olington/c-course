#include "test.h"

/**
 Тестирование функции popFront
 
 @return ничего не возвращает
 */
void popFrontTest()
{
    int flag = 1;
    
    FILE *f = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/in1.txt", "r");
    node_t *list = NULL;
    readList(&list, f);
    int *x = popFront(&list);
    if (*x != 7)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    
    x = popFront(&list);
    if (*x != 1)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    
    x = popFront(&list);
    if (*x != 2)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    fclose(f);
    
    if (flag == 1)
        printf("Test popFront: PASSED");
    else
        printf("Test popFront: NOT PASSED");
}

/**
 Тестирование функции popBack
 
 @return ничего не возвращает
 */
void popBackTest()
{
    int flag = 1;
    FILE *f = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/in1.txt", "r");
    
    node_t *list = NULL;
    readList(&list, f);
    int *x = popBack(&list);
    
    if (*x != 8)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    
    x = popBack(&list);
    if (*x != 3)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    
    x = popBack(&list);
    if (*x != 4)
    {
        printf("%d\n", *x);
        flag = 0;
    }
    
    if (flag == 1)
        printf("\nTest popBack: PASSED");
    else
        printf("\nTest popBack: NOT PASSED");
}

/**
 Сравнивает два списка
 
 @param list [in]
 @param res [in]
 
 @return 1, если списки совпадают, 0 - иначе
 */
int check(node_t **list, node_t **res)
{
    int flag = 1;
    
    while ((*list)->next && (*res)->next)
    {
        int *x = popBack(list), *y = popBack(res);
        if (*x != *y)
            flag = 0;
    }
    return flag;
}

/**
 Тестирование функции sort
 
 @return ничего не возвращает
 */
void sortTest()
{
    int flag1 = 0, flag2 = 0, flag3 = 0;
    
    FILE *f1 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/in1.txt", "r");
    FILE *f2 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/in4.txt", "r");
    FILE *f3 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/in5.txt", "r");
    
    FILE *f11 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/out4.txt", "r");
    FILE *f22 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/out5.txt", "r");
    FILE *f33 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/out6.txt", "r");
    
    if (f1 && f2 && f3 && f11 && f22 && f33)
    {
        node_t *res1 = NULL, *res2 = NULL, *res3 = NULL;
        readList(&res1, f11);
        readList(&res2, f22);
        readList(&res3, f33);
        
        node_t *list1 = NULL;
        readList(&list1, f1);
        
        node_t *list2 = NULL;
        readList(&list2, f2);
        
        node_t *list3 = NULL;
        readList(&list3, f3);
        
        node_t *out1 = NULL;
        out1 = sort(list1, comparatorInt);
        flag1 = check(&out1, &res1);
        
        node_t *out2 = NULL;
        out2 = sort(list2, comparatorInt);
        flag2 = check(&out2, &res2);
        
        node_t *out3 = NULL;
        out3 = sort(list3, comparatorInt);
        flag3 = check(&out3, &res3);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f11);
    fclose(f22);
    fclose(f33);
    
    if (flag1 + flag2 + flag3 == 3)
        printf("\nTest sort: PASSED");
    else
        printf("\nTest sort: NOT PASSED");
}

/**
 Тестирование функции append
 
 @return ничего не возвращает
 */
void appendTest()
{
    int flag1 = 0, flag2 = 0, flag3 = 0;
    
    FILE *f1 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/in1.txt", "r");
    FILE *f2 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/in4.txt", "r");
    FILE *f3 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/in5.txt", "r");
    
    FILE *f11 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/out1.txt", "r");
    FILE *f22 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/out2.txt", "r");
    FILE *f33 = fopen("/Users/olga/Documents/C/3-sem/lab_10/lab_10/files/out3.txt", "r");
    
    if (f1 && f2 && f3 && f11 && f22 && f33)
    {
        node_t *res1 = NULL, *res2 = NULL, *res3 = NULL;
        
        readList(&res1, f11);
        readList(&res2, f22);
        readList(&res3, f33);
        
        node_t *list1 = NULL;
        readList(&list1, f3);
        node_t *list2 = NULL;
        readList(&list2, f2);
        appendList(&list1, &list2);
        flag1 = check(&list1, &res1);
        
        list1 = NULL;
        readList(&list1, f2);
        list2 = NULL;
        readList(&list2, f3);
        appendList(&list1, &list2);
        flag2 = check(&list1, &res2);
        
        list1 = NULL;
        readList(&list1, f1);
        list2 = NULL;
        readList(&list2, f3);
        appendList(&list1, &list2);
        flag3 = check(&list1, &res3);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f11);
    fclose(f22);
    fclose(f33);

    if (flag1 + flag2 + flag3 == 3)
        printf("\nTest append: PASSED\n");
    else
        printf("\nTest append: NOT PASSED\n");
}

int main(int argc, char **argv)
{
    popFrontTest();
    popBackTest();
    sortTest();
    appendTest();
    
    return 0;
}
