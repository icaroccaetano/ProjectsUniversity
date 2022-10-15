/*ICARO CARNEIRO 202103732*/
#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No *esquerda;
    struct No *direita;
    
} No;

void criarArvore (No **pRaiz);
void insercao (No **pRaiz, int numero);
void exibirEmOrdem (No *pRaiz);
void exibirPreOrdem (No *pRaiz);
void exibirPosOrdem (No *pRaiz);
void encerra (No **pRaiz);

int main (void)
{
    int testes, nodes, n, i;
    No *raiz;
    scanf ("%d", &testes);
    for (i=1;i<=testes;i++)
    {
        criarArvore (&raiz);
        scanf ("%d", &nodes);
        while (nodes--)
        {
            scanf ("%d", &n);
            insercao (&raiz, n);
        }
        printf ("Case %d:\nPre.:", i);
        exibirPreOrdem (raiz);
        printf ("\nIn..:");
        exibirEmOrdem (raiz);
        printf ("\nPost:");
        exibirPosOrdem (raiz);
        printf ("\n\n");
        free (raiz);
    }

    return 0;
}

void criarArvore (No **pRaiz)
{
    *pRaiz = NULL;
}
void insercao (No **pRaiz, int numero)
{
    if (*pRaiz == NULL) //se estiver vazio e vou alocar o numero la
    {
        *pRaiz = (No *)malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->valor = numero;
    }
    else // se ja tiver algum numero na raiz eu vou mandar ele pra esquerda ou pra direita
    {
        //Se for menor que o valor da raiz, vai pra esquerda dele. faço isso chamando a inseercao denovo em praiz->esquerda, se for maior, vai pra direita
        if (numero < ((*pRaiz)->valor))
        {    
            insercao (&((*pRaiz)->esquerda), numero);
        }
        else
        {
            insercao (&((*pRaiz)->direita), numero);
        }
    }
}
void exibirEmOrdem (No *pRaiz)
{
    if (pRaiz != NULL)
    {
        exibirEmOrdem(pRaiz->esquerda);
        printf(" %d", pRaiz->valor);
        exibirEmOrdem (pRaiz->direita);
    }
}
void exibirPreOrdem (No *pRaiz)
{
    if (pRaiz != NULL)
    {
        printf (" %d", pRaiz->valor);
        exibirPreOrdem (pRaiz->esquerda);
        exibirPreOrdem (pRaiz->direita);
    }
}
void exibirPosOrdem (No *pRaiz)
{
    if (pRaiz != NULL)
    {
        exibirPosOrdem (pRaiz->esquerda);
        exibirPosOrdem (pRaiz->direita);
        printf (" %d", pRaiz->valor);
    }
}
void encerra (No **pRaiz)
{
    if (pRaiz != NULL)
    {
        encerra (&(*pRaiz)->esquerda);
        encerra (&(*pRaiz)->direita);
        free ((*pRaiz));
    }
}
