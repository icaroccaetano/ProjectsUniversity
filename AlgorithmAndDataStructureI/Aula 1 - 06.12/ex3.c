#include <stdio.h>

int main (void)
{
    int op;
    double a, b, r;

    printf("formato <op> <a> <b>\noperações disponíveis:\n1-Adição\n2-Subtração\n3-Multiplicação\n4-Divisão\n");
    scanf("%d %lf %lf", &op, &a, &b);

    switch (op)
    {
        case 1:
            r = a+b;
            printf("%.2lf + %.2lf = %.2lf\n", a, b, r);
            break;
        case 2:
            r = a-b;
            printf("%.2lf - %.2lf = %.2lf\n", a, b, r);
            break;
        case 3:
            r = a*b;
            printf("%.2lf * %.2lf = %.2lf\n", a, b, r);
            break;
        case 4:
            r = a/b;
            printf("%.2lf / %.2lf = %.2lf\n", a, b, r);
            break;
        default:
            printf("Operação inválida.\n");
            break;
    }
    return 0;

}