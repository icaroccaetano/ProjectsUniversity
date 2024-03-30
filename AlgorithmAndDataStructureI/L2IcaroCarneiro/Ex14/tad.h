#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TipoCelula
{
    char nome[24];
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
void enfileira (Fila *a, int id, char* nome);
void desenfileira (Fila *a);
void printfila (Fila *a);
void front (Fila *a);