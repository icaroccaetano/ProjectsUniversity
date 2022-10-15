/* ICARO CARNEIRO CAETANO CHEREDNIKOV 202103732 :)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 201


typedef struct //struct celula
{
    int cod;
    char nome[36];
} TipoCelula;

typedef struct {            //struct da lista
    TipoCelula item[MAX];    
    int qnt;
} Lista;

void init (Lista *a); //inicializa as lista
int empty (Lista *a); //confere se estao vazias
void add (int x, char *nome, Lista *a);//adiciona termo
void remve (int cod, Lista *a); //remove termo
void print (Lista *a); //
void swaprod (Lista *a, int p1, int p2);
void selectionsort (Lista *a);
void insertionsort (Lista *a);
int binaria (int cod, Lista *a);
int sequencial (int cod, Lista *a);
int comparelists (Lista *a, Lista *b);