#include <stdio.h>
#include <math.h>

void triangle_exists(double a, double b, double c)
{
    if (((a+b)>c) && ((a+c)>b) && ((b+c)>a))
    {
        printf("triangle exists");
    }
    else
    {
        printf("triangle doesn't exist");
    }
}

int main()
{
    double x1,y1,x2,y2,x3,y3;
    double a, b, c;
    
    printf("Введите координаты x1, y1: ");
    scanf("%lf", &x1);
    scanf("%lf", &y1);
    printf("\nВведите координаты x2, y2: ");
    scanf("%lf", &x2);
    scanf("%lf", &y2);
    printf("\nВведите координаты x3, y3: ");
    scanf("%lf", &x3);
    scanf("%lf", &y3);
    
    a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    b = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
    c = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1));
    
    triangle_exists(a,b,c);
    
    return 0;
}
