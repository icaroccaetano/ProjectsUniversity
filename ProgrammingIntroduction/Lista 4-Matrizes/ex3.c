#include <stdio.h>
#define nmax 1000

void read_m (int l, int c, int  m[nmax][nmax])
{
    int al, ac;
    for (al=0;al<l;al++)
    {
        for (ac=0;ac<c;ac++)
        {
            scanf("%d", &m[al][ac]);
        }
    }
    return;
}

int main (void)
{
    int m[nmax][nmax], i, n, l, c;

    scanf("%d", &n);

    read_m  (n,n,m);

    c = n-1;
    //impressao da diagonal secundaria
    for (l=0;l<n;l++)
    {
        printf("%d\n", m[l][c]);
        c--;
    }
    return 0;
}