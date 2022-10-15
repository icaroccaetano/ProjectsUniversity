#include <stdio.h>
#define nmax 1000

int main () {
    int t, n, v[nmax], i, a, b;
    unsigned int d, aux;
    scanf("%d", &t);
    b = 0;
    
    if (t<1 || t>10) {
        printf("falha: quantidade de testes deve ser entre 1 e 10\n");
        return 0;
    }
    d = 10000000;
    
    for (t;t>0;t--) {
        scanf("%d", &n);
        for (i=0;i<n;i++) {
            scanf("%d", &v[i]);
        }
        for (i=0;i<n;i++) {
            for (a=0;a<n;a++) {
                aux = v[i]-v[a];
                //printf("% e o aux\n");
                if (aux<d) {
                    d == aux;
                }
            }
        }
        b = n*n;
        printf("%d %d\n", d, b);
    }

    return 0;
}


