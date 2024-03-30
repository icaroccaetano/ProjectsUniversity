#include <stdio.h>
#include <stdlib.h>
#define nmax 10

void readm (int m[nmax][nmax], int l, int c);
void pmat (int n[nmax][nmax], int l, int c);
void inv (int a[nmax][nmax], int l, int c);
void tran (int a[nmax][nmax], int l, int c);
void det (int a[nmax][nmax], int l, int c);

int main (void)
{
    int l, c;
    int a[nmax][nmax];
    char op;

    scanf("%d %d", &l, &c);
    readm(a,l,c);
    scanf("%*c%c", &op);

    switch (op)
    {
        case 'I': 
            inv(a,l,c);
        break;
        case 'T': 
            tran(a,l,c);
        break;
        case 'D': 
            det(a,l,c);
        break;
        default:
            printf("operacao invalida\n");
        break;
    }

    return 0;   
}

void readm (int m[nmax][nmax], int l, int c)
{  
    int cl, cc;
    for (cl=0;cl<l;cl++) {
        for (cc=0;cc<c;cc++) {
            scanf("%d", &m[cl][cc]);
        }
    }    
    return;
}

void pmat (int n[nmax][nmax], int l, int c)
{
    int cl, cc;

    for (cl=0;cl<l;cl++)
    {
        for (cc=0;cc<c;cc++)
        {
            printf("%d ", n[cl][cc]);
        }
        printf("\n");
    }
    return;
}

void inv (int a[nmax][nmax], int l, int c)
{
    int v, cl, cc, rl, rc, r[nmax][nmax];
    int* p;
    v = 0;
    p = malloc ((l*c) * sizeof(int));
    
    for (cl=0;cl<l;cl++)
    {
        for (cc=0;cc<c;cc++)
        {
            p[v] = a[cl][cc];
            v++;
        }
    }

    v = (l*c)-1;

    for (cl=0;cl<l;cl++)
    {
        for (cc=0;cc<c;cc++)
        {
            r[cl][cc] = p[v];
            v--;
        }
    }
    free (p);
    pmat (r,l,c);
    return;
}

void tran (int a[nmax][nmax], int l, int c)
{
    int r[nmax][nmax], cl, cc, rl, rc;
    cl = 0;
    cc = 0;

    for (rc=0;rc<l;rc++)
    {
        for (rl=0;rl<c;rl++)
        {
            r[rl][rc] = a[cl][cc];
            cc++;
            if (cc==c)
            {
                cl++;
                cc=0;
            }
        }
    }
    pmat(r,c,l);
    return;
}

void det (int a[nmax][nmax], int l, int c)
{
    int p, s, r, cl, cc;
    p = 1;
    s = 1;

    if (l==c)
    {
        //produto principal
        for (cl=0;cl<l;cl++)
        {
            for (cc=0;cc<c;cc++)
            {
                if (cl==cc) 
                {
                    p *= a[cl][cc];
                }
            }
        }
        //produto secundario
        cc = (c-1);
        for (cl=0;cl<l;cl++)
        {
            s *= a[cl][cc];
            cc--;
        }

        r = p-s;

        printf("%d\n", r);
    }

    else printf("ERROR\n");
    return;
}