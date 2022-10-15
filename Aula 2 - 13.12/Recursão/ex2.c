#include <stdio.h>

double pot (double x, int n)
{
    double r=1;
    if (n==0) return r;
    
    else r = x * pot (x,n-1);
}

int main (void) 
{
    double b;
    int e;
    printf("Insira o valor da base seguido do expoente:\n");
    printf("   Formato: <base> <exp>\n");

    scanf("%lf %d", &b, &e);

    printf("Resultado: %.3lf\n", pot (b,e));

    return 0;
}