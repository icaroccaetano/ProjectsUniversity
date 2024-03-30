#include "tad.h"

void init (Fila *a)
{
    a->prim = NULL;
    a->ult = a->prim;
    a->qtd = 0;
}
void enfileira (Fila *a, int n)
{
    TipoCelula *q = malloc(sizeof(TipoCelula));
    q->id = n;
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
void printfila (Fila *a)
{
    TipoCelula *q = a->prim;
    int i;
    printf("Ordem do próximo a sair até o último:\n");
    printf("Quanto maior o tempo de espera mais rápido a tarefa será exeutada\n");
    for (i=(a->qtd-1);i>=0;i--)
    {
        printf("Código da processo: %d (Tempo: %d)\n", q->id, i);
        q = q->prox;       
    }
}