#include <stdio.h>
#define nmax 10

void read_m (int l, int c, double  m[nmax][nmax])
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

void print_m (int l, int c, double  m[nmax][nmax])
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

int main (void) {
    int n, k;
    double m[nmax][nmax];

    scanf("%d\n%d", &n, &k);

    read_m (n,n,m);

    print_m (n,n,m);
}