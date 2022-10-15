#include <stdio.h>
#define nmax 1000000

int main () {
    int v[nmax], r[100];
    int n, i, qt, num;

    scanf("%d", &n);

    if(n>nmax) {
        printf ("Tamanho invalido\n");
        return 0;
    }

    for(i=0;i<n;i++) {
        scanf("%d", &v[i]);
        if (v[i]>100) {
            continue;
        }
        r[v[i]]++;
    }

    qt = 0;

    for (i=0;i<=100;i++) {
        if (r[i]>qt) {
            qt = r[i];
            num = i;
        }
    }
    printf("%d\n", num);
    printf("%d\n", qt);

    return 0;
}