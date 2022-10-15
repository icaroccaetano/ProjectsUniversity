#include <stdio.h>
#include <stdlib.h>

float maior(float *v, int tam, int i);

int main (void)
{
    int n, i;
    float *v;
    
    printf("Quantidade de termos do vetor:\n");
    scanf("%d", &n);

    v = malloc (n * sizeof(float));

    printf("Inserir os %d valores do vetor:\n", n);
    printf("   Formato: <v1> <v2> ... <vn>\n");

    for(i=0;i<n;i++)
    {
        scanf("%f", &v[i]);
    }

    printf("Maior termo = %.2f\n", maior (v,n,0));

    free (v);
    return 0;
}

float maior(float *v, int tam, int i)
{
    if(tam == 0) return v[i];
    else
    {
        if (v[tam-1] > v[i])
        {
            return maior(v, tam-1, tam-1);
        }
        else 
        {
            return maior (v, tam-1, i);
        }
    }
}