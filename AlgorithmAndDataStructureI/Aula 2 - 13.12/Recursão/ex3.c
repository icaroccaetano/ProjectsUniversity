#include <stdio.h>

double T (double n);

int main (void)
{
    double n;

    printf("Insira o valor de n\n");
    scanf("%lf", &n);

    printf("Resultado = %lf\n", T(n));

    return 0; 
}

double T (double n)
{
    if (n==1) return 1;

    else return 2* T(n/2) + n;
}

//PS.: Prof nao consegui resolver esse, tentei pesquisar pra ver se entendia mas não consegui :(