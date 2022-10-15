#include <stdio.h>
#define N_MAX 1000

int main () {
    int size, m, i, q, a, aux;
    int v[N_MAX];

    scanf("%d", &size);
    if(size < 1 || size > N_MAX) {
        printf ("TAMANHO INVALIDO\n");
        return 0;
    }
    
    for(i=0;i<size;i++) {
        scanf("%d", &v[i]);
    }

    scanf("%d", &q);
    if(q < 1 || q > 1000) {
        printf ("TAMANHO INVALIDO\n");
        return 0;
    }
    for (q;0<q;q--) {
        scanf("%d", &a);
        aux=0;
        for(i=0;i<size;i++) {
            if (v[i]==a) {
                printf("ACHEI\n");
                aux++;
            }
        }
        if (aux==0) printf("NAO ACHEI\n");
    }

    return 0;
}