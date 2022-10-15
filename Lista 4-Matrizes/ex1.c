#include <stdio.h>

int main () {
    double m[2][2];
    int l, c;
    double r;

    for (l=0;l<2;l++) {
        for (c=0;c<2;c++) {
            scanf("%lf", &m[l][c]); 
        }
    }
    r = (m[0][0]*m[1][1]) - (m[0][1]*m[1][0]);
    
    printf("%.2lf\n", r);
    return 0;
}