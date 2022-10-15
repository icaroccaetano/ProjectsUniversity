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
TipoCelula *findmat (Turma *Lista, int m);
void ordena (Turma *Lista); //Essa e a funcao do ex 4
void print (Turma *Lista);
void encerrar (Turma *Lista);

int main (void)
{
    Turma turma;
    int x;
    init (&turma);
    while (1)
    {
        printf ("Escolha uma opcao:\n1 - Adicionar aluno\n2 - Remover aluno\n3 - Ver lista \n4 - Ordenar\n5 - Encerrar\nDigite uma opcao: ");
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
            ordena (&turma);
            break;
        case 5:
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
    Lista->primeiro = NULL;
    Lista->ultimo = Lista->primeiro;
}

void add (Turma *Lista)
{
    int iaux;
    TipoCelula *aux;
    char caux[56];
    if (Lista->qtd >= nmax)
    {
        printf ("Falha ao adicionar: Limite alcançado!\n");
        return;
    }
    TipoCelula *insert = malloc(sizeof(TipoCelula)); // Celula a ser colocada
    printf ("Insira a matricula: ");
    scanf("%d", &insert->matricula);
    printf("%d\n", insert->matricula);
    printf ("Insira o nome: ");
    fgets (insert->nome,56,stdin);
    scanf("%[^\n]%*c", caux);
    strcpy (insert->nome,caux);
    printf("%s\n", insert->nome);
    printf ("Insira o curso: ");
    scanf("%[^\n]%*c", caux);
    strcpy (insert->curso,caux);
    printf("%s\n", insert->curso);
    printf("Nota 1: ");
    scanf("%d", &insert->nota1);
    printf("%d\n", insert->nota1);
    printf("Nota 2: ");
    scanf("%d", &insert->nota2);
    printf("%d\n", insert->nota2);
    

    if(conferemat(Lista,insert->matricula) == 1)
    {
        printf ("Erro: matricula ja em uso\n");
        return;
    } // a confere mat nao estava dando certo, nao consehui entender o motivo :(
    
    if (Lista->qtd == 0) // Se a lista estiver vazia
    {
        Lista->primeiro = insert;
        Lista->ultimo = insert;
        Lista->qtd++;
        printf ("Adicionado com sucesso!\n");
    }
    else if (Lista->qtd == 1) // Se so tiver um termo
    {
        insert->prox = Lista->primeiro;
        insert->ant = Lista->primeiro;
        Lista->primeiro->prox = insert;
        Lista->primeiro->ant = insert;
        Lista->ultimo = insert;
        Lista->qtd++;
        printf ("Adicionado com sucesso!\n");
        
    }
    else 
    {   
        insert->prox = Lista->primeiro;
        insert->ant = Lista->ultimo;
        Lista->primeiro->ant = insert;
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
    if (Lista->primeiro == NULL) return 0; // se a lista for vazia
    if (Lista->qtd == 1)
    {
        if (Lista->primeiro->matricula == mat) return 1;
        else return 0;
    }
    aux = Lista->primeiro;
    while (1)
    {
        if (aux->matricula == mat) return 1;
        if (aux->prox == Lista->primeiro) return 0;
        aux = aux->prox;
    }
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
            Lista->qtd--;
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
TipoCelula *findmat (Turma *Lista, int m)
{
    TipoCelula *resp = Lista->primeiro;

    while (1)
    {
        if (resp->matricula == m) break;
        resp = resp->prox;
    }
    return resp;
}
void ordena (Turma *Lista)
{
    int i, j, vet[Lista->qtd], men;
    char nome[56], curso[56];
    int matr, n1, n2;
    TipoCelula *aux1 = Lista->primeiro;
    TipoCelula *aux2;
    
    i=0;
    while (1)
    {
        vet[i] = aux1->matricula;
        i++;
        if (aux1->prox == Lista->primeiro) break;
        aux1 = aux1->prox;
    }
    for (i=0;i<Lista->qtd;i++)
    {
        men = i;
        for (j=i;j<Lista->qtd;j++)
        {
            if (vet[men]>vet[j]) men = j;
        }

        aux1 = findmat (Lista,vet[i]);
        aux2 = findmat (Lista,vet[men]);
        printf ("Sai: %d, Entra: %d\n", aux1->matricula, aux2->matricula);
        //if (aux1->matricula == aux2->matricula) continue;
        /*---------------------FAZENDO SWAP---------------------*/ //fiz aqui para ter controle maior do vetor que to usando para ordenar
        //fazendo swap na lista
        strcpy (nome,aux1->nome);
        strcpy (curso,aux1->curso);
        matr = aux1->matricula;
        n1 = aux1->nota1;
        n2 = aux1->nota2;
        strcpy (aux1->nome,aux2->nome);
        strcpy (aux1->curso,aux2->curso);
        aux1->matricula = aux2->matricula;
        aux1->nota1 = aux2->nota1;
        aux1->nota2 = aux2->nota2;       
        strcpy (aux2->nome,nome);
        strcpy (aux2->curso,curso);
        aux2->matricula = matr;
        aux2->nota1 = n1;
        aux2->nota2 = n2;
        //fazendo o swap no vetor
        n1 = vet[i];
        vet[i] = vet[men];
        vet[men] = n1;
        /*------------------FIM DO SWAP-----------------*/
          
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
        if (aux->prox == Lista->primeiro) break;
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
        if (Lista->primeiro == Lista->primeiro) break;
    }
    printf ("Programa encerrado com sucesso!\n");
    return;
}