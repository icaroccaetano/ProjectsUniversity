#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

/*
    aprendendo tabela hash com Programe seu futuro
    vou usar uma tabela com lista encadeada
    15 elementos
*/
// M = 1,75 * 1000 = 2000, usarei M = 1747; (primo)

#define M 1451
#define VAZIO 0

typedef struct No
{
    int chave;
    char nome[24];
    struct no *proximo;
} No;

typedef struct No *ApontadorNo;

typedef struct 
{
    ApontadorNo inicio;
    int m;
}Lista;

void initList (Lista *l);
void listInsert (Lista *l, int x, char y[24]);
void listSearch (Lista *l, int x);
void listPrint (Lista *l);
int FuncaoHash (int x);
void initTable (Lista *t);
void hashInsert (Lista *t, int x, char y[24]);
void hashSearch (Lista *t, int x);
void hashPrint (Lista *t);


#define GET_MS(ini, fim) ((fim.tv_sec * 1000000 + fim.tv_usec) - (ini.tv_sec * 1000000 + ini.tv_usec))
struct timeval inicio, fim;

int main()
{
    int mat;
    char nome [24];
    Lista tab[M];
    while(1)
    {
        if (scanf ("%d;%[^\n]%*c", &mat, &nome) == EOF) break;
        hashInsert(tab,mat,nome);
    }
    printf("\tPesquise por matricula: ");
    scanf("%d", &mat);
    gettimeofday(&inicio, NULL);
    hashSearch (tab,9859358);
    hashSearch (tab,1602121);
    hashSearch (tab,3068552);
    hashSearch (tab,7161063);
    hashSearch (tab,9831061);
    //printf("\tEndereco %d: %s\n", mat, hashSearch (tab,6591507));
    gettimeofday(&fim, NULL);
    printf("\n\tTempo de execução: %ld ms\n\n", GET_MS(inicio, fim));
    return 0;
}

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
    int i = 0;
    ApontadorNo aux = l->inicio;
    while (aux && aux->chave != x)
    {
        i += 2;
        aux = aux->proximo;
    }
    i += 2;
    if (aux)
        printf ("\n\tEncontrado: %s (mat: %d)\n\tComparacoes feitas: %d\n", aux->nome,aux->chave, i);
        return;
    printf ("\n\tMatricula nao encontrada!\n\tComparacoes feitas: %d\n", i);
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