#include "tad.h"

int main (void)
{
    Pilha pilha;
    //inicializa
    init (&pilha);
    // adiciona termos a pilha
    empilha (&pilha,524);
    empilha (&pilha,1254);
    empilha (&pilha,21);
    empilha (&pilha,427);
    empilha (&pilha,48);
    // printando a pilha
    printPilha (&pilha);
    // Testando funcao ex16
    printf("Desempilhado: %d\n", retRem (&pilha));
    printPilha (&pilha);
    // Testando funcao ex17
    infoPilha (&pilha);
    // Testando funcao ex18
    invertePilha (&pilha);
    printPilha (&pilha);

    return 0;
}