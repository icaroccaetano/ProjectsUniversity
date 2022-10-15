#include "tad.h"

void criaLista (ListaNomes *a) //crialista
{
    a->qnt = 0;
}
int vaziaLista (ListaNomes *a) //confere se esta vazia
{
    if (a->qnt == 0) return 0;
    else return 1;
} 
void addLista (char *x, ListaNomes *a) //adiciona um nome na lista
{
    int i=0;
    if (a->qnt >= nmax) 
    {
        printf("ERRO: Lista esta cheia\n");  //se a lista estiver cheia
        return;
    }
    else 
    {
        a->cel[a->qnt].nome = (char *)malloc( strlen (x) * sizeof(char));
        a->qnt++; //quantidade de termos ++
        while (x[i] != '\0')
        {
            a->cel[a->qnt-1].nome[i] = x[i];
            i++;
        }
        printf("Adicionado: \"%s\".\n", a->cel[a->qnt-1].nome);//copia o nome
    }
}
void encerra (ListaNomes *a) // encerra o programa (faz os free)
{
    int i;
    printf ("Encerrando programa...");
    for (i=0;i<a->qnt;i++)
    {
        free(a->cel[i].nome);
    }
    printf ("\n:)\n");
}
void swap (ListaNomes *a, int p1, int p2) //faz o swap entre duas posicoes
{
    char *aux;
    int i=0;

    aux = (char *)malloc( strlen (a->cel[p1].nome) * sizeof(char));
    while (a->cel[p1].nome[i] != '\0') // p1 -> aux
    {
        aux[i] = a->cel[p1].nome[i];
        i++;
    }
    memset (a->cel[p1].nome,0, strlen (a->cel[p1].nome)); //limpando o vetor
    i=0;
    while (a->cel[p2].nome[i] != '\0') // p2 -> p1
    {
        a->cel[p1].nome[i] = a->cel[p2].nome[i];
        i++;
    }
    memset (a->cel[p2].nome,0, strlen (a->cel[p2].nome)); //limpando o vetor
    i=0;
    while (aux[i] != '\0') // aux -> p2
    {
        a->cel[p2].nome[i] = aux[i];
        i++;
    }
    free (aux);
}
void ordLista (ListaNomes *a) //funcao do ex1 - Vai ordenar a lista de acordo com o tamanho
{
    int i, j, men;
    for (i=0;i<a->qnt;i++)
    {

        men = i; //menor comeca com o valor de i
        for (j=i;j<a->qnt;j++)
        {
            if (strlen(a->cel[j].nome) < strlen(a->cel[i].nome)) men = j; // sempre que for menor vou ressalvar o menor
        }
        swap (a,i,men);
    }
}
void printLista (ListaNomes *a) //printa a lista
{
    int i;
    for (i=0;i<a->qnt;i++)
    {
        printf ("%s\n", a->cel[i].nome);
    }
}