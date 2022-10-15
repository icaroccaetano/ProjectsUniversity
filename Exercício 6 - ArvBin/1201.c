/*ICARO CARNEIRO 202103732*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    char valor;
    struct No *esquerda;
    struct No *direita;
    
} No;

int espaco;

void criarArvore (No **pRaiz);
void insercao (No **pRaiz, int numero);
void exibirEmOrdem (No *pRaiz);
void exibirPreOrdem (No *pRaiz);
void exibirPosOrdem (No *pRaiz);
int busca (No *pRaiz, char x);
No *remover (No *r, int v);

int main (void)
{
    No *raiz;
    char funcao[10];
    char compare[10];
    char val;
    criarArvore (&raiz);
    while (scanf("%s%*c", funcao) != EOF)
    {
        //if (scanf("%s%*c", funcao) == EOF) break;
        //strcpy("I",compare);
        if (strcmp(funcao,"I") == 0)
        {
            scanf ("%c", &val);
            insercao (&raiz,val);
        }
        //strcpy("PREFIXA",compare);
        if (strcmp(funcao,"PREFIXA") == 0)
        {
            espaco = 1;
            exibirPreOrdem (raiz);
            printf("\n");
        }
        //strcpy("INFIXA",compare);
        if (strcmp(funcao,"INFIXA") == 0)
        {
            espaco = 1;
            exibirEmOrdem (raiz);
            printf("\n");
        }
        //strcpy("POSFIXA",compare);
        if (strcmp(funcao,"POSFIXA") == 0)
        {
            espaco = 1;
            exibirPosOrdem(raiz);
            printf("\n");
        }
        //strcpy("P",compare);
        if (strcmp(funcao,"P") == 0)
        {
            scanf ("%c", &val);
            switch (busca(raiz,val))
            {
            case 0:
                printf("%c existe\n", val);
                break;
            
            default:
                printf ("%c nao existe\n",val);
                break;
            }
        }
        //strcpy("R",compare);
        if (strcmp(funcao,"R") == 0)
        {
            scanf ("%c", &val);
            remover (raiz,val);
        }
    }
    return 0;
}

void criarArvore (No **pRaiz)
{
    *pRaiz = NULL;
}
void insercao (No **pRaiz, int numero)
{
    if (*pRaiz == NULL) //se estiver vazio e vou alocar o numero la
    {
        *pRaiz = (No *)malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->valor = numero;
    }
    else // se ja tiver algum numero na raiz eu vou mandar ele pra esquerda ou pra direita
    {
        //Se for menor que o valor da raiz, vai pra esquerda dele. faço isso chamando a inseercao denovo em praiz->esquerda, se for maior, vai pra direita
        if (numero < ((*pRaiz)->valor))
        {    
            insercao (&((*pRaiz)->esquerda), numero);
        }
        else
        {
            insercao (&((*pRaiz)->direita), numero);
        }
    }
}
void exibirEmOrdem (No *pRaiz)
{
    if (pRaiz != NULL)
    {
        exibirEmOrdem(pRaiz->esquerda);
        if(espaco != 1) printf (" %c", pRaiz->valor);
            else 
            {
                printf ("%c", pRaiz->valor);
                espaco = 0;
            }
        exibirEmOrdem (pRaiz->direita);
    }
}
void exibirPreOrdem (No *pRaiz)
{
    if (pRaiz != NULL)
    {
        if(espaco != 1) printf (" %c", pRaiz->valor);
        else 
        {
            printf ("%c", pRaiz->valor);
            espaco = 0;
        }        
        exibirPreOrdem (pRaiz->esquerda);
        exibirPreOrdem (pRaiz->direita);
    }
}
void exibirPosOrdem (No *pRaiz)
{
    if (pRaiz != NULL)
    {
        exibirPosOrdem (pRaiz->esquerda);
        exibirPosOrdem (pRaiz->direita);
        if(espaco != 1)  printf (" %c", pRaiz->valor);
        else 
        {
            printf ("%c", pRaiz->valor);
            espaco = 0;
        }
    }
}
int busca (No *pRaiz, char x)
{
    if (pRaiz == NULL)
        return 1;
    if (x == pRaiz->valor) 
        return 0;
    if (x < pRaiz->valor) 
        return busca (pRaiz->esquerda,x);
    else 
        return busca (pRaiz->direita,x);
}
No *remover (No *r, int v)
{
    if (r == NULL) 
        return NULL; //se ele pediu pre removerr algo NULL, so volta NULL
    else if (r->valor > v) //se for menor ou mair ele vai mandar pra esquerda ou direita, chamando o remover
        r->esquerda = remover (r->esquerda, v);
    else if (r->valor < v)
        r->direita = remover (r->direita, v);
    else // se chegou aqui é porque eu ja to no pra ser removido
    {
        if (r->esquerda == NULL && r->direita == NULL) // se esse no nao tiver "galhos" postumos
        {
            free(r);
            r = NULL; //removido
        }
        else if (r->esquerda == NULL) //se tiver algo na direita dele
        {
            No *t = r;
            r = r->direita;
            free (t);
        }
        else if (r->direita == NULL) //se tiver algo na esquerda dele
        {
            No *t = r;
            r = r->esquerda;
            free (t);
        }
        else // nesse caso nem a direita nem a esquerda estao vazios, tem ramificações pros dois lados
        {
            No *f = r->esquerda;
            while (f->direita != NULL) f = f->direita;
            r->valor = f->valor;
            f->valor = v;
            f->esquerda = remover(r->esquerda, v); //ok, aqui eu boiei total, nao entendi
        }
    }
    return r;
}
