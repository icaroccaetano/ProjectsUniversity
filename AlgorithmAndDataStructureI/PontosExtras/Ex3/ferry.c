#include "ferry.h"

void initferry (Ferry *a, int max) /* Iniciando a balsa */
{
    a->primeiro = NULL; // primeiro recebe NULL
    a->ultimo = a->primeiro; // O ultimo aponta para o primeiro
    a->max = max; // Quantidade maxima de veiculos setada
    a->atual = 0; // Configurando que balsa esta vazia
}

int ferryvazia (Ferry *a)
{
    if (a->primeiro == NULL) return 0;
    else return 1;
}

void auxplaca (char from[7], char to[7]) /* Funcao auxiliar para passar as placas */
{
    int i;
    for (i=0;i<7;i++)
    {
        to[i] = from[i];
    }
}

int enterferry (Ferry *a, char placa[7]) /* Adicionar carro a Balsa */
{
    if (a->atual==a->max) return 1;
    TipoCelula *insert = malloc(sizeof(TipoCelula));
    if (insert)
    {
        auxplaca(placa,insert->id); // Aplicando o valor a celula
        if (ferryvazia(a) == 0) // se for o primeiro
        {
            a->primeiro = insert;
            a->ultimo = insert; // Primeiro e ultimo recebe o insert
            a->ultimo->prox = NULL;
            a->atual++; //Aumentando o contador da lista;
        }
        else
        {
            a->ultimo->prox = insert; // Adcionando no fim da Lista;
            a->ultimo = insert; // O ponteiro ultimo recebe o elemento que foi adicionado no final
            insert->prox = NULL;
            a->atual++; //Aumentando o contador da lista;
        }
    }
    else printf("Erro ao adicionar!\n");
    return 0;
}

void statusferry (Ferry *a) /* Visao geral da balsa */
{
    int i;
    ArrayFerry aux;
    aux = a->primeiro;
    for (i=0;i<=(a->atual)-1;i++)
    {
        printf("Posição %d: %s\n", i, aux->id);
        aux = aux->prox;
    }
}

void capacity (Ferry *a)
{
    printf("Capacidade atual: %d/%d\n", a->atual, a->max);
}

void removeferrypos (Ferry *a, int pos, TipoFila *Fila)
{
    int i;
    TipoCelula *q, *ant;
    char remid[7];
    if (ferryvazia(a) == 0)
    {
        printf("Falha: Balsa vazia\n");
        return;
    }
    else
    {
        if (a->atual-1<pos)
        {
            printf("Falha: posicao inexistente");
            return;
        }
        else
        {

            if (pos==0) //Caso o pra ser removido seja o primeiro
            {    
                q = a->primeiro; // q recebe p primeiro termo da lista
                a->primeiro = a->primeiro->prox; // o primeiro termo da lista vai virar o segundo (primeiro vai ser removido)
                printf("Carro posicão %d retirado (%s).\n", pos, q->id);
                free (q); //libera o q
                a->atual--;
            }
            else if (pos == (a->atual-1)) // Caso o para ser romvido seja o ultimo
            {
                q = a->ultimo;
                ant = a->primeiro;
                for (i=0;i<=(pos-1);i++)
                {
                    ant = ant->prox;
                }
                ant->prox = NULL; // O anterior recebe NULL
                a->ultimo = ant; //  o ultimo agora apontara para o anterior
                printf("Carro posicão %d retirado (%s).\n", pos, q->id);
                free (q); //libera o q
                a->atual--;
            }
            else // se nao e o ultimo nem o primeiro
            {
                q = a->primeiro;
                for (i=0;i<=(pos-1);i++)
                {
                    q = q->prox;
                } // q recebe o ponteiro a ser removido
                ant = a->primeiro;
                for (i=0;i<=(pos-2);i++) // ant recebe o ponteiro anterior
                {
                    ant = ant->prox;
                } 
                ant->prox = q->prox; //poteiro prox do anterior recebe o proximo do q;
                printf("Carro posicão %d retirado (%s).\n", pos, q->id);
                free(q); //libera o q
                a->atual--;
            }
            if (Vazia(Fila) == 1)
            {
                enterferry(a,Fila->Frente->id);
                Desenfileira(Fila);
            }
        }
    }
} 
void Inicializar(TipoFila *Fila)
{
  Fila->Frente=NULL;
  Fila->Tras = Fila->Frente;
} 
int Vazia(TipoFila *Fila)
{ 
  if(Fila->Frente == NULL) return 0;
  else return 1; 
} 
void Enfileira (Ferry *a, char x[7], TipoFila *Fila)
{
    if (a->atual < a->max) enterferry (a,x);
    else
    {
        TipoApontador novo = (TipoApontador) malloc(sizeof(TipoCelula));
        auxplaca (x,novo->id);
        novo->Prox=NULL;
        if(Fila->Frente==NULL)
        {
            Fila->Frente=novo;
        }
        else {
            Fila->Tras->Prox=novo;  
        }
        Fila->Tras = novo;
    }
} 
void Desenfileira(TipoFila *Fila)
{
  TipoApontador q;
  if (Vazia(Fila) == 0) return; 

  q = Fila->Frente;
  Fila->Frente = Fila->Frente->Prox;
  free(q);
  if (Fila->Frente==NULL)
    Fila->Tras=NULL;
} 

void Imprime(TipoFila Fila)
{
  TipoApontador Aux;
  Aux = Fila.Frente;
  while (Aux != NULL) 
    { 
      printf("%s\n", Aux->id);
      Aux = Aux->Prox;
    }
}