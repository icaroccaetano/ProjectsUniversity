#include <stdio.h>
#include <math.h>
#define PI 3.14

int main() {
    char op;
    int angulo, ac;
    double sc;

    scanf("%c%d", &op, &angulo);

    //angulo correspondente no 1o quadrante
    if(angulo >= 0 && angulo <= 90) { 
        ac = angulo;
        printf("%d\n", ac);
        if(op=='s') printf("%.3lf\n", sin(ac*PI/180));
        else if(op=='c') printf("%.3lf\n", cos(ac*PI/180));
        if(op=='s') printf("SINAL IGUAL\n");
        else if(op=='c') printf("SINAL IGUAL\n");
        //primeiro quadrante: SENO + / COSSENO +
    }
    else if(angulo > 90 && angulo <= 180) {
        ac = 180 - angulo;
        printf("%d\n", ac);
        if(op=='s') printf("%.3lf\n", sin(ac*PI/180));
        else if(op=='c') printf("%.3lf\n", cos(ac*PI/180));
        if(op=='s') printf("SINAL IGUAL\n");
        else if(op=='c') printf("SINAL INVERTIDO\n");
        //segundo quadrante: SENO + / COSSENO -
    }
    else if(angulo > 180 && angulo <= 270) {
        ac = (180 + angulo)-360;
        printf("%d\n", ac);
        if(op=='s') printf("%.3lf\n", sin(ac*PI/180));
        else if(op=='c') printf("%.3lf\n", cos(ac*PI/180));
        if(op=='s') printf("SINAL INVERTIDO\n");
        else if(op=='c') printf("SINAL INVERTIDO\n");
        //terceiro quadrante: SENO - / COSSENO -
    }
    else if(angulo > 270 && angulo <= 360) {
        ac = 360 - angulo;
        printf("%d\n", ac);
        if(op=='s') printf("%lf\n", sin(ac*PI/180));
        else if(op=='c') printf("%lf\n", cos(ac*PI/180));
        if(op=='s') printf("SINAL INVERTIDO\n");
        else if(op=='c') printf("SINAL IGUAL\n");
        //quarto quadrante: SENO - / COSSENO +
    }

    
    return 0;
}