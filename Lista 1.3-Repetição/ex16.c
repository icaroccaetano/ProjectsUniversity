#include <stdio.h>

int main () {

    double hrs, phr, tot;
    int mat;

    while (1) {
        scanf("%i %lf %lf", &mat, &hrs, &phr);
       
        if (mat !=0) {
        
        tot = phr*hrs;
        printf ("%i %.2lf\n", mat, tot);
        }

        else {return 0;}
    }
    return 0;
}