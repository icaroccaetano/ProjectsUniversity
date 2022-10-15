#include <stdio.h>
#include <stdlib.h>
/*
    aprendendo tabela hash com Programe seu futuro
    vou usar uma tabela com vetor
    15 elementos
*/
// M = 2 * 15 = 30, usarei M = 31; (primo)
#define TAM 31
#define VAZIO -1

void initTable (int *t);
int hashFunction (int x);
void insert (int *t, int x);
int search (int *t, int x);
void hashPrint (int *t);

int main (void)
{
    int op, valor, tabela[TAM];

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
            insert (tabela, valor);
            break;
        case 2:
            printf ("\tQual valor deseja buscar? ");
            scanf ("%d", &valor);
            valor = search(tabela, valor);
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

void initTable (int *t)
{
    int i;
    for (i=0;i<TAM;i++)
        t[i] = VAZIO;
}

int hashFunction (int x)
{
    return (x%TAM); 
}

void insert (int *t, int x)
{
    int id = hashFunction(x);
    while (t[id] != VAZIO)
        id = hashFunction(id+1);
    t[id] = x;
}

int search (int *t, int x)
{
    int id = hashFunction(x);
    while (t[id] != VAZIO)
    {
        if (t[id] == x) return t[id];
        else id = hashFunction(id+1);
    }
    return VAZIO;
}

void hashPrint (int *t)
{
    int i;
    for (i=0;i<TAM;i++)
        printf("%d = %d\n", i, t[i]);
}