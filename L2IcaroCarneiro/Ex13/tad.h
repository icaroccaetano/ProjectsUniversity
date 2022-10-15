#include <stdio.h>
#include <stdlib.h>

typedef struct TipoCelula
{
    int id;
    struct TipoCelula *prox, *ant;
}TipoCelula;

typedef struct TipoCelula *ApontadorCelula;

typedef struct
{
    ApontadorCelula prim, ult;
    int qtd;
}Fila;

void init (Fila *a);
void enfileira (Fila *a, int n);
void desenfileira (Fila *a);
void printfila (Fila *a);
