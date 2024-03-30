#include <stdio.h>

int main () {
    double a , b, c, per, area;

    scanf ("%lf %lf %lf", &a, &b, &c);

    if (+(b-c)<a && +(b-c)<(b+c) && a<(b+c) && +(a-c)<b && +(a-c)<(a+c) && b<(a+c) && +(a-b)<c && +(a-c)<(a+b) && c<(a+b)) {
        per = a+b+c;
        printf("Perimetro = %.1lf\n", per);                        
    }
    else {
        area = ((a+b)*c)/2.0;
        printf("Area = %.1lf\n", area);
    }
    return 0;
}