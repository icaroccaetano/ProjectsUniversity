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
    return;
}

void mxad (int l, int c, int  m[nmax][nmax])
{
    int al, ac, i;
    i = 1;
    for (al=0;al<l;al++)
    {
        for (ac=0;ac<c;ac++)
        {
            if (ac%2==0 && al%2==0)
            {
                m[al][ac] = 0;
                continue;
            }
            if (ac%2!=0 && al%2!=0)
            {
                m[al][ac] = 0;
                continue;
            }
            m[al][ac]=i;
            i++;
        }
    }
    return;
}

int main (void)
{
    int m[nmax][nmax], l, c;
    
    scanf("%d %d", &l, &c);

    mxad (l,c,m);
    
    print_m (l,c,m);
    return 0;
}