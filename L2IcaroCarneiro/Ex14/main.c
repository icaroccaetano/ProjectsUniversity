#include "tad.h"

int main (void)
{
    Fila filadec;

    //inicializa
    init (&filadec);
    //adicionando avioes
    enfileira(&filadec,453,"NAOCAI");
    enfileira(&filadec,750,"IHULLL");
    enfileira(&filadec,325,"HAJACORACAO");
    enfileira(&filadec,951,"VOAVOA");
    enfileira(&filadec,413,"VOADOR");
    enfileira(&filadec,596,"REZOUVOOU");
    //mostrar lista de espera
    printfila (&filadec);
    //mostrando primeiro
    front (&filadec);
    //retirando da fila
    desenfileira (&filadec);
    desenfileira (&filadec);
    // mostrando a lista de espera
    printfila (&filadec);
}