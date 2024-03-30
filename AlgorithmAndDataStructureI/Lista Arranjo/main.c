#include <stdio.h>
#include <stdlib.h>
#include "listaArranjo.h"

int main(int argc, char *argv[])
{

  TipoLista lista;
  //TipoItem item;
  int vetor[MAXTAM];
  int i, j, k, n, max, valor;
  max = 5;
  FLVazia(&lista);

  for (i = 0; i < max; i++){
    printf("Digite um valor: ");
    scanf("%d",&valor);
    Insere(valor,&lista);
  }
  
  Imprime (lista);
  //valor = 2;

  while(i!=0){
    printf("Informe a posicao do valor a ser removido (digite 0 para sair): ");
    scanf("%d", &i);
    Retira(i, &lista);
  }
  
  Imprime (lista);
  return(0);
}