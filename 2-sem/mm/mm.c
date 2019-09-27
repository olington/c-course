#include <stdio.h>
#include <math.h>

int metres(int mm)
{
    int m;
    m = mm / 100;
    return m;
}

int smetres(int mm)
{
    int sm;
    sm = mm % 100;
    return sm;
}

int main()
{
    int mm, sm, m;
    
    printf("Distance: ");
    scanf("%d", &mm);
    
    m = metres(mm);
    sm = smetres(mm);
    
    printf("%d%d", m, sm);
    return 0;
}
