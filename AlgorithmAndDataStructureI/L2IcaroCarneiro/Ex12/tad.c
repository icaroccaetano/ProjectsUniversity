#include "tad.h"

void init (Fila *a)
{
    a->prim = NULL;
    a->ult = a->prim;
    a->qtd = 0;
}
void enfileira (Fila *a, double n, int p)
{
    TipoCelula *q = malloc(sizeof(TipoCelula));
    q->valor = n;
    q->prio = p;
    if (a->prim == NULL) //se estiver vazia
    {
        a->prim = q;
        a-> ult = q;
        a->prim->ant = NULL;
        a->prim->prox = NULL;
        a->qtd++;
    }
    else
    {
        a->ult->prox = q;
        q->ant = a->ult;
        a->ult = q;
        a->ult->prox = NULL;
        a->qtd++;
    }
}
void desenfileira (Fila *a)
{
    if (a->prim == NULL)
    {
        printf ("ERRO - FILA VAZIA\n");
        return;
    }
    TipoCelula *q;
    q = a->prim;
    a->prim = a->prim->prox;
    a->qtd--;
    free (q);    
}
void separaPrior (Fila *a, int p, Fila *p1, Fila *p2)
{
    TipoCelula *q = a->prim;
    int i;
    for (i=0;i<a->qtd;i++)
    {
        if (q->prio<=p)
        {
            enfileira (p1, q->valor, q->prio);
        }
        else
        {
            enfileira (p2, q->valor, q->prio);
        }
        q = q->prox;
    }
}
void printfila (Fila *a)
{
    TipoCelula *q = a->prim;
    int i;
    for (i=0;i<a->qtd;i++)
    {
        printf("Termo %d: %.4lf (Pri: %d)\n", i, q->valor, q->prio);
        q = q->prox;       
    }
}