#include <stdio.h>

void print_m (int l, int c, double  m[2][2]);
void quad_mat (double m[2][2]);
void read_m (int l, int c, double  m[2][2]);


int main (void)
{
    double m[2][2];
    read_m (2,2,m);

    quad_mat (m);

    print_m (2,2,m);

    return 0;
}

void print_m (int l, int c, double  m[2][2])
{
    int al, ac;
    for (al=0;al<l;al++)
    {
        for (ac=0;ac<c;ac++)
        {
            printf("%.3lf ", m[al][ac]);
        }
        printf("\n");
    }
    return;
}

void read_m (int l, int c, double  m[2][2])
{
    int al, ac;
    for (al=0;al<l;al++)
    {
        for (ac=0;ac<c;ac++)
        {
            scanf("%lf", &m[al][ac]);
        }
    }
    return;
}

void quad_mat (double m[2][2])
{
    int u, d, t, q;
    u = m[0][0];
    d = m[0][1];
    t = m[1][0];
    q = m[1][1];

    m[0][0] = u*u + d*t;
    m[0][1] = d*u + d*q;
    m[1][0] = t*u + q*t;
    m[1][1] = t*d + q*q;

    return;
}