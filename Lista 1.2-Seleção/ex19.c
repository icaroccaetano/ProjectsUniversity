#include <stdio.h>

void swap (double *x, double *y) {
    double aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main () {
    double a, b, c, d;
    int i;

    scanf ("%lf %lf %lf %lf", &a , &b, &c, &d);

    // primeiro número (a)
    if (b < a) {
        swap (&b, &a);
    }
    if (c < a) {
        swap (&c, &a);
    }
    if (d < a) {
        swap (&d, &a);
    }

    //segudno número (b)
    if (c < b) {
        swap (&c, &b);
    }
    if (d < b) {
        swap (&d, &b);
    }

    //terceiro número (c)
    if (d < c) {
        swap (&c, &d);
    }

    printf("%.2lf, %.2lf, %.2lf, %.2lf\n", a, b, c, d);

    return 0;
}