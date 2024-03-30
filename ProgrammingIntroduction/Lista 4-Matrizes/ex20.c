#include <stdio.h>
#define nmax 1000

void print_m (int l, int c, int  m[nmax][nmax])
{
    int al, ac;
    for (al=0;al<l;al++)
    {
        for (ac=0;ac<c;ac++)
        {
            printf("%d ", m[al][ac]);
        }
        printf("\n");
    }
}

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

void swap (int *a, int *b)
{   
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    return;
}

void swap_bs (int l, int c, int  m[nmax][nmax])
{
    int b, s, cl, cc, cs, cb, ls, lb;

    b = m[0][0];
    s = m[0][0];
    cs=0;
    cb=0;
    ls=0;
    lb=0;

    for (cl=0;cl<l;cl++)
    {
        for (cc=0;cc<c;cc++)
        {
            if (m[cl][cc]<s) 
            {
                cs = cc;
                ls = cl;
                s = m[cl][cc];
            }
            if (m[cl][cc]>b) 
            {
                cb = cc;
                lb = cl;
                b = m[cl][cc];
            }
        }
    }
    swap (&m[ls][cs],&m[lb][cb]);
    return;
}

int main (void) {
    int m[nmax][nmax];
    int l, c;
    scanf("%d %d", &l, &c);

    read_m (l,c,m);

    swap_bs(l,c,m);

    print_m (l,c,m);    
    return 0;
}