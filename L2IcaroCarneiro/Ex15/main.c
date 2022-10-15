#include "tad.h"

int main (void)
{
    Fila f1, f2, f3;

    // Inicializando as filas
    init (&f1);
    init (&f2);
    init (&f3);

    // Colocando valores na fila 1
    enfileira (&f1,1951);
    enfileira (&f1,1998);
    enfileira (&f1,1999);
    enfileira (&f1,2012);
    enfileira (&f1,2015);
    enfileira (&f1,2020);
    enfileira (&f1,2020);
    enfileira (&f1,2021);
    // printando ela
    printf("Fila 1:\n");
    printfila (&f1);

    // Colocando valores na fila 2
    enfileira (&f2,1960);
    enfileira (&f2,1967);
    enfileira (&f2,1967);
    enfileira (&f2,1969);
    enfileira (&f2,1972);
    enfileira (&f2,1973);
    enfileira (&f2,1993);
    enfileira (&f2,1994);
    enfileira (&f2,2016);
    enfileira (&f2,2018);
    // printando ela
    printf("\nFila 2:\n");
    printfila (&f2);

    // Testando a funcao do exercicio 15
    unicres (&f1,&f2,&f3);
    printf("\nUniao das duas filas crescentes:\n");
    printfila (&f3);

    return 0;
}