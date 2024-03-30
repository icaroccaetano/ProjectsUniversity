#include "tad.h"

int main (void)
{
    Fila fila;

    //inicializando fila
    init(&fila);
    // adicionando processos à fila
    enfileira (&fila,1254);
    enfileira (&fila,698);
    enfileira (&fila,784);
    enfileira (&fila,442);
    enfileira (&fila,4);
    enfileira (&fila,1101);
    enfileira (&fila,548);
    // Verificando fila
    printfila (&fila);
    //Removendo duas tarefas
    desenfileira (&fila);
    desenfileira (&fila);
    //verificando novamente
    printfila (&fila);
    // adicionando processos à fila
    enfileira (&fila,547);    
    //verificando novamente
    printfila (&fila);

    return 0;
}