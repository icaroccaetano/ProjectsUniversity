#include <stdio.h>
#define max 100

void le_conjunto (int  * v, int n) {
    int i, a;
    
    for (i=0;i<n;i++) {
        scanf("%d", &v[i]);
        for (a=0;a<i;a++) {
            if (v[i]==v[a]) {
                while (v[i]==v[a]) {
                    scanf("%d", &v[i]);
                    a=0;
                }
            }
        }
        if (i==0) {
            printf("(%d", v[i]);
        }
        else if (i<n) {
            printf(",%d", v[i]);
        }
    }
    printf(")\n");

    return;
}

int main () {
    int v[max], n;

    scanf("%d", &n);

    if (n<1 || n>max) {
        return 0;
    }

    le_conjunto(v, n);

    return 0;
}