#include "tad.h"

int main (void)
{
    Fila f, f1, f2;
    int p, qtd;
    double n;

    qtd = 15; // Quantidade de termos da fila

    init (&f);
    init (&f1);
    init (&f2);

    // Adicionadno os termos
    enfileira (&f,5.45,3); 
    enfileira (&f,145.15,1); 
    enfileira (&f,47.41,4); 
    enfileira (&f,7.77,3); 
    enfileira (&f,10.10,2); 
    enfileira (&f,1.123,5); 
    enfileira (&f,98.457,5); 
    enfileira (&f,0.133,4); 
    enfileira (&f,5.147,4); 
    enfileira (&f,86.457,3); 
    enfileira (&f,124.1,1); 
    enfileira (&f,487.1,2); 
    enfileira (&f,5.5,3); 
    enfileira (&f,3.33,2); 
    enfileira (&f,30.30,1);
    printf("Fila antes:\n");
    printfila (&f);
    // Utilizando a funcao
    separaPrior (&f,3,&f1,&f2);
    printf("Separadas:\nFila 1:\n");
    printfila (&f1);
    printf("Fila 2:\n");
    printfila (&f2);

    return 0;
}