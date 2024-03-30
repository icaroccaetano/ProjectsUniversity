#include <stdio.h>
#define txa 0.03
#define txb 0.015

int main () {
    double a, b;
    int i;
    
    scanf("%lf %lf", &a, &b);
    if (a>b) {
        return 0;
    }
    for (i=0;a<b;i++) {
        a = a + (a*txa);
        b = b + (b*txb);
    }
    printf("ANOS = %d\n", i);

    return 0;
}