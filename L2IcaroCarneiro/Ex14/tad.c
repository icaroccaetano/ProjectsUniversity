#include "tad.h"

void init (Fila *a)
{
    a->prim = NULL;
    a->ult = a->prim;
    a->qtd = 0;
}
void enfileira (Fila *a, int id, char* nome)
{
    TipoCelula *q = malloc(sizeof(TipoCelula));
    q->id = id;
    strcpy (q->nome, nome);
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
        printf ("ERRO - Sem aviões para decolar!\n");
        return;
    }
    TipoCelula *q;
    q = a->prim;
    a->prim = a->prim->prox;
    a->qtd--;

    printf("Decolagem realizada! Dados do avião decolado:\n");
    printf("Nome: %s (Id: %d)\n", q->nome, q->id);    
    free (q);
}
void printfila (Fila *a)
{
    TipoCelula *q = a->prim;
    int i;
    printf("Ordem da fila de decolagem\n");
    for (i=0;i<a->qtd;i++)
    {
        printf("%d: Nome: %s (Id: %d)\n", i, q->nome, q->id);
        q = q->prox;       
    }
}

void front (Fila *a)
{
    TipoCelula *q = a->prim;

    printf("Primeiro avião da fila:\n");
    printf("Nome: %s (Id: %d)\n", q->nome, q->id);
}