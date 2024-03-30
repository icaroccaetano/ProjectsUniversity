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
    int i, n;
    double x, y;
 
    scanf("%lf", &x);
    scanf("%d", &n);
 
    for (i=0;i<=n;i++) {
        y += (pow(x,i))/(fat(i));
    }
 
    printf("e^%.2lf = %lf\n", x, y);
    return 0;
}