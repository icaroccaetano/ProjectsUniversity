#include <stdio.h>
#include <math.h>

int main () {
    
    double x, y;
    int n, i, p;

    p = 1;
    
    scanf("%lf %d", &x, &n);
    
    for (i=0;i<=n;i++) {        
        double num, den;

        num = pow (-1,i)*pow(x,(2*i));

        if (i==0) {
            den = 1;
        }
        
        if (i!=0) {
            den = 1;
            for (p=1;p<=(2*i);p++) {
                den *= p;
            }
        }
        y += num/den;

    }

    printf("cos(%.2lf) = %.6lf\n", x, y);
    
    return 0;
}