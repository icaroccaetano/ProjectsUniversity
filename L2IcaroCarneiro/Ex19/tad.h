#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUCCESS 0
#define UNSUCCESFUL 1

typedef struct TipoCelula
{
    char caractere;
    struct TipoCelula *prox, *ant;
}TipoCelula;

typedef struct TipoCelula *ApontadorCelula;

typedef struct
{
    ApontadorCelula fundo, topo;
    int qtd;
}Pilha;

void init (Pilha *a);
int pilhaVazia (Pilha *a);
void limpapilha (Pilha *a);
void empilha (Pilha *a, char id);
void desempilha (Pilha *a);
void printPilha (Pilha *a);
void palindromo (Pilha *a);
