#include <stdio.h>
#define nmax 1000

void read_m (int l, int c, int  m[nmax][nmax]);
void print_m (int l, int c, int  m[nmax][nmax]);
void vect_m (int l, int c, int v[nmax],int m[nmax][nmax]);
void order_vect (int v[nmax], int n);
void vect_mat (int v[nmax], int m[nmax][nmax], int n);
void swap (int *a, int *b);

int main (void)
{
    int n, m[nmax][nmax], v[nmax];

    scanf("%d", &n);

    read_m      (n,n,m);
    vect_m      (n,n,v,m);
    order_vect  (v,n);
    vect_mat    (v,m,n);
    print_m     (n,n,m);

    return 0;
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
    return;
}

void vect_m (int l, int c, int v[nmax],int m[nmax][nmax])
{
    int al, ac, i;
    i=0;
    for (al=0;al<l;al++)
    {
        for (ac=0;ac<c;ac++)
        {
            v[i] = m[al][ac];
            i++;
        }
    }
    return;
}

void order_vect (int v[nmax], int n)
{
    int i, j, im;

    for (i=0;i<((n*n));i++)
    {
        im = i;
        for (j=i+1;j<((n*n));j++)
        {
            if (v[j]<v[im]) {im=j;}
        }
        swap (&v[i], &v[im]);
    }
    return;
}

void vect_mat (int v[nmax], int m[nmax][nmax], int n)
{
    int al, ac, i;
    i=0;
    for (al=0;al<n;al++)
    {
        for (ac=0;ac<n;ac++)
        {
            m[al][ac] = v[i];
            i++;
        }
    }
}

void swap (int *a, int *b) 
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    return;
}