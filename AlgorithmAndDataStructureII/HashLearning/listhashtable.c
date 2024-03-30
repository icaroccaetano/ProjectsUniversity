#include <stdio.h>
#include <stdlib.h>

/*
    aprendendo tabela hash com Programe seu futuro
    vou usar uma tabela com lista encadeada
    15 elementos
*/
// M = 2 * 15 = 30, usarei M = 31; (primo)

#define TAM 31
#define VAZIO -1

typedef struct No
{
    int chave;
    struct no *proximo;
} No;

typedef struct No *ApontadorNo;

typedef struct 
{
    ApontadorNo inicio;
    int tam;
}Lista;

void initList (Lista *l);
void listInsert (Lista *l, int x);
int listSearch (Lista *l, int x);
void listPrint (Lista *l);

void initTable (Lista *t);
int hashFunction (int x);
void hashInsert (Lista *t, int x);
int hashSearch (Lista *t, int x);
void hashPrint (Lista *t);

int main (void)
{
    int op, valor;
    Lista tabela[TAM];

    initTable (tabela);
    do
    {
        printf ("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Buscas\n\t3 - Imprimir\n");
        scanf ("%d", &op);
        switch (op)
        {
        case 1:
            printf ("Qual valor deseja inserir? ");
            scanf ("%d", &valor);
            hashInsert (tabela, valor);
            break;
        case 2:
            printf ("\tQual valor deseja buscar? ");
            scanf ("%d", &valor);
            valor = hashSearch (tabela, valor);
            if (valor != VAZIO)
                printf ("\tEncontrado: %d\n", valor);
            else printf ("\tNao encontrado!\n");
            break;
        case 3:
            hashPrint (tabela);
            break;
        default:
            break;
        }
    } while (op != 0);
    return 0;    
}

void initList (Lista *l)
{   
    l->inicio = NULL;
    l->tam = 0;
}

void listInsert (Lista *l, int x)
{
    No *new = malloc (sizeof(No));
    new->proximo = NULL;
    new->chave = x;
    if (new)
    {
        new->proximo = l->inicio;
        l->inicio = new;        
        l->tam++;
    }
    else printf ("\n\tErro ao alocar memoria!\n");
}

int listSearch (Lista *l, int x)
{
    ApontadorNo aux = l->inicio;
    while (aux && aux->chave != x)
        aux = aux->proximo;
    if (aux)
        return aux->chave;
    return VAZIO;
}

void listPrint (Lista *l)
{
    ApontadorNo aux = l->inicio;
    printf (" Tam: %d: ", l->tam);
    while (aux)
    {
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }
}

void initTable (Lista *t)
{
    int i;
    for (i=0;i<TAM;i++)
        initList (&t[i]);
}

int hashFunction (int x)
{
    return ((((x*11)/3)*7)%TAM); 
}

void hashInsert (Lista *t, int x)
{
    int id = hashFunction(x);
    listInsert (&t[id], x);
}

int hashSearch (Lista *t, int x)
{
    int id = hashFunction(x);
    return listSearch (&t[id], x);
}

void hashPrint (Lista *t)
{
    int i;
    for (i=0;i<TAM;i++)
    {
        printf ("%2d = ", i);
        listPrint (&t[i]);
        printf ("\n");
    }
}