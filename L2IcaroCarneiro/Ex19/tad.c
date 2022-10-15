#include "tad.h"

void init (Pilha *a)
{
    a->fundo = NULL;
    a->topo = a->fundo;
    a->qtd = 0;
}
int pilhaVazia (Pilha *a)
{
    if (a->fundo == NULL) return SUCCESS;
    else return UNSUCCESFUL;
}
void limpapilha (Pilha *a)
{
    int aux, i;
    aux = a->qtd;
    for(i=0;i<aux;i++)
    {
        desempilha (a);
    }
    if (pilhaVazia(a) == UNSUCCESFUL) printf("Erro ao esvaziar pilha");
    return;
}
void empilha (Pilha *a, char id)
{
    TipoCelula *q = malloc(sizeof(TipoCelula));
    q->caractere = id;
    if (pilhaVazia(a) == SUCCESS) //se estiver vazia
    {
        a->fundo = q;
        a->fundo->ant = NULL;
        a->fundo->prox = NULL;
        a->topo = a->fundo;
        a->qtd++;
    }
    else
    {
        a->topo->prox = q;
        q->ant = a->topo;
        a->topo = q;
        a->topo->prox = NULL;
        a->qtd++;
    }

}
void desempilha (Pilha *a)
{
    if (pilhaVazia(a) == SUCCESS)
    {
        printf ("ERRO - PILHA VAZIA\n");
        return;
    }
    TipoCelula *q;
    if (a->qtd == 1) //se so tiver um termo
    {
        q = a->topo;
        free (q);
        init (a);
        return;
    }
    q = a->topo;
    a->topo = a->topo->ant;
    a->topo->prox = NULL;
    a->qtd--;    
    free (q);
}
void printPilha (Pilha *a)
{
    TipoCelula *q = a->fundo; //comecei apontando para o fundo so para as impressoes das frases nao palindronas nao sairem invertidas
    int i;
    for (i=0;i<a->qtd;i++)
    {
        printf("%c", q->caractere);
        q = q->prox;       
    }
}
void palindromo (Pilha *a)
{
    int i, j=0, aux;
    char *vec; //irei armazenar as letras nesse vetor para compará-las (ignorando os espaços)
    TipoCelula *q = a->topo, *r;

    for (i=0;i<a->qtd;i++)
    {
        if (q->caractere != 32) //se for diferente de espaço;
        {
            vec[j] = q->caractere;
            j++;
        }
        q = q->ant;
    }
    aux = j;
    // if (aux%2!=0) aux--;
    j--;
    for (i=0;i<(aux/2);i++)
    {
        if (vec[i] != vec[j])
        {
            printPilha (a);
            printf (" - Nao é palíndromo!\n");
            return;
        }
        j--;
    }
    printPilha (a);
    printf(" - É palíndromo!\n");
    return;
}
