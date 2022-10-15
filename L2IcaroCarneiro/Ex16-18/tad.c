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
void empilha (Pilha *a, int id)
{
    TipoCelula *q = malloc(sizeof(TipoCelula));
    q->val = id;
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
    TipoCelula *q = a->topo;
    int i;
    printf("Do topo ao fundo:\n");
    for (i=0;i<a->qtd;i++)
    {
        printf("%d\n", q->val);
        q = q->ant;       
    }
}
int retRem (Pilha *a)
{
    int ret;
    ret = a->topo->val;
    desempilha (a);
    return ret;
}
void infoPilha (Pilha *a)
{
    Pilha aux;
    TipoCelula *q;
    int i, n, som=0, mai, men;
    double media;
    q = a->topo;
    init (&aux);
    for (i=0;i<a->qtd;i++) // Copiando a pilha recebida para a auxiliar
    {
        empilha (&aux,q->val);
        q = q->ant;
    }
    men = aux.topo->val;
    mai = aux.topo->val;
    for (i=0;i<a->qtd;i++) // usando os valores;
    {
        q = aux.topo;
        n = retRem (&aux);
        som += n; //somandos termos para media
        if (n>mai) mai=n; // conferindo o maior termo
        if (n<men) men=n; // conferindo o menor termo
    }
    media = (double) som/a->qtd;
    printf ("Maior: %d\nMenor: %d\nMedia aritmetica: %.2lf\n", mai, men, media);
}
void invertePilha (Pilha *a) //irei desempilhar todos os termos e salva-los em um vetor, depois irei empilhar novamente (começando do primeiro a ser desempilhado), se eu desempilho e empilho eu inverto a pilha :)
{
    int vec[a->qtd]; // Vetor do tamano da quantidade de termos da pilha
    int i, qnt;
    qnt = a->qtd; //salvando a quantidade de termso da pilha
    for (i=0;i<qnt;i++) // limpando a pilha e salvando os termos em um vetor
    {
        vec[i] = retRem (a);
    } // se eu nao precisasse armazenar os valores invertidos na mesma pilha, eu poderia empilhar o desmpilhado direto, porem eu tenho que limpar a pilha e depois armazena-la para nao perder os dados
    for (i=0;i<qnt;i++)
    {
        empilha (a,vec[i]);
    }
}