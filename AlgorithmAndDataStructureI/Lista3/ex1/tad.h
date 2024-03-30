#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nmax 60

typedef struct
{
    char *nome;
} TipoCelula;


typedef struct
{
    TipoCelula cel[nmax];
    int qnt;
} ListaNomes;


void criaLista (ListaNomes *a); //crialista
int vaziaLista (ListaNomes *a); //confere se esta vazia
void addLista (char *x, ListaNomes *a); //adiciona um nome na lista
void encerra (ListaNomes *a); // encerra o programa (faz os free)
void ordLista (ListaNomes *a); //funcao do ex1 - Vai ordenar a lista de acordo com o tamanho
void swap (ListaNomes *a, int p1, int p2); //faz o swap entre duas posicoes
void printLista (ListaNomes *a); //printa a lista
