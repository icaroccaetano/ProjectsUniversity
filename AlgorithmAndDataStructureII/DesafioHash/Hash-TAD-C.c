#include <stdio.h>
#include "Hash-TAD-H.h"

void initList (Lista *l)
{   
    l->inicio = NULL;
    l->m = 0;
}

void listInsert (Lista *l, int x, char y[24])
{
    No *new = malloc (sizeof(No));
    new->proximo = NULL;
    new->chave = x;
    strcpy (new->nome, y);
    if (new)
    {
        new->proximo = l->inicio;
        l->inicio = new;        
        l->m++;
    }
    else printf ("\n\tErro ao alocar memoria!\n");
}

void listSearch (Lista *l, int x)
{
    //int i = 0;
    ApontadorNo aux = l->inicio;
    while (aux && aux->chave != x)
    {
        //i += 2;
        aux = aux->proximo;
    }
    //i += 2;
    if (aux)
        printf ("\n\tEncontrado: %s (mat: %d)\n", aux->nome,aux->chave);
        return;
    printf ("\n\tMatricula nao encontrada!\n");
}

void listPrint (Lista *l)
{
    ApontadorNo aux = l->inicio;
    printf (" m: %d: ", l->m);
    while (aux)
    {
        printf("%s-%d | ", aux->nome ,aux->chave);
        aux = aux->proximo;
    }
}

void initTable (Lista *t)
{
    int i;
    for (i=0;i<M;i++)
        initList (&t[i]);
}

int FuncaoHash (int x)
{
    return ((((x*11)/3)*7)%M); 
}

void hashInsert (Lista *t, int x, char y[24])
{
    int id = FuncaoHash(x);
    listInsert (&t[id], x, y);
}

void hashSearch (Lista *t, int x)
{
    int id = FuncaoHash(x);
    listSearch (&t[id], x);
    return;
}

void hashPrint (Lista *t)
{
    int i;
    for (i=0;i<M;i++)
    {
        printf ("%2d = ", i);
        listPrint (&t[i]);
        printf ("\n");
    }
}

int CriaHash(Lista *t)
{
    int mat;
    char nome [24];
    while(1)
    {
        if (scanf ("%d;%[^\n]%*c", &mat, &nome) == EOF) break;
        hashInsert(t,mat,nome);
    }
    return 0;
}

int BuscaHash(Lista *t, int chave, float media)
{
    // Aqui COMEÇA a Implementação de sua função HASH
    printf("\n");
    int j = 0;
    printf("Implemente aqui sua funcao HASH %f, buscando a chave: %d", media, chave);
    for (j = 0; j < 25; j++)
        printf(".");
    return 0;
    // Aqui TERMINA a Implementação de sua função HASH
}
