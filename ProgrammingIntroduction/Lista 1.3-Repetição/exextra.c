#include <stdio.h>

int main () {
    int m, n, s, i, n1, n2, a;
    
    scanf ("%d %d %d", &m, &n, &s);

    n1 = 1; 
    n2 = 0;
    a = 0;
    
    while (n1<=m) {

    for(i=0;i<n;i++) {
        for(n2=1;n2<=m;n2++) {            
        printf ("(%2d,%2d)", n1, n2);
        }
    printf("\n");
    n1++;
    }
//    a++;
    }
    return 0;
}