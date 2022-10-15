
#include <stdio.h>
#include <stdlib.h>

typedef struct TipoCelula
{
    double valor;
    int prio;
    struct TipoCelula *prox, *ant;
}TipoCelula;

typedef struct TipoCelula *ApontadorCelula;

typedef struct
{
    ApontadorCelula prim, ult;
    int qtd;
}Fila;

void init (Fila *a);
void enfileira (Fila *a, double n, int p);
void desenfileira (Fila *a);
void separaPrior (Fila *a, int p, Fila *p1, Fila *p2);
void printfila (Fila *a);