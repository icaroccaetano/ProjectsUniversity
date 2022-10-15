#include <stdio.h>

int main () {
    int n, x, y, aux1,aux2;
    
    scanf ("%d", &n);

    for (x=1;x<n;x++) {
        
        for (y=x;y<n;y++) {
            aux1 = (x*y);
            aux2 = aux1%n;
            if (aux2==1 || aux1==1) {
                printf("(%d,%d)\n", x, y);                        
            }
        }
    }
    return 0;
}