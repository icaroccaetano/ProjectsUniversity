/* ICARO CARNEIRO CAETANO CHEREDNIKOV 202103732 :)*/
#include "tad.h"

int main (void)
{
    Lista l1, l2;
    int aux, aux2,i;
    char pala[36];

    init(&l1);
    init(&l2);
    
    printf ("ALMOXARIFADO 1 - Quantidade de produtos a serem adicionados: ");
    scanf ("%d", &aux);
    printf ("Insira os %d produtos separados por um enter.\nCodigo e nome do produto separados por um espaço:\n<codigo> <nome>\n", aux);
    for (i=0;i<aux;i++)
    {
        scanf("%d %[^\n]%*c", &aux2, pala);
        add (aux2,pala,&l1);
    }
    printf ("ALMOXARIFADO 2 - Quantidade de produtos a serem adicionados: ");
    scanf ("%d", &aux);
    printf ("Insira os %d produtos separados por um enter.\nCodigo e nome do produto separados por um espaço:\n<codigo> <nome>\n", aux);
    for (i=0;i<aux;i++)
    {
        scanf("%d %[^\n]%*c", &aux2, pala);
        add (aux2,pala,&l2);
    }
    selectionsort (&l1);
    insertionsort (&l2); // Testo os dois tipos de ordenacao
    comparelists (&l1, &l2);
    printf ("Imprimir listas, escolha uma opcao:\n");
    printf ("0 - Nao imprimir nenhuma\n1 - Imprimir Almoxarifado 1\n2 - Imprimir Almoxarifado 2\n3 - Imprimir Almoxarifado 1 e 2\n");
    scanf("%d", &aux2);
    switch (aux2)
    {
        case 0:
            break;
        case 1:
            printf ("ALMOXARIFADO 1:\n");
            print (&l1);
            break;
        case 2:
            printf ("ALMOXARIFADO 2:\n");
            print (&l2);
            break;
        case 3:
            printf ("ALMOXARIFADO 1:\n");
            print (&l1);
            printf ("ALMOXARIFADO 2:\n");
            print (&l2);
            break;
        default:
            break;
    }

    return 0; // :)
}