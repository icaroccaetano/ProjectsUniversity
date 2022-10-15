#include <stdio.h>

double maior (double * a, double * b);

int main (void)
{
    double x, y;

    printf("Insira o valor de dois numeros reais:\n");
    printf("    Formato XX.XX XX.XX\n");

    scanf("%lf %lf", &x, &y);

    printf("Maior = %.3lf\n", maior (&x, &y));

    return 0;
}

double maior (double * a, double * b)
{
    if (*a>*b) return *a;
    else return *b;
}