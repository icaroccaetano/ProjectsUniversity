#include <stdio.h>
#define dmax 10

int main () {
    int a[dmax][dmax], l, c, cl, cc, i;
    i = 1;
    for (;;) {
        scanf("%d", &l);
        if (l>0 && l<=dmax) {
            break;
        }
    }
    for (;;) {
        scanf("%d", &c);
        if (c>0 && c<=dmax) {
            break;
        }
    }
    for (cl=0;cl<l;cl++) {
        for(cc=0;cc<c;cc++) {
            scanf("%d", &a[cl][cc]);
        }
    }
    for (cl=0;cl<l;cl++) {
        printf("linha %d: ", i);
        for(cc=0;cc<c;cc++) {
            printf("%d", a[cl][cc]);
            if (cc<(c-1)) {
                printf(",");
            }
        }
        i++;
        printf("\n");
    }
    return 0;
}

