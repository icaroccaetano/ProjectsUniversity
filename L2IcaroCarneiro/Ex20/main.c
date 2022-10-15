#include "tad.h"

int main (void)
{
    Fila p, i, pi;
    int n;
    init (&p);
    init (&i);
    init (&pi);

    while (1) // Adionando os termos
    {
        printf ("Adicone um numero inteiro ou 0 para sair\n");
        scanf ("%d", &n);
        if (n==0) break;
        locate (n,&p,&i);
    }
    // Testando a funcao
    pi = intercala (&p,&i);
    printfila (&pi);
    return SUCCESS;
}