#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void)
{
    int n, i, m;
    int *v;
    
    printf("Quantidade de números da sequencia:\n");
    scanf("%d", &n);

    v = calloc (n, sizeof(int));

    printf("Escreva os números da sequencia:\nFormato: <num> <num> <num> ...\n");

    for (i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }
    m = v[0];
    for (i=0;i<n;i++)
    {
        if (v[i]>m)
        {
            m = v[i];
        }
    }
    printf("Maior número da sequência é %d\n", m);
}