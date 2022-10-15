#include <stdio.h>

int main () {

    double  i;
    double s, aux, ent;

    scanf("%lf", &i);

    if (i-(int)i!=0) {
        printf("Numero invalido!\n");
        return 0;
    }

    if (i<=0) {
        printf("Numero invalido!\n");
        return 0;
    } 

    ent = 1;

    while (i>0) {
        aux = 1.00/ent;
        ent++;
        i--;
        s += aux;   
    }


    printf("%.6lf\n", s);

    return 0;
}