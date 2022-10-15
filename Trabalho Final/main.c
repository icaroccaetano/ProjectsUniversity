/*
  GRUPO: EDUARDO LOZANO AZEVEDO 
         LUAN DIAS CARDOSO
         ICARO CARNEIRO CHEREDNIKOV
*/

#include "tad.h"
#define N 100

int main(void) {

  FILE *code;
  char linha[N], aux_linha[N];
  char *r;
  Lista ListaReservadas;
  Lista ListaTipos;
  Lista ListaVar;
  Pilha par, cha, col;
  int cont_linhas = 0;
  int cont_erros = 0;

  //======================= TESTE DE FUNÇÕES =======================//
  char *str = "              Muitos espacos";
  Start(&ListaReservadas, &ListaTipos, &ListaVar, &par, &cha, &col);
  // imprimeLista(&ListaReservadas);
  // buscaPalavra_Chave("return", &ListaTipos);

  // printf("%s\n", str);
  // str = LimpaEspacos(str);
  // printf("%s\n", str);
  //================================================================//

  code = fopen("code.txt", "r");
  if (!code)
    exit(1);

  printf("\n");
  while (!feof(code)) {
    cont_linhas++;
    r = fgets(linha, 100, code);

    if (r) {
      strcpy(aux_linha, linha);
      cont_erros += Verifica_Reservadas(linha, &ListaReservadas, &ListaTipos,
                                        &ListaVar, cont_linhas);
      parenteses(linha, &par, &cha, &col, cont_linhas);
      conferePV(aux_linha, cont_linhas, &ListaReservadas);
    }
  }
  conferepar(&par, &cha, &col);
  printf("\n--------FIM---------\n\n");
  return 0;
}
