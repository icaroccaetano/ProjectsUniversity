#include "listaArranjo.h"
#define MAX 10

void FLVazia(TipoLista *Lista)              // inicializacao da lista
{ Lista -> Primeiro = INICIOARRANJO;        //apontar para o primeiro elemento
  Lista -> Ultimo = Lista -> Primeiro;      //atribuir o ultimo elemento para o primeiro
}  /* FLVazia */

int Vazia(TipoLista Lista)                  //verificar se a lista esta vazia
{ return (Lista.Primeiro == Lista.Ultimo);
}  /* Vazia */

void Insere(int x, TipoLista *Lista)   //realizar a insercao de elementos
{ if (Lista -> Ultimo >= MAXTAM) 
    printf("Lista esta cheia\n");  //se a lista estiver cheia
  else {
    Lista -> Item[Lista -> Ultimo] = x;      //caso a lista nao estiver cheia
    Lista -> Ultimo++;
  }
}  /* Insere */

void Retira(int p, TipoLista *Lista) //realizar a remocao de elementos
{ int Aux;
      // considerando que o usuario ira inserir valores entre 1 ate o valor final
  if (Vazia(*Lista) || (p-1) >= Lista -> Ultimo || p < 0)   //se lista vazia ou p maior que ultimo ou p menor que zero
  {
    printf(" Erro   Posicao nao existe\n");
  }
  else{                                             //se a posicao for valida
    Aux = Lista->Item[p-1];
    printf("O valor removido e: %d.\n",Aux);        //imprime o elemento a ser removido
    //printf("O valor removido e: %d.\n",Lista->Item[p-1]);        
    for (Aux = p; Aux < Lista -> Ultimo; Aux++)     //reordenar o vetor
      Lista -> Item[Aux - 1] = Lista -> Item[Aux];
    Lista -> Ultimo--;
  }
}  /* Retira */

void Imprime(TipoLista Lista)
{ int Aux;
  for (Aux = Lista.Primeiro; Aux <= (Lista.Ultimo - 1); Aux++)
    printf("%d\n", Lista.Item[Aux]);
}  /* Imprime */