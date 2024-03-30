#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

/*
    aprendendo tabela hash com Programe seu futuro
    vou usar uma tabela com lista encadeada
    15 elementos
*/
// M = 1,85 * 20000 = 37000, usarei M = 37003; (primo)

#define M 37003
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
int CriaHash(Lista *t);
int BuscaHash (Lista *t, int chave, float media);

#define GET_MS(ini, fim) ((fim.tv_sec * 1000000 + fim.tv_usec) - (ini.tv_sec * 1000000 + ini.tv_usec))
struct timeval inicio, fim;

int vetor_hash[20000];
char nome_hash[20000][20];
