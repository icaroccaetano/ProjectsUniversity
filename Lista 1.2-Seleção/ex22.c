#include <stdio.h>

int main () {
    int n;
    float x[3];
    float p, s, t;
    
    scanf("%d", &n);
    scanf("%f", &x[0]);
    scanf("%f", &x[1]);
    scanf("%f", &x[2]);

    if (x[0]>=x[1]) {
        p = x[0];
        s = x[1]; 
    }
    if (x[1]>x[0]) {
        p = x[1];
        s = x[0];
    }    
    if (x[2]>p) {
        t = s;
        s = p;
        p = x[2];
    }   
    if (x[2]>s && x[2]<p) {
        t = s;
        s = x[2];
    }
    if (x[2]<=s) {
        t = x[2];
    }
    if (n==1) {
        printf ("%.2f %.2f %.2f\n", t, s, p);
    }
    if (n==2) {
        printf ("%.2f %.2f %.2f\n", p, s, t);
    }
    if (n==3) {
        printf ("%.2f %.2f %.2f\n", s, p, t);
    }
    return 0;
}