#include "tad.h"

// PILHAS PARA ABERTURA E FECHAMENTOS
// empilhar(Pilha* pilha, char c);
// desempilhar(Pilha* pilha);

// FUNÇOES PARA COMPARAR PALAVRAS RESERVADAS COM AS LISTAS
// compara(char* string, Lista* palavrasReservadas)
void Inicia_Lista(Lista *ListaReservadas) {

  ListaReservadas->First = NULL;
  ListaReservadas->Last = ListaReservadas->First;
}

void Insere_Lista(char *palavra, Lista *ListaReservadas) {

  TipoApontador PC = (TipoApontador)malloc(sizeof(TipoCelula));

  strcpy(PC->PalavraChave.reservada, palavra);

  PC->Next = NULL;
  if (ListaReservadas->First == NULL) {
    ListaReservadas->First = PC;
  } else {
    ListaReservadas->Last->Next = PC;
  }

  ListaReservadas->Last = PC;
}

void Cria_ListaPalavrasChave(Lista *ListaReservadas) {

  Inicia_Lista(ListaReservadas);
  Insere_Lista("break", ListaReservadas);
  Insere_Lista("case", ListaReservadas);
  Insere_Lista("char", ListaReservadas);
  Insere_Lista("const", ListaReservadas);
  Insere_Lista("default", ListaReservadas);
  Insere_Lista("do", ListaReservadas);
  Insere_Lista("double", ListaReservadas);
  Insere_Lista("else", ListaReservadas);
  Insere_Lista("float", ListaReservadas);
  Insere_Lista("for", ListaReservadas);
  Insere_Lista("goto", ListaReservadas);
  Insere_Lista("if", ListaReservadas);
  Insere_Lista("int", ListaReservadas);
  Insere_Lista("long", ListaReservadas);
  Insere_Lista("return", ListaReservadas);
  Insere_Lista("short", ListaReservadas);
  Insere_Lista("signed", ListaReservadas);
  Insere_Lista("sizeof", ListaReservadas);
  Insere_Lista("static", ListaReservadas);
  Insere_Lista("struct", ListaReservadas);
  Insere_Lista("switch", ListaReservadas);
  Insere_Lista("typedef", ListaReservadas);
  Insere_Lista("unsigned", ListaReservadas);
  Insere_Lista("void", ListaReservadas);
  Insere_Lista("while", ListaReservadas);
}

void imprimeLista(Lista *ListaReservadas) {

  TipoApontador Aux;
  Aux = ListaReservadas->First;

  while (Aux != NULL) {

    printf("%s\n", Aux->PalavraChave.reservada);

    Aux = Aux->Next;
  }
}

int buscaLista(char *palavra, Lista *ListaReservadas) {

  TipoApontador Aux;
  int boo;
  Aux = ListaReservadas->First;

  while (Aux != NULL) {

    boo = strcmp(palavra, Aux->PalavraChave.reservada);

    if (boo == 0) {
      // printf("Palavra chave %s valida!\n", Aux->PalavraChave.reservada);
      return 1;
    }

    Aux = Aux->Next;
  }

  // printf("Palavra chave %s invalida!\n", palavra);
  return 0;
}

void Cria_ListaTipo(Lista *ListaTipos) {

  Inicia_Lista(ListaTipos);
  Insere_Lista("char", ListaTipos);
  Insere_Lista("const", ListaTipos);
  Insere_Lista("double", ListaTipos);
  Insere_Lista("float", ListaTipos);
  Insere_Lista("int", ListaTipos);
  Insere_Lista("long", ListaTipos);
  Insere_Lista("short", ListaTipos);
  Insere_Lista("signed", ListaTipos);
  Insere_Lista("unsigned", ListaTipos);
}

void Start(Lista *ListaReservadas, Lista *ListaTipos, Lista *ListaVar,
           Pilha *par, Pilha *cha, Pilha *col) {

  Cria_ListaPalavrasChave(ListaReservadas);
  Cria_ListaTipo(ListaTipos);
  Inicia_Lista(ListaVar);
  criaPilha(par);
  criaPilha(cha);
  criaPilha(col);
}

int Verifica_Reservadas(char *linha, Lista *ListaReservadas, Lista *ListaTipos,
                        Lista *ListaVar, int cont_linha) {

  printf("\nAnalisando linha %d: %s\n", cont_linha, linha);

  linha = LimpaEspacos(linha);

  if (linha[0] == '#' || linha[0] == '\n' || linha[0] == '}' || linha[0] == '/')
    return 0;

  char *p;

  p = strtok(linha, " ;=+-({[");
  if (p == NULL) {
    printf("----- ERRO: Erro na linha %d! -----\n", cont_linha);
    return 1;
  }

  // printf("%s\n", p);

  if (buscaLista(p, ListaReservadas) == 1) {

    if (buscaLista(p, ListaTipos) == 1) {

      p = strtok(NULL, " ;=+({[");
      // printf("%s\n", p);
      if (strcmp(p, "main") == 0) {
        return 0;
      } else {

        if (buscaLista(p, ListaReservadas) == 1) {
          printf("----- ERRO: Erro na linha %d! Atribuindo nome de palavra reservada a "
                 "variavel! -----\n",
                 cont_linha);
          return 1;
        }
        Insere_Lista(p, ListaVar);
        // printf("Variavel %s criada!\n", p);
      }
    }

  } else if (buscaLista(p, ListaVar) == 0) {
    printf("----- ERRO: Erro na linha %d! -----\n", cont_linha);
    return 1;
  }
  return 0;
}

