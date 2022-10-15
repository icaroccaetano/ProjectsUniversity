#include <stdio.h>

void read_m (int l, int c, int  m[9][9])
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

int colunas (int m[9][9])
{
    int l, c, s;
    for (c=0;c<9;c++)
    {  
        s = 0;
//        printf("c%d =", c);
        for (l=0;l<9;l++)
        {
            s += m[l][c];
//            printf("%d + ", m[l][c]);
        }
        //printf("= %d\n", s);
        if (s!=45)
        {
            return 1;
        }
    }
    return 0;
}

int linhas (int m[9][9])
{
    int l, c, s;
    for (l=0;l<9;l++)
    {  
        s = 0;
        for (c=0;c<9;c++)
        {
            s += m[l][c];
        }
        if (s!=45)
        {
            return 1;
        }
    }
    return 0;
}

int quadrados (int m[9][9])
{
    int s, l, c;
    s = 0;
    for (l=0;l<3;l++)
    {
        for (c=0;c<3;c++)
        {
            s += m[l][c];
        }
    }
    if (s!=45)
    {
        return 1;
    }
    s = 0;
    for (l=0;l<3;l++)
    {
        for (c=3;c<6;c++)
        {
            s += m[l][c];
        }
    }
    if (s!=45)
    {
        return 1;
    }
    s = 0;
    for (l=0;l<3;l++)
    {
        for (c=6;c<9;c++)
        {
            s += m[l][c];
        }
    }
    if (s!=45)
    {
        return 1;
    }
    s = 0;
    for (l=3;l<6;l++)
    {
        for (c=0;c<3;c++)
        {
            s += m[l][c];
        }
    }
    if (s!=45)
    {
        return 1;
    }
    s = 0;
    for (l=3;l<6;l++)
    {
        for (c=3;c<6;c++)
        {
            s += m[l][c];
        }
    }
    if (s!=45)
    {
        return 1;
    }
    s = 0;
    for (l=3;l<6;l++)
    {
        for (c=6;c<9;c++)
        {
            s += m[l][c];
        }
    }
    if (s!=45)
    {
        return 1;
    }
    s = 0;
    for (l=6;l<9;l++)
    {
        for (c=0;c<3;c++)
        {
            s += m[l][c];
        }
    }
    if (s!=45)
    {
        return 1;
    }
    s = 0;
    for (l=6;l<9;l++)
    {
        for (c=3;c<6;c++)
        {
            s += m[l][c];
        }
    }
    if (s!=45)
    {
        return 1;
    }
    s = 0;
    for (l=6;l<9;l++)
    {
        for (c=6;c<9;c++)
        {
            s += m[l][c];
        }
    }
    if (s!=45)
    {
        return 1;
    }
    return 0;
}

int main (void)
{
    int m[9][9], t;
    
    read_m (9,9,m);
    
    t = linhas(m);
    if (t>0) 
    {
        printf("invalido\n");
        return 0;
    }

    t = colunas (m);
    if (t>0)
    {
        printf("invalido\n");
        return 0;
    }

    t = quadrados (m);
    if (t>0)
    {
        printf("invalido\n");
        return 0;
    }

    printf("valido\n");

    return 0;
}