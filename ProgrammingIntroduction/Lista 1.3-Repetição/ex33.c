#include <stdio.h>
#include <math.h>
 
int fat (int x){
    int r=1;
    if (x==0) {
        r = 1;
        return r;
    }
    while (x>0) {
        r *= x;
        x--;
    }
    return r;
}
 
int main () {
    int i, n, p;
    double x, y, num, den, aux;
    
    scanf("%lf", &x);
    scanf("%d", &n);

    for (i=0;i<=n;i++) {
        aux = 2*i+1;
        num = pow(-1,i)*pow(x,aux);
        
        if (aux==0) {
            den = 1;
        }
        
        if (aux!=0) {
            den = 1;
            for (p=1;p<=aux;p++) {
                den *= p;
            }
        }

        y += num/den;
    }
 
    printf("seno(%.2lf) = %lf\n", x, y);
    return 0;
}