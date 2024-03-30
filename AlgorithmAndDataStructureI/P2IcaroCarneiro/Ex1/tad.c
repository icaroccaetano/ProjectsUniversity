/* ICARO CARNEIRO CAETANO CHEREDNIKOV 202103732 :)*/ 
#include "tad.h"

void init (Lista *a)              // inicializa a lista
{ 
    a->qnt = 1;        //quantidade de termos recebe 0    
}  

int empty (Lista *a)                  //verifica se a lista esta vazia
{
    if (a->qnt == 1) return 0;
    else return 1;
} 

void add (int x, char *nome, Lista *a)   //insere elementos (no caso produtos)
{ 
    if (a->qnt >= MAX) 
    {
        printf("ERRO: Lista esta cheia\n");  //se a lista estiver cheia
        return;
    }
    else 
    {
        strcpy (a->item[a->qnt].nome,nome); //copia o nome do produto
        a->item[a->qnt].cod = x; //copia o cod do produto
        a->qnt++; //quantidade de termos ++
    }
}

void remve (int cod, Lista *a) //remove o primeiro elemento com determinado cod
{
    int i, aux, pos; 
    if (empty(a) == 0)   //se lista vazia
    {
        printf("ERRO: Lista vazia\n");
        return;
    }
    else
    {         
        for (i=1;i<a->qnt;i++)
        {
            if (a->item[i].cod = cod) // buscando a posicao do produto a ser removido
            {
                break;
            } 
            if (i = a->qnt-1) // se chegar no ultimo e ele nao for igual significa que o codigo digitado nao existe na lista
            {
                if (a->item[i].cod != cod)
                {
                    printf("ERRO: Codigo de produto invalido para remocao\n");
                    return;
                }
            }
        }
        printf("Produto removido:%s (%d)\n",a->item[i].nome, a->item[i].cod); //imprime o elemento a ser removido     
        for (aux=i+1;aux<a->qnt;aux++)  //reordenar o a->item
        {
            a->item[aux-1].cod = a->item[aux].cod;
            strcpy(a->item[aux-1].nome,a->item[aux].nome);
        }
        a->qnt--; // quantidade de termos da lista--
    } 
}
void print (Lista *a) //printa a lista
{
    int i; 
    for (i=1;i<a->qnt;i++) //percorre a lista dando printf
    {
        printf("%s - %d\n", a->item[i].nome, a->item[i].cod);
    }
}

void swaprod (Lista *a, int p1, int p2) //faz a troca entre dois produtos
{
    int naux;
    char caux[36];
    naux = a->item[p1].cod; //irei usar as auxiliares para fazer o swap
    strcpy (caux,a->item[p1].nome);
    a->item[p1].cod = a->item[p2].cod;
    strcpy (a->item[p1].nome,a->item[p2].nome);
    a->item[p2].cod = naux;
    strcpy (a->item[p2].nome,caux);


}

void selectionsort (Lista *a)
{
    int i, j, men;
    for (i=1;i<a->qnt;i++) //corre o vetor - marca a posicao atual
    {
        men = i; // menor comeca valendo a pos atual
        for (j=i+1;j<a->qnt;j++) // vai ver qual e o menor da atual pra frente
        {
            if (a->item[j].cod < a->item[men].cod) men = j;
        }
        swaprod (a,i,men); // vai colocar o menor na pos atual (i)
    }
}

void insertionsort (Lista *a) //usa o metodo insertion sort para ordenar de acordo com o cod
{
    int i, j, aux;

    for (i=2;i<a->qnt;i++) //irei rodar o vetor
    {
        aux = a->item[i].cod;
        j = i - 1;
        while (j>=0&&aux<a->item[j].cod) //irei comparar o cod com o cod do produto da esquerda e trocar caso seja menor
        {
            swaprod (a,j,j+1);
            j--;
        }
    
    }
}

int binaria (int cod, Lista *a) // faz a busca binaria e retorna a posicao (lista ja ordenada)
{
    int i, Esq, Dir;
    if (empty(a)==0) //se for vazia sai
    {
        printf ("ERRO AO PESQUISAR - Lista Vazia\n");
        return 0;
    }
    else 
    {
        Esq = 1; //esquerda e direita começam no inicio e final do vetor (respectivamente)
        Dir = a->qnt-1;
        do 
        {
            i = (Esq + Dir) / 2;
            if (cod > a->item[i].cod)
            Esq = i + 1;
            else
            Dir = i - 1;
        } while (cod != a->item[i].cod && Esq <= Dir);
        
        if (cod == a->item[i].cod) return (i-1); //ele devolve i-1 so por conta do vetor ser organizado para receber tambem o search sequencial
        else
        {
            return 0;
        } //se voltar 0 e pq nao achou, mesmo padrao da sequencial pra ficar uniforme
    }
}


int sequencial (int cod, Lista *a) //faz a pesquisa sequencial e devolve a posicao do procurado
{
    int i;
    a->item[0].cod = cod;
    i = a->qnt + 1;
    do {i--;} while (a->item[i].cod != cod);
    return i;
}
int comparelists (Lista *a, Lista *b)
{
    int aux=0, i, j, areps=0;
    char reps[36][200];
    printf ("Produtos repetidos em ambas as listas:\n");
    for (i=1;i<a->qnt;i++) //irei rodar a lista toda e conferir se todos os elementos se repetem (se todos se repetirem => lista igual)
    {
        j = binaria (a->item[i].cod,b);
        if (j==0) //se eu nao achar algum cod na outra lista ja fica marcado que as listas nao sao iguais 
        {
            aux ++;
            continue;
        }
        printf ("Repetido: %s - %d\n", b->item[j].nome, b->item[j].cod);
    }
    if (aux==0) printf ("=> LISTAS IGUAIS\n");
    else printf ("=>LISTAS DIFERENTES\n");
}