#include "tad.h"

void init (Fila *a)
{
    a->prim = NULL;
    a->ult = a->prim;
    a->qtd = 0;
}
void enfileira (Fila *a, int id)
{
    TipoCelula *q = malloc(sizeof(TipoCelula));
    q->val = id;
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
    for (i=0;i<a->qtd;i++)
    {
        printf("%d\n", q->val);
        q = q->prox;       
    }
}
void unicres (Fila *a, Fila *b, Fila *dest)
{
    int i;
    TipoCelula *q, *r;
    q = a->prim;
    r = b->prim;

    for (i=0;i<(a->qtd+b->qtd);i++)
    {
        if (q->val<=r->val)
        {           
            enfileira (dest,q->val);
            if (q->prox!=NULL) q = q->prox;
            else break;
        }
        else if (r->val<q->val) 
        {
            enfileira (dest,r->val);
            if (r->prox!=NULL) r = r->prox;
            else break;
        }
    }
    if (r->prox!=NULL) // Vai vim pra ca quando uma das lista ja estiverem inteiramente adicionadas, ai aqui adiciona o resto dos termos da outra lista
    {
        for (i;i<(a->qtd+b->qtd);i++)
        {
            enfileira (dest,r->val);
            if (r->prox!=NULL) r = r->prox;
            else break;
        }
    }
    else
    {
        for (i;i<(a->qtd+b->qtd);i++)
        {
            enfileira (dest,q->val);
            if (q->prox!=NULL) q = q->prox;
            else break;
        }
    }
}