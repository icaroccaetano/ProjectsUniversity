#include <stdio.h>
#define INSS 0.08
#define IMP 0.15

int main () {

    double salm, lim_ins, tv1, tv2, salb, sall, ctv1, ctv2;
    int mat, qtv1, qtv2;
    
    scanf("%lf %lf %lf %lf", &salm, &lim_ins, &tv1, &tv2);

    while (1) {
        
        scanf ("%d %d %d", &mat, &qtv1, &qtv2);
        
        if (mat != 0) {
        
        printf("MATRICULA = %d, ", mat);

        if (qtv1 >= 10) {ctv1 = qtv1 * (0.14*tv1);}
        if (qtv1 < 10)  {ctv1 = qtv1 * (0.13*tv1);}

        if (qtv2 >= 20) {ctv2 = qtv2 * (0.13*tv2);}
        if (qtv2 < 20)  {ctv2 = qtv2 * (0.12*tv2);}

        salb = salm + ctv1 + ctv2;

        printf("SALARIO BRUTO = %.2lf, ", salb );

        sall = salb - (salb*INSS);

        if (sall>lim_ins) {sall = sall - ((sall-lim_ins)*0.15);}

        printf("SALARIO LIQUIDO = %.2lf\n", sall);
        }
        else {return 0;}
    }

    return 0;
}

