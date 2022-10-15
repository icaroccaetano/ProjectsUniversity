#include "tad.h"

int main (void)
{
    ListaNomes lista;
    char *pal;
    int i, n;

    // Teste da função ex 1
    criaLista (&lista);
    printf("Digite a quantidade de nomes a serem adicionadas\n");
    scanf("%d%*c", &n);
    printf("Digite os %d nomes a serem adicionadas separadas por um ENTER\n", n);
    for (i=0;i<n;i++)
    {
        scanf("%[^\n]%*c", pal);
        addLista (pal,&lista);
    }
    ordLista (&lista);
    printLista (&lista);
    encerra (&lista);
    return 0;
}