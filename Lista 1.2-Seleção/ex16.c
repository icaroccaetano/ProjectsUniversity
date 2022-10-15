#include <stdio.h>
#define M12 0.20
#define M5 0.08

int main () {
    int mat, dep;
    float salm, salf, ip, ib, il, it;

    scanf("%d %f %d %f %f", &mat, &salm, &dep, &salf, &ip);

    if (salf > (12*salm)) {
        ib = salf * M12;
    }
    else if (salf > (5*salm)) {
        ib = salf * M5;
    }
    else {
        ib = 0;
    }

    il = ib - (dep*300.0);

    it = il - (salf*(ip/100));

    printf("MATRICULA = %d\n", mat);
    printf("IMPOSTO BRUTO = %.2f\n", ib);
    printf("IMPOSTO LIQUIDO = %.2f\n", il);
    printf("RESULTADO = %.2f\n", it);

    if (it>0) {printf("IMPOSTO A PAGAR\n");}
    if (it==0) {printf("IMPOSTO QUITADO\n");}
    if (it<0) {printf("IMPOSTO A RECEBER\n");}



    return 0;
}