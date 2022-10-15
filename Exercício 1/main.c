/*
ALUNO: ICARO CARNEIRO CAETANO CHEREDNIKOV
MATRICULA: 202103732
MATERIA: ALGORITMO E ESTRUTURAS DE DADOS
PROFESSOR: RONALDO MARTINS DA COSTA
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define nmax 50

typedef struct TipoCelula
{
    int matricula;
    char nome[56];
    char curso[56];
    int nota1;
    int nota2;
    struct TipoCelula *prox;
    struct TipoCelula *ant;
} TipoCelula;

typedef struct TipoCelula *ApontadorCelula;

typedef struct 
{
    ApontadorCelula primeiro, ultimo;
    int qtd;
} Turma;

void init (Turma *Lista);
void add (Turma *Lista);
int conferemat (Turma *Lista, int mat);
void remove_ (Turma *Lista);
void print (Turma *Lista);
void encerrar (Turma *Lista);

int main (void)
{
    Turma turma;
    int x;
    init (&turma);
    while (1)
    {
        printf ("Escolha uma opcao:\n1 - Adicionar aluno\n2 - Remover aluno\n3 - Ver lista \n4 - Encerrar\nDigite uma opcao: ");
        scanf ("%d", &x);
        switch (x)
        {
        case 1:
            add (&turma);
            break;
        case 2:
            remove_ (&turma);
            break;
        case 3:
            print (&turma);
            break;
        case 4:
            encerrar (&turma);
            return 0;
            break;
        default:
            printf ("Opcao inválida!\n");
            break;
        }
    }
}

void init (Turma *Lista)
{
    Lista->qtd = 0;
    Lista->ultimo = NULL;
    Lista->primeiro = Lista->ultimo;
}

void add (Turma *Lista)
{
    int iaux;
    char caux[56];
    if (Lista->qtd >= nmax)
    {
        printf ("Falha ao adicionar: Limite alcançado!\n");
        return;
    }
    TipoCelula *insert = malloc(sizeof(TipoCelula)); // Celula a ser colocada
    printf ("Insira a matricula: ");
    scanf("%d", &insert->matricula);
    printf ("Insira o nome: ");
    fgets (insert->nome,56,stdin);
    scanf("%[^\n]%*c", caux);
    strcpy (insert->nome,caux);
    printf ("Insira o curso: ");
    scanf("%[^\n]%*c", caux);
    strcpy (insert->curso,caux);
    printf("Nota 1: ");
    scanf("%d", &insert->nota1);
    printf("Nota 2: ");
    scanf("%d", &insert->nota2);
    
    if(conferemat(Lista,insert->matricula) == 1)
    {
        printf ("Erro: matricula ja em uso\n");
        return;
    }
    
    if (Lista->primeiro == NULL) // Se a lista estiver vazia
    {
        insert->ant = NULL;
        insert->prox = NULL;
        Lista->primeiro = insert;
        Lista->ultimo = insert;
        Lista->qtd++;
        printf ("Adicionado com sucesso!\n");
    }
    else 
    {
        insert->prox = NULL;
        insert->ant = Lista->ultimo;
        Lista->ultimo->prox = insert;
        Lista->ultimo = insert;
        Lista->qtd++;
        printf ("Adicionado com sucesso!\n");
    }
    return;
}
int conferemat (Turma *Lista, int mat)
{
    TipoCelula *aux;
    aux = Lista->primeiro;
    while (aux!=NULL)
    {
        if (aux->matricula == mat) return 1;
        aux = aux->prox;
    }
    return 0;
}
void remove_ (Turma *Lista)
{
    if (Lista->primeiro == NULL)
    {
        printf ("Lista vazia!\n");
        return;
    }
    int mat;
    TipoCelula *aux;
    aux = Lista->primeiro;
    printf ("Digite matrícula a ser removida: ");
    scanf ("%d", &mat);
    while(1)
    {
        if (aux->matricula == mat)
        {
            printf ("Remover %s?", aux->nome);
            printf("Aperte 1 para confirmar... ");
            scanf ("%d", &mat);
            if (mat != 1) 
            {
                printf("Nao removido\n");
                return;
            }
            aux->ant->prox = aux->prox;
            printf ("Removido: %d", aux->matricula);
            free (aux);
            break;
        }
        if (aux->prox ==  NULL) 
        {
            printf("Falha: Numero de matrícula inválido");
            break;
        }
        aux = aux->prox;
    }

}
void print (Turma *Lista)
{
    if (Lista->primeiro == NULL)
    {
        printf ("Lista vazia!\n");
        return;
    }
    TipoCelula *aux;
    aux = Lista->primeiro;
    printf ("--------LISTA ALUNOS--------\n");
    while (1)
    {
        printf ("Nome: %s\nMatrícula: %d\nCurso: %s\nMédia Final: %d\n", aux->nome, aux->matricula, aux->curso, (aux->nota1+aux->nota2)/2);
        printf ("\n");
        if (aux->prox == NULL) break;
        aux = aux->prox;
    }
}
void encerrar (Turma *Lista)
{
    if (Lista->primeiro == NULL) return;
    TipoCelula *aux;
    aux = Lista->primeiro;
    while (1)
    {   
        Lista->primeiro = aux->prox;
        free (aux);
        aux = aux->prox;
        if (Lista->primeiro == NULL) break;
    }
    printf ("Programa encerrado com sucesso!\n");
    return;
}