char *LimpaEspacos(char *linha) {
  if (linha[0] != 32) {
    return linha;
  } else {
    linha = strpbrk(
        linha, "abcdefghijklmnopqrstuvxwyzABCDEFGHIJKLMNOPQRSTUVXWYZ()[]{}#\n");
  }

  return linha;
}

void criaPilha(Pilha *p) { p->tam = 0; }
int pilhavazia(Pilha *p) {
  if (p->tam == 0)
    return 0;
  else
    return 1;
}
void empilha(Pilha *p, int x) {
  NoPilha *novo;

  novo = malloc(sizeof(struct NoPilha));
  novo->linha = x;
  novo->prox = NULL;

  if (p->tam == 0) // se a pilha esta vazia
  {
    novo->ant = NULL;
    p->topo = novo;
  } else {
    novo->ant = p->topo;
    p->topo->prox = novo;
    p->topo = novo;
  }
  p->tam++;
  return;
}
int desempilha(Pilha *p) {
  int r;
  NoPilha *apaga;

  apaga = p->topo;
  r = apaga->linha;
  p->topo = apaga->ant;
  free(apaga);
  p->tam--;
  return r;
}

void parenteses(char *linha, Pilha *par, Pilha *cha, Pilha *col,
                int cont_linha) {
  int i = 0;
  // linha = LimpaEspacos(linha);

  while (linha[i] != '\n') {
    /*
    ( -> 40
    ) -> 41
    { -> 123
    } -> 125
    [ -> 91
    ] -> 93
    */
    // printf("ANALISANDO -> /%c/\n", linha[i]);

    if ((int)linha[i] == 40) {
      empilha(par, cont_linha);
    }
    if ((int)linha[i] == 41) {
      if (par->tam <= 0)
        printf("----- ERRO: parenteses fechada sem antes abrir na linha %d -----\n",
               cont_linha);
      else
        desempilha(par);
      ;
    }
    if ((int)linha[i] == 123) {
      empilha(cha, cont_linha);
    }
    if ((int)linha[i] == 125) {
      if (cha->tam <= 0)
        printf("----- ERRO: chaves fechada sem antes abrir na linha %d -----\n",
               cont_linha);
      else
        desempilha(cha);
    }
    if ((int)linha[i] == 91) {
      empilha(col, cont_linha);
    }
    if ((int)linha[i] == 93) {
      if (col->tam <= 0)
        printf("----- ERRO: colchetes fechado sem antes abrir na linha %d -----\n",
               cont_linha);
      else
        desempilha(col);
    }

    i++;
  }
  return;
}
void conferepar(Pilha *par, Pilha *cha, Pilha *col) {
  if (pilhavazia(par) != 0) {
    while (pilhavazia(par) != 0) {
      printf("----- ERRO: parenteses nao fechado em linha %d -----\n", desempilha(par));
    }
  }
  if (pilhavazia(cha) != 0) {
    while (pilhavazia(cha) != 0) {
      printf("----- ERRO: chaves nao fechada em linha %d -----\n", desempilha(cha));
    }
  }
  if (pilhavazia(col) != 0) {
    while (pilhavazia(col) != 0) {
      printf("----- ERRO: colchete nao fechada em linha %d -----\n", desempilha(col));
    }
  }
}

void conferePV(char *linha, int cont_linhas, Lista *ListaReservadas) {
    int i = 0, lastIndex, cont = 0, aux = -1;
    char *ret1, *ret2;

    while(linha[i] != '\n') i++;  //achamos o indice do \n
    lastIndex = i - 1; //o indice do ultimo char antes do \n


    i = 0;
    while(linha[i] != '\n') {
        if(linha[i] == 'f' && linha[i+1] == 'o' && linha[i+2] == 'r') {
            aux = buscaLista("for ", ListaReservadas); //se tiver for, aux recebe 0
            break;
        }
        i++;
    }
    if(aux == 0) {
        if(linha[lastIndex] == ';') {
            i = 0;
            while(linha[i] != '\n') {
                if(linha[i] == ';') cont++;
                i++;
            }
            if(cont != 3) printf("----- ERRO: ; na linha %d -----\n", cont_linhas);
        }
    }
    else if(linha[0] == '#' && linha[lastIndex] == ';') {
        printf("----- ERRO: ; na linha %d -----\n", cont_linhas);
    }
    else if(linha[lastIndex] == ';' && (linha[lastIndex-1] == '{' || linha[lastIndex-1] == '}')) {           
        printf("----- ERRO: ; na linha %d -----\n", cont_linhas);
    }
    else if(linha[lastIndex] == ';' && linha[lastIndex-1] == ';') {
        printf("----- ERRO: ; na linha %d -----\n", cont_linhas);
    }
    else {
        ret1 = strpbrk(linha, "abcdefghijklmnopqrstuvwyz1234567890[]{}();<>#+-=*");
        if(ret1 == NULL) return;

        ret2 = strpbrk(linha, ";{}#");
        if(ret2 == NULL) {
            printf("----- ERRO: ; na linha %d -----\n", cont_linhas);
        }
    }

}