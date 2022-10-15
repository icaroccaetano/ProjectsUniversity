#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUCCESS 0
#define UNSUCCESFUL 1

typedef struct TipoCelula
{
    int valor;
    struct TipoCelula *prox, *ant;
}TipoCelula;

typedef struct TipoCelula *ApontadorCelula;

typedef struct
{
    ApontadorCelula prim, ult;
    int qtd;
}Fila;

void locate (int n, Fila *par, Fila *impar);
void init (Fila *a);
void enfileira (Fila *a, int n);
void desenfileira (Fila *a);
void printfila (Fila *a);
int positivos (Fila *a);
Fila intercala (Fila *par, Fila *impar);