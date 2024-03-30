#include "tad.h"

int main (void)
{
    Lista l1, l2, l3;
    int i, a;
    int pos, val;

    newlist (&l1);
    a=0;
    for (i=5;i<=8;i++)
    {
        if (add (&l1,i) == SUCCESS) printf ("%d adicionado com exito\n", l1.l[a]);
        a++;
    }
    print (&l1);
    
    newlist (&l2);
    a=0;
    for (i=1;i<=4;i++)
    {
        if (add (&l2,i) == SUCCESS) printf ("%d adicionado com exito\n", l2.l[a]);
        a++;
    }
    print (&l2);


    printf("\nTESTE CONCATENA\n");
    l3 = concatena(&l1,&l2);
    print (&l3);

    printf("\nTESTE REMOVE\n");
    remove_(&l3, 2);
    print (&l3);

    printf("\nTESTE MAIOR\n");
    if (maiorValor (&l3,&pos,&val) == SUCCESS)
    {
        printf("Maior Valor = %d\nPosicao do maior valor = %d\n", val, pos);
    }
    
    printf("\nTESTE PARES\n");
    printf ("Numeros pares na lista = %d\n", par(&l3));

    printf("\nTESTE MEDIA\n");
    printf ("Media da lista = %.2lf\n", media(&l3));
}