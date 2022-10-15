#include "tad.h"

void init (Lista *a)
{
    a->prim = NULL;
    a->ult = a->prim;
    a->qt = 0;
}
void add (Lista *a, int n)
{
    TipoCelula *q = malloc(sizeof(TipoCelula));
    q->n = n;
    if (a->prim == NULL) // Se estiver vazia
    {
        a->prim = q;
        a->ult = q;
        a->ult->prox = NULL;
        a->qt++;
    }
    else 
    {
        a->ult->prox = q;
        a->ult = q;
        a->ult->prox = NULL;
        a->qt++;
    }
}
Lista crialista  (int *vect, int qnt)
{
    int i;
    Lista lista;
    TipoCelula *aux;
    init(&lista);
    aux = lista.prim; // Inicia no primeiro
    for (i=0;i<qnt;i++)
    {
        add(&lista,vect[i]);
    }
    return lista;
}
int search (Lista *a, int n)
{
    int i;
    ApontadorCelula q;
    q = a->prim;
    for (i=0;i<a->qt;i++)
    {
        if (q->n == n) return 1;
        q = q->prox;
    }
    return 0;
}
Lista concatena (Lista *a, Lista *b)
{
    Lista r;
    int i;
    TipoCelula *q;
    init (&r);
    q = a->prim;
    for (i=0;i<a->qt;i++) // Adcionando termos da lista 1
    {
        add (&r,q->n);
        q = q->prox;
    }
    q = b->prim;
    for (i=0;i<b->qt;i++) // Adcionando termos da lista 2
    {
        add(&r,q->n);
        q = q->prox;
    }
    return r;
}
void printlista (Lista *a)
{
    int i;
    TipoCelula *q;
    q = a->prim;
    for (i=0;i<a->qt;i++) 
    {
        printf ("%2d ", q->n);
        if ((i+1)%5==0 && i!=1) printf ("\n");
        q = q->prox;
    }
    if (i%5 != 0)printf("\n");
}

void removedor (Lista *a, int pos)
{
    int i;
    TipoCelula *q, *ant;
    if (pos==0) //Caso o pra ser removido seja o primeiro
    {    
        q = a->prim; // q recebe p primeiro termo da lista
        a->prim = a->prim->prox; // o primeiro termo da lista vai virar o segundo (primeiro vai ser removido)
        free (q); //libera o q
       a->qt--;
       return;
    }
    else if (pos == (a->qt-1)) // Caso o para ser romvido seja o ultimo
    {
        q = a->ult;
        ant = a->prim;
        for (i=0;i<=(pos-1);i++)
        {
            ant = ant->prox;
        }
        ant->prox = NULL; // O anterior recebe NULL
        a->ult = ant; //  o ultimo agora apontara para o anterior
        free (q); //libera o q
        a->qt--;
        return;
    }
    else // se nao e o ultimo nem o primeiro
    {
        q = a->prim;
        for (i=0;i<=(pos-1);i++)
        {
            q = q->prox;
        } // q recebe o ponteiro a ser removido
        ant = a->prim;
        for (i=0;i<=(pos-2);i++) // ant recebe o ponteiro anterior
        {
            ant = ant->prox;
        } 
        ant->prox = q->prox; //poteiro prox do anterior recebe o proximo do q;
        free(q); //libera o q
        a->qt--;
        return;       
    }
}

void semreps (Lista *a)
{
    int i, j, aux;
    ApontadorCelula q, r; 
    
    inicio:
    aux = 0; //zera o auxiliar;
    q = a->prim; // q comeca apontado para o primerio termo de a;
    for(j=0;;j++) 
    {
        r = a->prim; // r comeca no primerio
        for (i=0;;i++)
        {
            if (q->n == r->n) //se o termo igual seu sucessor
            {
                aux++;
                if (aux>1)
                {         
                    printf("Repetido: %d\n", r->n);       
                    removedor (a,(i));
                    goto inicio;
                }
            }
            if (r == a->ult) 
            { 
                break;
            }
            r = r->prox;
        }
        if (q == a->ult)
        {   
            break;
        }
        aux = 0;
        q = q->prox;
    }
    return;
}
Lista intercala (Lista *a, Lista *b)
{
    Lista r;
    int i=0;
    TipoCelula *qa, *qb;
    init (&r);
    qa = a->prim;
    qb = b->prim;
    while (r.qt < (a->qt+b->qt))
    {
        if (i%2==0)
        {   if (qa != NULL)
            {
                add (&r,qa->n);
                qa = qa->prox;
            }
            i++;
        }
        else if (i%2!=0)
        {   if (qb != NULL)
            {
                add (&r,qb->n);
                qb = qb->prox;
            }
            i++;
        }
    }
    return r;    
}
int somadalista (Lista *a)
{
    int som=0,i;
    TipoCelula *q;
    q = a->prim;
    for (i=0;i<a->qt;i++)
    {
        som += q->n;
        q = q->prox;
    }
    return som;
}