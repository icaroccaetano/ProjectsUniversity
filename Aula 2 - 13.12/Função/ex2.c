#include <stdio.h>

int par_imp (int x);

int main (void)
{
    int n;

    printf("Insira um numero inteiro:\n");
    scanf("%d", &n);

    switch (par_imp(n))
    {
        case 0: 
            printf("Numero impar\n");
            break;
        case 1:
            printf("Numero par\n");
            break;
    }

    return 0;
}

int par_imp (int x)
{
    if (x%2==0) return 1;
    else return 0;
}