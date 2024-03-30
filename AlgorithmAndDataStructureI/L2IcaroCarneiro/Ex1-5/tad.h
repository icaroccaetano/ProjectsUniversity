#include <stdio.h>
#include <stdlib.h>

#define nmax 50
#define SUCCESS 0
#define ERROR 1

typedef struct 
{
    int l[nmax];
    int nelem;
} Lista;

void newlist (Lista* a); /* Cria Lista */
int add (Lista* a, int x); /*Adicona termo x a lista */
void print (Lista*a); /* Imprime lista */
int check (Lista* a, int x); /*Confere se o termo x esta na lista*/
Lista concatena (Lista* a, Lista* b); /* Retorna a concatenação das duas lista*/
void auxremove (Lista* a); /*remove o primeiro termo da lista*/
void remove_ (Lista *a, int x); /*Remove os primeiros x termos da lista*/
int maiorValor (Lista* a, int* pos, int* val); /*Retorna por referencia a posicao e o maior valor da lista*/
int par (Lista* a); /*Quantos valores pares na lista*/
double media (Lista* a); /*Media dos valores dda lista*/