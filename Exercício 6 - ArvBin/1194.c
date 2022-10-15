/*ICARO CARNEIRO 202103732*/
#include <stdio.h>
#include <stdlib.h>

#define nmax 1000

typedef struct No
{
	char letra;
	struct No *direita;
	struct No *esquerda;
} No;

No* novoNo(char letra);
void exibirPosOrdem(No *pRaiz);
int src(char *str, int inicio, int fim, char letra);
No* tree(char *infixa, char *prefixa, int inInicio, int inFim);

int indice;

void main ()
{
	int qtsCasos;
	int qtsNodes, i;
	char prefixa[nmax], infixa[nmax];

	scanf("%d", &qtsCasos);

	while (qtsCasos--)
	{
		scanf("%d %s %s%*c", &qtsNodes, prefixa, infixa);
		indice = 0;
		No *raiz = tree(infixa, prefixa, 0, qtsNodes - 1);
		exibirPosOrdem(raiz);
		printf("\n");
	}

}

No* novoNo(char letra)
{
	No *no = (No *) malloc(sizeof(No));
	no->letra = letra;
	no->esquerda = no->direita = NULL;

	return no;
}

int src(char *str, int inicio, int fim, char letra)
{
	int i;
	for (i = inicio; i <= fim; ++i)
		if (str[i] == letra) return i;
	return -1;
}

No* tree(char *infixa, char *prefixa, int inInicio, int inFim)
{
	int infixaIndice;

	if (inInicio > inFim)
		return NULL;

	No *no = novoNo(prefixa[indice++]);
	if (inInicio == inFim)
		return no;

	infixaIndice = src(infixa, inInicio, inFim, no->letra);
	no->esquerda = tree(infixa, prefixa, inInicio, infixaIndice - 1);
	no->direita = tree(infixa, prefixa, infixaIndice + 1, inFim);

	return no;
}

void exibirPosOrdem(No *pRaiz) 
{
    if (pRaiz != NULL) 
    {
    exibirPosOrdem(pRaiz->esquerda);
    exibirPosOrdem(pRaiz->direita);
    printf("%c", pRaiz->letra);
    }
}
