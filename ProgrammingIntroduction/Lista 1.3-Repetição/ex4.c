#include <stdio.h>

int main () {

    int n, q;

    scanf("%i %i", &n, &q);

    if (n%2!=0) {
        printf("O PRIMEIRO NUMERO NAO E PAR\n");
        return 0;
    }
    
    printf("%i ", n); 

    while (q>1) {
        n += 2;
        q --; 
        printf("%i ", n); 
    }
    printf("\n");
    
    return 0;
}