#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoCelula
{
    int val;
    struct TipoCelula *prox, *ant;
}TipoCelula;

typedef struct TipoCelula *ApontadorCelula;

typedef struct
{
    ApontadorCelula prim, ult;
    int qtd;
}Fila;

void init (Fila *a);
void enfileira (Fila *a, int id);
void desenfileira (Fila *a);
void printfila (Fila *a);
void unicres (Fila *a, Fila *b, Fila *dest);