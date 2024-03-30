#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int numJogo;
    int numero[6];
} CARTELA;

int correcao (int * a, int * g, int *ac)
{
    int i, j, x;
    x= 0;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if(a[i] = g[j]) 
            {
                ac[x]=a[i];
                x++;
            }
        }
    }
    return x;
}

void zera (int *a)
{
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    return;
}

int main (void) 
{
    int n, i, sor, j, k, a, agm, l;
    int num[100];
    scanf("%d", &n);
    agm = 0;

    CARTELA *jgs = (CARTELA*) malloc((n+1)*sizeof(CARTELA));

    for (i=0;i<n;i++)
    {
        scanf ("%d %d %d %d %d %d %d", &jgs[i].numJogo, &jgs[i].numero[0], &jgs[i].numero[1], &jgs[i].numero[2], &jgs[i].numero[3], &jgs[i].numero[4], &jgs[i].numero[5]);
    }
    scanf("%d %d %d %d %d %d %d", &jgs[n].numJogo, &jgs[n].numero[0], &jgs[n].numero[1], &jgs[n].numero[2], &jgs[n].numero[3], &jgs[n].numero[4], &jgs[n].numero[5]);

    for(i=0;i<n;i++) 
    {   
        a=0;
        
        for(k=0;k<6;k++)
        {
            for(j=0;j<6;j++)
            {
                if(jgs[i].numero[k] == jgs[n].numero[j]) 
                {
                    num[a]=jgs[i].numero[k];
                    a++;
                }
            }
        }
        
        if (a>3 && a<5)
        {
            agm++;
            printf("QUADRA %d: ", jgs[i].numJogo);
            for(l=0;l<a;l++) {printf("%d ", num[l]);}
            printf("\n");
            zera (num);
        }
        else if (a>4 && a<6)
        {
            agm++;
            printf("QUINA %d: ", jgs[i].numJogo);
            for(l=0;l<a;l++) {printf("%d ", num[l]);}
            printf("\n");
            zera (num);
        }
        else if (a>5 && a<7)
        {
            agm++;
            printf("SENA %d: ", jgs[i].numJogo);
            for(l=0;l<a;l++) {printf("%d ", num[l]);}
            printf("\n");
            zera (num);
        }
    }

    if (agm==0) {printf("NENHUMA CARTELA PREMIADA PARA O CONCURSO %d\n", jgs[n].numJogo);}
    free (jgs);
    return 0;
}