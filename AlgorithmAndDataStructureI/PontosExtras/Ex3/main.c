#include "ferry.h"

int main (void)
{
    char placa[7];
    int k, i, n, aux;
    Ferry balsa;
    TipoFila fila;
    
    printf("Quantidade maxima de carros na balsa: "); // Pegando a quantidade max da balsa
    scanf("%d", &k);

    printf("Quantidade de carros na fila: "); // O numero de carros na fila (tem que ser maior que o max)
    scanf("%d", &n);

    initferry (&balsa,k); // Inicializando a balsa
    Inicializar (&fila);  // Inicializando a fila
    /* Testando adicionar carros a FIla e de la adiciona-se a balsa */
    printf("Insira as placas dos carros separadas por um enter (Modelo = ABC1D34)\n");
    for (n;n>0;n--)
    {
        for (aux=0;aux<7;aux++)
        { 
            scanf("%c", &placa[aux]); //lendo a placa do veiculo
            if (placa[aux] == '\n') aux--;
        }
        Enfileira(&balsa, placa, &fila);
    }
    capacity (&balsa);
    printf("BALSA:\n");
    statusferry (&balsa);
    printf("FILA DE ESPERA:\n");
    Imprime (fila);
    printf("\n");
    while (1)
    {
        printf("Digite uma posicao a ser removida ou -1 para sair: ");
        scanf("%d", &n); if (n==-1) break;
        removeferrypos(&balsa,n,&fila);
        capacity (&balsa);
        printf("BALSA:\n");
        statusferry (&balsa);
        printf("FILA DE ESPERA:\n");
        Imprime (fila);
        printf("\n");
    }
}