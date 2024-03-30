#include "tad.h"

void init (String *palavra)
{
    palavra->pos = 0;
}
void add (String *palavra, char lt)
{
    if (palavra->pos>nmax) 
    {
        printf ("ERRO - Limite de letras atingido\n");
        return;
    }
    else
    {    
        palavra->palavra[palavra->pos] = lt;
        palavra->pos++;
        palavra->palavra[palavra->pos] = '\0';
    }
}
void print (String *palavra)
{
    printf ("%s\n", palavra->palavra);
}
void charQuickSort (String * Palavra, int inicio, int fim)
{
    if(inicio < fim){ //se o meu inicio for menor que o fim
        char pivo = Palavra->palavra[inicio]; //determina quem é o pivo
        char temp;
        int i = inicio;
        int f = fim;
        
        while (1){
            while(pivo < Palavra->palavra[f]){  //enquanto o pivo for menor que o pivo naposição final
                f--;
            }
            while(pivo > Palavra->palavra[i]){ //enquando meu pivo for maior que inicial
                i++;
            }
            if (i >= f){
                break;
            }
            temp = Palavra->palavra[i];
            Palavra->palavra[i] = Palavra->palavra[f];
            Palavra->palavra[f] = temp;
        }
        //a rotina chama ela mesma
        charQuickSort(Palavra, inicio, f);
        charQuickSort(Palavra, f +1, fim);
    }
}
