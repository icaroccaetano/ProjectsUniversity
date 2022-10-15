#include <stdio.h>

int main () {
    int num, x, y, i, aux;
    scanf("%d", &num);
    i = 0;
    
    for (x=1;x<=6;x++) {
        
        for (y=1;y<=6;y++) {
            aux = x+y;
            if (aux==num && x!=y) {
                printf("D1: %d, D2: %d\n", x, y);
                i++;
            }       
        }
    }
    
    if (i<1) {
        printf("Combinacao impossivel\n");
        return 0;
    }
    else {
        printf("Ha %d possibilidades\n", i);
    }
    
    return 0;
}