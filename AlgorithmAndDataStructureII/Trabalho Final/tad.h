#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NoPilha {
  int linha;
  struct NoPilha *prox;
  struct NoPilha *ant;
} NoPilha;

typedef struct Pilha {
  NoPilha *topo;
  int tam;
} Pilha;

typedef struct TipoPalavraChave {

  char reservada[50];

} TipoPalavraChave;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {

  TipoPalavraChave PalavraChave;
  TipoApontador Next;

} TipoCelula;

typedef struct Lista {

  TipoApontador First, Last;

} Lista;

//---------------- Lista de tipos de variáveis ---------------- //

void Cria_ListaTipo(Lista *ListaTipos);

//------------------------------------------------------------- //

//---------------- Lista de Palavras Reservadas ---------------- //

void Inicia_Lista(Lista *ListaReservadas); // Inicializa lista

void Insere_Lista(char *palavra,
                  Lista *ListaReservadas); // Insere uma string na lista

void Cria_ListaPalavrasChave(Lista *ListaReservadas);

void imprimeLista(Lista *ListaReservadas);

int buscaLista(char *palavra,
               Lista *ListaReservadas); // Retorna 1 se tiver achado e 0 se não

//---------------------------------------------------------------//

//--------------------- Função START ---------------------//

void Start(Lista *ListaReservadas, Lista *ListaTipos, Lista *ListaVar,
           Pilha *par, Pilha *cha, Pilha *col);

//--------------------------------------------------------//

//-------------------- Funções Palavras Reservadas --------------------//

int Verifica_Reservadas(
    char *linha, Lista *ListaReservadas, Lista *ListaTipos, Lista *ListaVar,
    int cont_linha); // Retorna 0 se não houver erros, retorna 1 se   houver

char *LimpaEspacos(char *linha); // Limpa os espaços à esquerda da string

//---------------------------------------------------------------------//

//---------------------Funções para Pilhas-----------------------------//

void criaPilha(Pilha *p);
int pilhavazia(Pilha *p);
void empilha(Pilha *p, int x);
int desempilha(Pilha *p);

//---------------------------------------------------------------------//

//-----------------Funções para Parenteses, etc------------------------//

void parenteses(char *linha, Pilha *par, Pilha *cha, Pilha *col,
                int cont_linha);
void conferepar(Pilha *par, Pilha *cha, Pilha *col);

//---------------------------------------------------------------------//

//-----------------Funções para Ponto e Vírgula------------------------//

void conferePV(char *linha, int cont_linhas, Lista *ListaReservadas);

//---------------------------------------------------------------------//
