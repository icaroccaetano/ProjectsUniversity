#include "tad.h"

void locate (int n, Fila *par, Fila *impar)
{
    if (n%2==0) enfileira (par,n);
    else enfileira (impar,n);
    return;
}
void init (Fila *a)
{
    a->prim = NULL;
    a->ult = a->prim;
    a->qtd = 0;
}
void enfileira (Fila *a, int n)
{
    TipoCelula *q = malloc(sizeof(TipoCelula));
    q->valor = n;
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
    return;
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
        printf("Termo %d: %d\n", i, q->valor);
        q = q->prox;       
    }
}
int positivos (Fila *a) // Descobrir quantos positivos tenho na fila
{
    TipoCelula *q = a->prim;
    int i, r=0;
    for (i=0;i<a->qtd;i++)
    {
        if (q->valor>0) 
        {   
            r++;
        }
        q = q->prox;       
    }
    return r;
}
Fila intercala (Fila *par, Fila *impar)
{
    Fila r; // Fila resposta
    int i=0, qt;
    TipoCelula *qp, *qi; // Apontadores 
    init (&r);
    qt = positivos(par) + positivos(impar);
    qp = par->prim;
    qi = impar->prim;
    while (r.qtd < qt) // Loop vai terminar so quando a fila resposta tiver a quantidade de termos certa
    {
        if (i%2==0) //começamos a adicionar pela fila impar como pede a questao
        {
            if (qi->valor>0)
            {
                if (qi != NULL) 
                {
                    enfileira (&r,qi->valor);
                }
                i++;
            }
            qi = qi->prox;
        }
        else if (i%2!=0) //começamos a adicionar pela fila impar como pede a questao
        {
            if (qp->valor>0)
            {
                if (qp != NULL) 
                {
                    enfileira (&r,qp->valor);
                }
                i++;
            }
            qp = qp->prox;
        }
    }
    return r;
}