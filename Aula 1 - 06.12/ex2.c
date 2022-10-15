#include <stdio.h>

int main (void)
{
    double a, b, s;
    printf("Digite os valores de a e b:\n     <valor de a> <valor de b>\n");
    scanf("%lf %lf", &a, &b);
    s = a + b;

    if (a>b) 
    {
        printf("soma = %.2lf\na é o maior\n", s);
    }
    else if (a<b) 
    {
        printf("soma = %.2lf\nb é o maior\n", s);
    }    
    else
    {
        printf("soma = %.2lf\na e b são iguais\n", s);
    }
}