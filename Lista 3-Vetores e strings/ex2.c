#include <stdio.h>
#define N_MAX 1000

int main () {
    int n, i, k, r;
    int v[N_MAX];

    scanf ("%d", &n);
    
    while (n<1 || n>N_MAX) {
        scanf("%d", &n);
    }

    for (i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }

    scanf("%d", &k);

    r = 0;

    for (i=0;i<n;i++) {
        if (v[i]>=k) {
            r++;
        }
    }

    printf("%d\n", r);

    return 0;
}