#include <stdio.h>
#include <math.h>

int entarance(int a)
{
    int ent;
    ent = (a-1)/27 + 1;
    return ent;
}

int flo(int a)
{
    int f;
    f = ((a-1)%27)/3 + 1;
    return f;
}

int main()
{
    int a, ent, f;
    
    printf("Aparyment: ");
    scanf("%d", &a);
    
    ent = entarance(a);
    f = flo(a);
    
    printf("%d%d", ent, f);
    return 0;
}

