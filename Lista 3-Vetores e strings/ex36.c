#include <stdio.h>
#define nmax 500000
#define max  1000000

void unif (int q1, int qt, int *v1,int  *v2)
{
    int i, a=0;
    
    for (i=q1;i<qt;i++) 
    {  
        v1[i] = v2[a];
        a++;
    }
    return;
}

void ord (int q, int *v, int *ans) {
    int i, m, a, ii;

    m = max;

    for (ii=0;ii<q;ii++) 
    { 
        for (i=0;i<q;i++)
        {
            if (v[i] <= m)
            {
                m = v[i];
                a = i;
            }
        }
        ans[ii] = m;
        v[a] = max;
        m = max;
    }
    return;
}

int main () 
{
    int qtot, v1[nmax], v2[nmax], q1, q2, i, ans[nmax];
    scanf("%d\n%d", &q1, &q2);

    if (q1<1 || q1>nmax || q2<1 || q2>nmax) {return 0;}
    
    //leitura dos dois vetores
    for (i=0;i<q1;i++) 
    {
        scanf("%d", &v1[i]);
    }   
    for (i=0;i<q2;i++) 
    {
        scanf("%d", &v2[i]);
    }
    qtot = q1+q2;
    
    unif (q1,qtot,v1,v2);

    ord (qtot,v1,ans);

    for (i=0;i<qtot;i++) 
    {
        printf("%d\n",ans[i]);
    }    
    return 0;
}