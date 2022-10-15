#include <stdio.h>
#define nmax 100

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

void init_m (int l, int c, int  m[nmax][nmax])
{
    int al, ac;
    for (al=0;al<l;al++)
    {
        for (ac=0;ac<c;ac++)
        {
            m[al][ac] = 0;
        }
    }
    return;
}

void bordas(int l, int c, int lb, int vb, int m[nmax][nmax])
{
    int cl, cc, i;
    cl = 0;
    cc = 0;
    for (i=0;i<lb;i++)
    {   //borda lateral esquerda
        for(cl=0;cl<l;cl++)
        {   
            m[cl][i] = vb;
        }
       //borda lateral direita
        for(cl=0;cl<l;cl++)
        {   
            m[cl][l-1-i] = vb;
        }
        //borda superior
        for(cc=0;cc<c;cc++)
        {   
            m[i][cc] = vb;
        }
        //borda inferior
        for(cc=0;cc<c;cc++)
        {   
            m[c-1-i][cc] = vb;
        }
    }
    return;
}

void print_pgm (int l, int c, int m[nmax][nmax])
{
    printf("P2\n%d %d\n255\n", c, l);
    print_m (l,c,m);
    return;
}


int main (void)
{
    int m[nmax][nmax], l, c, lb, vb;

    scanf("%d %d %d %d", &c, &l, &lb, &vb);

    init_m (l,c,m);

    bordas (l,c,lb,vb,m);

    print_pgm (l,c,m);

    return 0;
    
}