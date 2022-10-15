#include <stdio.h>

int somaAmp (int m[6][6])
{   
    int al, ac, s, as;
    s = -64;
    as = 0;
    for (al=0;al<4;al++)
    {
        for (ac=0;ac<4;ac++)
        {
            as = m[al][ac] + m[al][(ac+1)] +m[al][(ac+2)] + m[al+1][(ac+1)] + m[al+2][(ac)] + m[al+2][(ac+1)] +m[al+2][(ac+2)];
            if (as>s) {s=as;}
        }
    }
    return s;
}

void read_m (int l, int c, int  m[6][6])
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

int main(void)
{
    int m[6][6], r;

    read_m (6,6,m);

    r = somaAmp (m);

    printf("%d\n", r);

    return 0;

}