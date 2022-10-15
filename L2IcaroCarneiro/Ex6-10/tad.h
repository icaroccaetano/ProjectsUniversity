#include <stdio.h>
#include <stdlib.h>

typedef struct TipoCelula
{
    int n;
    struct TipoCelula *prox;
} TipoCelula;

typedef struct TipoCelula *ApontadorCelula;

typedef struct 
{
    ApontadorCelula prim, ult;
    int qt;
}Lista;
void init (Lista *a);
void add (Lista *a, int n);
Lista crialista  (int *vect, int qnt);
int search (Lista *a, int n);
Lista concatena (Lista *a, Lista *b);
void printlista (Lista *a);
void removedor (Lista *a, int pos);
void semreps (Lista *a);
Lista intercala (Lista *a, Lista *b);
int somadalista (Lista *a);