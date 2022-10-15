#include <stdio.h>

int main () {
    int n, x, aux, r, rf;
    scanf("%d", &n);
    r = 1;

    for (n;n>0;n--) {
        scanf("%d", &x);
        if (x==aux) {
            r++;
            rf++;
        }
        else {
            rf = r;
            r = 1;
        }
        aux = x;
    }
    printf("O comprimento do segmento de numeros iguais e: %d\n", rf);
    return 0;
}