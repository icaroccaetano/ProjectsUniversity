#include <stdio.h>
#include <math.h>

int classifica_iris (double pt, double pl, double st, double sl, double * d1, double * d2, double * d3) {
    int r;
    * d1 = sqrt( (6.85-pt)*(6.85-pt) + (3.07-pl)*(3.07-pl) + (5.74-st)*(5.74-st) + (2.07-sl)*(2.07-sl) );
    * d2 = sqrt( (5.00-pt)*(5.00-pt) + (3.41-pl)*(3.41-pl) + (1.46-st)*(1.46-st) + (0.24-sl)*(0.24-sl) );
    * d3 = sqrt( (5.90-pt)*(5.90-pt) + (2.74-pl)*(2.74-pl) + (4.39-st)*(4.39-st) + (1.43-sl)*(1.43-sl) );
    
    if (*d1 < *d2) { 
        if (*d1 <= *d3) {
            r = 1;
            return r;
        }
        if (*d1 > *d3) {
            r = 3;
            return r;
        }
    }
    else { 
        if (*d2 <= *d3) {
            r = 2;
            return r;
        }
        if (*d2 > *d3) {
            r = 3;
            return r;
        }
        }

}

int main () {
    double pt, pl, st, sl;
    double  d1; 
    double  d2; 
    double  d3;
    int aux;

    while (scanf("%lf %lf %lf %lf", &pt, &pl, &st, &sl) != EOF) {
        aux = classifica_iris(pt, pl, st, sl, &d1, &d2, &d3); 
        printf("(%.2lf %.2lf %.2lf)",  d1,  d2,  d3);

        if (aux == 1) {printf(" setosa\n");}
        if (aux == 2) {printf(" virginica\n");}
        if (aux == 3) {printf(" versicolor\n");}
        
    } 

    return 0;
}