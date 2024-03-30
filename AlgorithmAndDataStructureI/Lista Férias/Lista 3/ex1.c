//=================================================
// Arquivo cnat.h
//=================================================
//
#define nmax 1000000
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct conjunto Conjunto;
int criaConjunto (Conjunto *C);
int conjuntoVazio (Conjunto *C);
void ordenaConjunto (int* a, int u);
int insereElementoConjunto (int x, Conjunto *C);
int excluirElementoConjunto (int x, Conjunto *C);
int tamanhoConjunto (Conjunto *C);
int maior (int x, Conjunto *C);
int menor(int x, Conjunto *C);
int pertenceConjunto (int x, Conjunto *C);
int conjuntosIdenticos (Conjunto *C1, Conjunto *C2);
int subconjunto (Conjunto *C1, Conjunto *C2);
int complemento (Conjunto *C1, Conjunto *C2);
Conjunto uniao (Conjunto *C1, Conjunto *C2);
Conjunto interseccao (Conjunto *C1, Conjunto *C2);
Conjunto diferenca (Conjunto *C1, Conjunto *C2);
int conjuntoparte (Conjunto *C);
void mostraConjunto (Conjunto *C, int ordem);
int copiarConjunto (Conjunto *C1, Conjunto *C2);
int destruirConjunto (Conjunto *C);
void OrdernarVetor(int *vetorN, int tamanho);
//
//=================================================
// Arquivo cnat.c
//=================================================
//
struct conjunto 
{
    int CON[nmax];
    int Ult;
};
//
// Cria um conjunto
//
int criaConjunto (Conjunto *C)
{
    C->Ult = 0;
    C->CON[C->Ult] = '\0';
    if (C->CON[C->Ult] == '\0') return 1;
    else return 0;
}
//
// Confere se o conjunto esta vazio
//
int conjuntoVazio (Conjunto *C)
{
    if (C->CON[0] != '\0') return 0;
    else return 1;
}
//
// Ordena o conjunto na ordem crescente
//
void ordenaConjunto (int* a, int u)
{
    int i, j, aux, m;
    printf("conjunto entrou como ");
    for (i=0;i<u;i++) printf("%d ", a[i]);
    printf("\n");

    for (i=0;i<u;i++)
    {
        m = i;
        for (j=i;j<u;j++)
        {
            if (a[j]<a[i])
            {
                aux = a[j];
                a[j] = a[i];
                a[i] = aux;
            }
        } 
    }
    printf("conjunto saiu como ");
    for (i=0;i<u;i++) printf("%d ", a[i]);
    printf("\n");
}
//
// Insere o elemento x no conjunto C
//
int insereElementoConjunto (int x, Conjunto *C)
{
    int i;
    for (i=0;i<C->Ult;i++) if (C->CON[i] == x) return 0;
    C->Ult++;
    C->CON[C->Ult] = '\0';
    C->CON[C->Ult-1] = x;
    if (C->CON[C->Ult-1] = x) 
    {
        OrdernarVetor(C->CON, C->Ult); 
        return 1;
    }
    else return 0;
}
//
// Exclui elemento do conjunto
//
int excluirElementoConjunto (int x, Conjunto *C)
{
    int i, j, a=0;
    for (i=0;i<C->Ult;i++)
    {
        if (C->CON[i] == x)
        {
            for (j=i+1;j<C->Ult;j++)
            {
                C->CON[j-1] = C->CON[j];
            }
        }
    }
    C->Ult--;
    C->CON[C->Ult] = '\0';
    if (a =! 0 && C->CON[C->Ult] == '\0') return 1;
    return 0;
}
//
//   Calcula a cardinalidade do conjunto
//
int tamanhoConjunto (Conjunto *C)
{
    return C->Ult;
}
//
//  Determina quantos numeros do conjunto sao maiores que x
//
int maior (int x, Conjunto *C)
{
    int i, c=0;
    for (i=0;i<C->Ult;i++)
    {
        if (C->CON[i] > x) c++;
    }
    return c;
}
//
//  Determina quantos numeros do conjunto sao menores que x
//
int menor (int x, Conjunto *C)
{
    int i, c=0;
    for (i=0;i<C->Ult;i++)
    {
        if (C->CON[i] < x) c++;
    }
    return c;
}
//
//  Diz se o numero x pertence ou nao ao conjunto
//
int pertenceConjunto (int x, Conjunto *C)
{
    int i;
    for (i=0;i<C->Ult;i++)
    {
        if (C->CON[i] == x) return 1;
    }
    return 0;
}
//
//  Diz se os conjuntos sao identicos
//
int conjuntosIdenticos (Conjunto *C1, Conjunto *C2)
{
    int i;
    if (C1->Ult != C2->Ult) return 0;
    for (i=0;i<C1->Ult;i++)
    {
        if (C1->CON[i] != C2->CON[i]) return 0;
    }
    return 1;
}
//
// (AUXILIAR) ordena o vetor
void OrdernarVetor(int *vetorN, int tamanho)
{
    int i, j;
    int aux;

    for(i=0;i<tamanho;i++)
    {
        for(j=0;j<tamanho;j++)
        {
            if(vetorN[i] < vetorN[j])
            {
                aux = vetorN[i];
                vetorN[i] = vetorN[j];
                vetorN[j] = aux;
            }
        }
    }
}
//
// Diz se o conjunto c1 e subconjunto de c2
//
int subconjunto (Conjunto *C1, Conjunto *C2)
{
    int i, j, c;
    for (i=0;i<C1->Ult;i++)
    {
        c=0;
        for(j=0;j<C2->Ult;j++)
        {
            if (C1->CON[i] == C2->CON[j]) c++;
        }
        if (c<1) return 0;
    }
    return 1;
}
//
// MENU DO MAIN
//
int menu (void)
{
    int r;
    printf("OPCOES:\n");
    printf("0 - VERIFICAR SE O CONJUNTO E VAZIO\n");
    printf("1 - INCLUIR ELEMENTO NO CONJUNTO\n");
    printf("2 - EXCLUIR ELEMENTO NO CONJUNTO\n");
    printf("3 - CARDINALIDADE DO CONJUNTO\n");
    printf("4 - VERIFICAR QUANTOS NUMEROS DO CONJUNTO SAO MAIORES OU MENORES QUE X\n");
    printf("5 - VERIFICAR SE PERTENCE AO CONJUNTO\n");
    printf("6 - COMPARAR SE A E B SAO IDENTICOS\n");
    printf("7 - IDENTIFICAR SE A E SUBCONJUNTO DE B\n");
    printf("8 - FUNÇÃO INDISPONIVEL NO MOMENTO\n");
    printf("9 - FUNÇÃO INDISPONIVEL NO MOMENTO\n");
    printf("10 - FUNÇÃO INDISPONIVEL NO MOMENTO\n");
    printf("11 - FUNÇÃO INDISPONIVEL NO MOMENTO\n");
    printf("12 - FUNÇÃO INDISPONIVEL NO MOMENTO\n");
    printf("13 - MOSTRAR ELEMENTOS PRESENTES NO COJUNTO\n");
    printf("14 - COPIAR CONJUNTO A PARA O B\n");
    printf("15 - FUNÇÃO INDISPONIVEL NO MOMENTO\n");
    printf("-1 - SAIR\n");
    scanf("%d", &r);
    return r;
}
//
// Mostrar elementos presentes no conjunto
//
void mostraConjunto (Conjunto *C, int ordem)
{
    int i, a;
    if (ordem==0)
    {
        for (i=C->Ult-1;i>=0;i--)
        {
            printf("%d ", C->CON[i]);
            a++;
            if (a==7)
            {
                a=0;
                printf("\n");
            }
        }
    }
    else if (ordem==1)
    {
        for (i=0;i<C->Ult;i++)
        {
            printf("%d ", C->CON[i]);
            a++;
            if (a==7)
            {
                a=0;
                printf("\n");
            }
        }
    }
    else printf("ORDEM INVALIDA!");
    printf("\n");
}
//=================================================
// Arquivo principal
//=================================================
//
int main (void)
{
    int i, a, b;
    Conjunto A, B;

    printf("TESTE DA TAD DE NUMEROS NATURAIS\nATENCAO: O CONJUNTO A E SEMPRE USADO COMO PADRAO E O B COMO AUXILIAR\n");

    // CRIACAO DO CONJUNTO A
    printf("CRIACAO DO CONJUNTO A\n");

    switch (criaConjunto (&A))
    {
        case 1:
            printf("Conjunto Criado!\n");
            break;
        case 0:
            printf("Erro ao criar conjunto!\n");
            break;
        default:
            break;
    }

    switch (conjuntoVazio(&A))
    {
    case 1:
        printf("Conjunto esta vazio!\n");
        break;
    case 0:
        printf("Conjunto nao esta vazio!\n");
        break;
    default:
        break;
    }
    
    printf ("Quantidade de numeros a serem inseridos no conjunto A: ");
    scanf("%d", &a);
    printf("Inserir %d valores a serem adicionados no conjunto A:\n", a);
    for (i=0;i<a;i++)
    {
        scanf("%d", &b);
        switch (insereElementoConjunto (b,&A))
        {
        case 1:
            printf("Numero %d adicionado com exito!\n", b);
            break;
        case 0:
            printf("Falha ao adicionar o numero %d!\n", b);
            i--;
            break;
        default:
            break;
        }
    }
    // CRIACAO DO CONJUNTO B
    printf("CRIACAO DO CONJUNTO B\n");
    
    switch (criaConjunto (&B))
    {
        case 1:
            printf("Conjunto Criado!\n");
            break;
        case 0:
            printf("Erro ao criar conjunto!\n");
            break;
        default:
            break;
    }

    switch (conjuntoVazio(&B))
    {
    case 1:
        printf("Conjunto esta vazio!\n");
        break;
    case 0:
        printf("Conjunto nao esta vazio!\n");
        break;
    default:
        break;
    }
    
    printf ("Quantidade de numeros a serem inseridos no conjunto B: ");
    scanf("%d", &a);
    printf("Inserir %d valores a serem adicionados no conjunto B:\n", a);
    for (i=0;i<a;i++)
    {
        scanf("%d", &b);
        switch (insereElementoConjunto (b,&B))
        {
        case 1:
            printf("Numero %d adicionado com exito!\n", b);
            break;
        case 0:
            printf("Falha ao adicionar o numero %d!\n", b);
            i--;
            break;
        default:
            break;
        }
    }

    // MENU DE OPCOES;
    while (1)
    {
        switch (menu())
        {
            case 0:
                switch (conjuntoVazio(&A))
                {
                case 1:
                    printf("Conjunto A esta vazio!\n");
                    break;
                case 0:
                    printf("Conjunto A nao esta vazio!\n");
                    break;
                default:
                    break;
                }
                break;
            case 1:
                printf("Inserir valor a ser adicionado no conjunto A:\n");
                scanf("%d", &b);
                switch (insereElementoConjunto (b,&A))
                {
                case 1:
                    printf("Numero %d adicionado com exito!\n", b);
                    break;
                case 0:
                    printf("Falha ao adicionar o numero %d!\n", b);
                    i--;
                    break;
                default:
                    break;
                }
                break;
            case 2:
                while (1)
                {
                    printf("Insira um valor a ser excluido ou -1 para nao excluir mais nenhum\n");
                    scanf("%d", &a);
                    if (a==-1) break;
                    else 
                    {
                        switch (excluirElementoConjunto (a,&A))
                        {
                            case 1:
                                printf("Numero %d removido com exito!\n", a);
                                break;
                            case 0:
                                printf("Falha ao remover o numero %d!\n", a);
                                break;
                            default:
                                break;
                        }
                    }
                }
                break;
            case 3:
                printf("Cardinalidade atual do conjunto = %d\n", tamanhoConjunto(&A));
                break;         
            case 4:
                while(1)
                {
                    printf("Insira um numero para servir de parametro para teste de maior e menor e a função a ser usada\n");
                    printf("Formato = <num> <fun>\n     0 = Quantos numeros da funcao sao MAIORES que o especificado\n     1 = Quantos numeros da funcao sao MENORES que o especificado\n");
                    printf("Digite -1 para sair\n");
                    scanf("%d", &a);
                    if (a==-1) break;
                    scanf("%d", &b);
                    switch (b)
                    {
                    case 0:
                        switch (maior(a,&A))
                        {
                        case 0:
                            printf("O conjunto nao tem numeros maiores que %d\n", a);
                            break;
                        case 1:
                            printf("O conjunto tem apenas um numero maior que %d\n", a);
                            break;          
                        default:
                            printf("O conjunto tem %d numeros maiores que %d\n", maior(a,&A), a);
                            break;
                        }
                        break;
                    case 1:
                        switch (menor(a,&A))
                        {
                        case 0:
                            printf("O conjunto nao tem numeros menores que %d\n", a);
                            break;
                        case 1:
                            printf("O conjunto tem apenas um numero menor que %d\n", a);
                            break;          
                        default:
                            printf("O conjunto tem %d numeros menores que %d\n", menor(a,&A), a);
                            break;
                        }
                        break;
                    default:
                        printf("Numero de funcao invalida\n");
                        break;
                    }
                }
                break;
            case 5:
                while (1)
                {
                    printf("Insira um numero para conferir se pertence ou nao ao conjunto\nDigite -1 para sair\n");
                    scanf("%d", &a);
                    if (a==-1) break;
                    switch (pertenceConjunto(a, &A))
                    {
                    case 1:
                        printf("O numero %d pertence ao conjunto!\n", a);
                        break;
                    case 0:
                        printf("O numero %d  nao pertence ao conjunto!\n", a);
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 6:
                switch (conjuntosIdenticos(&A,&B))
                {
                case 0:
                    printf("Os conjuntos nao sao identicos!\n");
                    break;
                case 1:
                    printf("Os conjuntos sao identicos!\n");
                    break;
                default:
                    break; 
                }
                break;
            case 7:
                switch (subconjunto(&A,&B))
                {
                case 0:
                    printf("O conjunto A nao e subconjunto de B!\n");
                    break;
                case 1:
                    printf("O conjunto A e subconjunto de B!\n");
                    break;
                default:
                    break; 
                }
                break;
            case 13:
                printf("Escolha a ordem:\n0 - Decrescente\n1 - Crescente\nOutro numero - Sair\n");
                scanf("%d", &a);
                if(a==0 || a==1) mostraConjunto(&A, a);
                break;
            case -1:
                printf("Obrigado! :)");
                return 0;
            default:
                printf("opcao invalida!\n");
                break;
        }
    }
    return 0;
} 