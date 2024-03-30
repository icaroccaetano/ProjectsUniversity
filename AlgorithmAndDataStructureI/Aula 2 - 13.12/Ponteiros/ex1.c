#include <stdio.h>

int main (void)
{
    int i;
    double r;
    char c;
    int * pi;
    double * pr;
    char * pc;
    //Dando valor às variáveis
    i = 10;
    r = 10;
    c = 'd';
    //Imprimindo os valores das variáveis
    printf("Valores antes da modificação via ponteiro:\n");
    printf("Valor do inteiro: %d\nValor do real: %.2lf\nValor do char: %c\n", i, r, c);
    //Associando-as aos ponteiros
    pi = &i;
    pr = &r;
    pc = &c;
    //Alterando o valor pelos ponteiros
    *pi = 20;
    *pr = 20;
    *pc = 'v';
    //Imprimindo novamente
    printf("Valores após a modificação via ponteiro:\n");
    printf("Valor do inteiro: %d\nValor do real: %.2lf\nValor do char: %c\n", i, r, c);
    //;)
    return 0;
}