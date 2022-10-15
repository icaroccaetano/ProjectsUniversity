#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int matricula;
    int idade;
    int numFilhos;
    char sexo;
    double salario;
} FUNCIONARIO;

int rendabla (FUNCIONARIO * a, int qf)
{
    int r, i, rpc;
    r=0;
    for (i=0;i<qf;i++)
    {    
        rpc = a[i].salario/(a[i].numFilhos+1);
        if(a[i].idade > 47 && rpc < 2400.00)
        {
            r++;
        }
    }
    return r;
}

int mediaFilhosH (FUNCIONARIO * a, int qf)
{
    int i, r, m;
    m=0;
    r=0;
    for (i=0;i<qf;i++)
    {    
        m+=a[i].numFilhos;
    }
    m /= qf;
    for (i=0;i<qf;i++)
    {    
        if (a[i].sexo == 'M')
        {
            if(a[i].numFilhos>m)
            {
                r++;
            }
        }
    }
    return r;
}

int mediaFilhosM (FUNCIONARIO * a, int qf)
{
    int i, r, m;
    m=0;
    r=0;
    for (i=0;i<qf;i++)
    {    
        m+=a[i].numFilhos;
    }
    m /= qf;
    for (i=0;i<qf;i++)
    {    
        if (a[i].sexo == 'F')
        {
            if(a[i].numFilhos>m)
            {
                r++;
            }
        }
    }
    return r;
}

int mediaIdades (FUNCIONARIO * a, int qf)
{
    int i, r, m;
    r=0;
    m=0;
    for (i=0;i<qf;i++)
    {
        m+=a[i].idade;
    }
    m /= qf;
    for (i=0;i<qf;i++)
    {    
        {
            if(a[i].idade>m && a[i].salario>3600.00)
            {
                r++;
            }
        }
    }

    return r;
}

int main (void) 
{
    int n, i, mid, mmf, mmh, rpc;
    //int * f;
    scanf("%d", &n);

    //f = (int*) calloc (n, sizeof(int));

    FUNCIONARIO f[n];

    for (i=0;i<n;i++)
    {
        scanf("%d %d %d %c %lf", &f[i].matricula, &f[i].idade, &f[i].numFilhos, &f[i].sexo, &f[i].salario);
    }

    mid = mediaIdades   (f,n); 
    mmf = mediaFilhosM  (f,n);   
    mmh = mediaFilhosH  (f,n);
    rpc = rendabla      (f,n);

    printf("%d %d %d %d\n", mid, mmf, mmh, rpc);

    //free(f);
    return 0;
}