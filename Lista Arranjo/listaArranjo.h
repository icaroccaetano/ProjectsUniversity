#include <stdio.h>
#include <stdlib.h>

#define INICIOARRANJO   0
#define MAXTAM          10


typedef struct {            //definindo uma struct com as informacoes a serem armazenadas
  int Chave;
  /* outros componentes */
} TipoItem;

typedef struct {            //definindo a struct que armazena o vetor
  int Item[MAXTAM];    
  int Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);
int Vazia(TipoLista Lista);
void Insere(int x, TipoLista *Lista);
void Retira(int p, TipoLista *Lista);
void Imprime(TipoLista Lista);