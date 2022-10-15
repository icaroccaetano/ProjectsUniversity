#include <stdio.h>

int main () {
    double ValMer, a, b, difvm, n, l, mvf, ml, mni;

    scanf("%lf %lf %lf", &ValMer, &a, &b);
    if (a>=b){
        printf("INTERVALO INVALIDO\n");
        return 0;
    }
    mvf = 0;
    ml = 0;
    mni = 0;

    for(a;a<=b;a++) {
        difvm = ValMer - a;
        if (difvm>=0) {
            n = (difvm*50)+120;
            l = (n*a)-(200.00+(0.05*n));
            if (ml<l) {
                mvf = a;
                ml = l;
                mni = n;
            }
            printf("V: %.2lf, N: %.0lf, L: %.2lf\n", a, n, l);
        }
        if (difvm<0) {
            n = (difvm*60)+120;
            l = (n*a)-(200+(0.05*n));
            if (ml<l) {
                mvf = a;
                ml = l;
                mni = n;
            }
            printf("V: %.2lf, N: %.0lf, L: %.2lf\n", a, n, l);
        }
    }
    printf("Melhor valor final: %.2lf\n", mvf);
    printf("Lucro: %.2lf\n", ml);
    printf("Numero de ingressos: %.0lf\n", mni);

    return 0;
}