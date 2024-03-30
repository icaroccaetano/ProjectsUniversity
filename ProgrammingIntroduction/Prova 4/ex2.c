#include <stdio.h>
#include <stdlib.h>

void read_m (int l, int c, int ** m)
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

int ** cria_matrix (int n)
{
    int ** m;
    int i, j;

    m = malloc (n * sizeof (int*)) ;


    m[0] = malloc (n * n * sizeof (int)) ;


    for (i=1; i < n; i++)
    {
        m[i] = m[0] + i * n ;
    }

    for (i=0; i < n; i++)
    {
        for (j=0; j < n; j++)
        {
            m[i][j] = 0;    
        }
    }
    return m;
}

int ePermutacao (int ** m, int n, int * som)
{
    int al, ac, r, soma, aux;
    soma = 0;
    r = 1;
    //soma dos elemntos
    for (al=0;al<n;al++)
    {
        for (ac=0;ac<n;ac++)
        {
            soma += m[al][ac];
        }
    }
    if (soma < n || soma > n)
    {
        r++;
    }
    *som = soma;
    //ver linha por linha
    aux = 0;
    for (al=0;al<n;al++)
    {
        if(m[al][0]!=0)
        {
            if(m[al][0]=1) aux++;
            else r++;
            if (aux<1) r++;
        }
    }
    if (aux>1) r++;
    //ver coluna por coluna
    aux = 0;
    for (al=0;al<n;al++)
    {
        if(m[0][al]!=0)
        {
            if(m[0][al]=1) aux++;
            else r++;
            if (aux<1) r++;
        }
    }
    if (aux>1) r++;
    return r;
}

void destroi_matrix (int **m)
{
    free(m[0]);
    free(m);
    return;
}

int main (void)
{
    int n, al, ac, perm;
    int ** mat;
    int som = 0;
    scanf("%d", &n);

    mat = cria_matrix(n);

    for (al=0;al<n;al++)
    {
        for (ac=0;ac<n;ac++)
        {
            scanf("%d", &mat[al][ac]);
        }
    }

    perm = ePermutacao(mat,n,&som);

//    printf("r saiu valendo %d\n", perm);

    printf("%d\n", n);

    if(perm>0 && perm<2){printf("PERMUTACAO\n");}
    else {printf("NAO E PERMUTACAO\n");}

    printf("%d\n", som);

    destroi_matrix (mat);

    return 0;
}