#include <stdio.h>
#include <stdlib.h>

struct No 
{
    double valor;
    struct No *esq;
    struct No *dir;
};

typedef struct 
{
    No *no;
    int aux;
} Arvore;

typedef struct No No;

void InitArvore (Arvore *praiz)
{
    praiz = NULL;
    praiz->aux = 0;
}

void insercao(No *pRaiz, int n)
{
    if (pRaiz == NULL)
    {
        pRaiz = (No *)malloc(sizeof(No));
        pRaiz->esq = NULL;
        pRaiz->dir = NULL;
        pRaiz->valor = n;
    } 
    else 
    {
        if  (n < (pRaiz->valor)) insercao(&(pRaiz->esq), n);
        else insercao(&pRaiz->dir, n);
    }
}


