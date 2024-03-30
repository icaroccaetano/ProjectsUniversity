#include <stdio.h>

int main () {

    int vi, r, n, soma, aux, ri;

    scanf("%i %i %i", &vi, &ri, &n);
    r = ri;
    soma = vi;

    while (n>1) {
        aux = vi + r;
        r += ri;
        n --;
        soma += aux;
    }

    printf("%i\n", soma);

    return 0;
}