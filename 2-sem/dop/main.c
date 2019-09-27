#include<stdio.h>
#include<math.h>

struct parall
{
    int xl_1;
    int yl_1;
    int xr_1;
    int yr_1;
    int xl_2;
    int yl_2;
    int xr_2;
    int yr_2;
    int angle;
};

struct trapeze
{
    int found;
    int d;
    int xl;
    int yl;
    int xr;
    int yr;
};

struct ellips
{
    int x;
    int y;
    int a_k;
    int kf;
    int x1_rect;
    int y1_rect;
    int x2_rect;
    int y2_rect;
};

void parall_square(FILE *f)
{
    FILE *fig = fopen("figure1.txt", "w");
    int ct2;
    struct parall p[10];
    fscanf(f, "%d", &ct2);
    for (int i = 0; i < ct2; i++)
        fscanf(f, "%d%d%d%d%d%d%d%d", &p[i].xl_1, &p[i].yl_1, &p[i].xr_1, &p[i].yr_1, &p[i].xl_2, &p[i].yl_2, &p[i].xr_2, &p[i].yr_2, &p[i].angle);
    for (int i = 0; i < ct2; i++)
    {
        float s = sin(p[i].angle) * 0.5
        * sqrt((p[i].yl_1 - p[i].yr_1) * (p[i].yl_1 - p[i].yr_1) +(p[i].xl_1 - p[i].xr_1) *(p[i].xl_1 - p[i].xr_1)) *
        sqrt((p[i].yl_2 - p[i].yr_2) * (p[i].yl_2 - p[i].yr_2) + (p[i].xl_2 - p[i].xr_2) * (p[i].xl_2 - p[i].xr_2));
        fprintf(fig, "Square of parallelogram: %f ", s);
    }
    fprintf(fig, "\n");
    fclose(fig);
}

void trapeze_square(FILE *f)
{
    FILE *fig = fopen("figure1.txt", "w");
    int ct1, ct2, ct3;
    struct trapeze t[10];
    fscanf(f, "%d", &ct3);
    for (int i = 0; i < ct2; i++)
        fscanf(f, "%d%d%d%d%d%d", &t[i].found, &t[i].d, &t[i].xl, &t[i].yl, &t[i].xr, &t[i].yr);
    for (int i = 0; i < ct1; i++)
    {
        float s = 0.5 * fabs(t[i].yl - t[i].yr) * (t[i].found + fabs(t[i].xl - t[i].xr));
        fprintf(fig, "Square of trapeze: %f ", s);
    }
    fclose(fig);
}

void ellips_square(FILE *f)
{
    FILE *fig = fopen("figure1.txt", "w");
    int ct1, ct2, ct3;
    struct ellips e[10];    float pi = 3.14;
    fscanf(f, "%d", &ct1);
    for (int i = 0; i < ct1; i++)
    {
        fscanf(f, "%d%d%d%d%d%d%d%d", &e[i].x, &e[i].y, &e[i].a_k, &e[i].kf, &e[i].x1_rect, &e[i].y1_rect, &e[i].x2_rect, &e[i].y2_rect);
    }
    for (int i = 0; i < ct1; i++)
    {
        float s = pi * e[i].a_k * (e[i].a_k / e[i].kf);
        fprintf(fig, "Square of ellips: %f ", s);
    }
    fprintf(fig, "\n");
    fclose(fig);
}

int main()
{
    FILE *f = fopen("figure1.txt", "r");
    parall_square(f);
    trapeze_square(f);
    ellips_square(f);
    fclose(f);
    return 0;
}
