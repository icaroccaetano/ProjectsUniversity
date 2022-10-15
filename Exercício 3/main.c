#include <stdio.h>
#include <string.h>
#define MaxTam 1000

typedef struct tipopilha
{
    int valor;
} TipoPilha;
typedef struct pilha
{
    TipoPilha item[MaxTam];
    int topo;
} Pilha;

void criaPilha (Pilha *p);
int pilhavazia (Pilha *p);
void empilha (Pilha *p, int x);
int desempilha (Pilha *p);
int tamPilha (Pilha *p);
void printPilha (Pilha *p);
void calculadora (Pilha *pilha);

int main (void)
{
    Pilha *pilha;
    int opcao;
    criaPilha (pilha);

    printf  ("Calculadora Pos Fixada\n");
    printf  ("1 - Calculadora\n");
    printf  ("2 - Sair\n");

    switch (opcao)
    {
    case 1:
        calculadora (pilha);
        break;
    case 2:
        encerrar (pilha);
        system ("clear");
        return 0;
    
    default:
        break;
    }


}

void criaPilha (Pilha *p)
{
    p -> topo = NULL;
}
int pilhavazia (Pilha *p)
{
    if (p->topo == NULL) return 0;
    else return 1;
}
void empilha (Pilha *p, int x)
{
    p->item[p->topo].valor = x;
    p->topo ++;
}
int desempilha (Pilha *p)
{
    p->topo--;
    return p->item[p->topo+1].valor;
}
int tamPilha (Pilha *p)
{
    return p->topo;
}
void printPilha (Pilha *p)
{
    int i;
    for (i=p->topo-1;i>=0;i--)
    {
        printf("%d\n", p->item[i].valor);
    }
}
void calculadora(Pilha *pilha){
    char entrada[10];
    int valor;
    system("clear");
    printf("Modo calculadora\n");
    printf("Digite 'sair' para sair do modo calculadora\n");

    do{
        printPilha(pilha);
        printf("->");
        scanf("%s", entrada);

        if(strcmp(entrada, "+") == 0 || strcmp(entrada, "-") == 0 ||
           strcmp(entrada, "*") == 0 || strcmp(entrada, "/") == 0){

            operacaoBasica(pilha, entrada);

        }else if(strcmp(entrada, "+!") == 0 || strcmp(entrada, "-!") == 0 ||
                 strcmp(entrada, "*!") == 0){

            operacaoRepeticao(pilha, entrada);

        }else if(strcmp(entrada, "c") == 0){

            copiaDeElemento(pilha, entrada);

        }
        else{
            if(validaCalculadora(entrada)){
                valor = atoi(entrada);
                empilha(pilha, valor);
            }
            else{
                printf("Valor invalido\n");
                printf("Pressione ENTER para continuar ou 'sair' para sair do modo calculadora");
                getchar();
                getchar();
            }
        }
        system("clear");
    }while(strcmp (entrada, "sair") != 0);
}