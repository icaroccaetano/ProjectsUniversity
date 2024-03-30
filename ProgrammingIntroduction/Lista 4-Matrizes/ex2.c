#include <stdio.h>
#define dmax 1000

int main () {
    int m[dmax][dmax];
    int n, l, c;

    scanf("%d", &n);

    for(l=0;l<n;l++) {
        for (c=0;c<n;c++) {
            scanf("%d", &m[l][c]);
        }
    }

    for(l=0;l<n;l++) {
        for(c=0;c<n;c++) {
            if(l==c) {
                printf("%d\n", m[l][c]);
            }
        }
    }
    return 0;
}