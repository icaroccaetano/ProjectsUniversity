#include <stdio.h>

int main () {
    int x, d;
    while (1) {
        scanf("%d", &x);
        if (x <= 1) {
            printf("Fatoracao nao e possivel para o numero %d!\n", x);
        }
        else {break;}
    }
    printf("%d =", x);
    for (d=2;x>1;d++) {
        while (1) {
            if (x%d!=0) {break;}
            x /= d;
            if (x!=1) {
                printf(" %d x", d);
            }
            else {
                printf(" %d", d);
            }                    
        }
    }
    printf("\n");
    return 0;
}