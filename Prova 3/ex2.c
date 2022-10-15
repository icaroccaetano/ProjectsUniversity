#include <stdio.h>
#define nmax 10

int main () {
    int n, l, c, t, sl1, sl2, sc, sb;
    int m[nmax][nmax];
    
    t=0;

    scanf("%d", &n);

    if (n>nmax) {
        printf("dimensao invalida\n");
        return 0;
    }
    
    for(l=0;l<n;l++) {
        for (c=0;c<n;c++) {
            scanf("%d", &m[l][c]);
        }
    }


    if (m[0][0] == m[(n-1)][(n-1)]) {
        t++;
    }
    if (m[(n-1)][0] == m[0][n-1]) {
        t++;
    }

    sl1 = 0;

    for (l=0;l<n;l++) {
        sl1 += m[l][0];
    }

    sl2 = 0;

    for (l=0;l<n;l++) {
        sl2 += m[l][(n-1)];
    }
    
    sc = 0;

    for (c=0;c<n;c++) {
        sc += m[0][c];
    }

    sb = 0;

    for (c=0;c<n;c++) {
        sb += m[(n-1)][c];
    }
        
    if (sl1 == sl2 && sc == sb) {
        printf("bissimetrica\n");
        return 0;
    }
    
    printf ("nao bissimetrica\n");
    return 0;
}