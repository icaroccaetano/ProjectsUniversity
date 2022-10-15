#include <stdio.h>

int main (void)
{
    double salm, salu, r;

    printf("Inserir salario mínimo:\n");
    scanf ("%lf", &salm);
    printf("Inserir salario do usuário:\n");
    scanf ("%lf", &salu);

    r = salu/salm;

    printf("Salário do usuário = %.2lf salários mínimos\n", r);
    return 0;
}
