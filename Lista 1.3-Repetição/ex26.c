#include <stdio.h>

int main () {
    int n, i, som;

    scanf("%d", &n);
    som = 1;
   
    printf("%d = 1", n);

    
    for(i=2;i<n;i++) {
        if (n%i==0) {
            som += i;
            printf(" + %d", i);        
        }
    }
    printf(" = %d", som);

    if (som==n) {printf(" (NUMERO PERFEITO)\n");} 
    else {printf(" (NUMERO NAO E PERFEITO)\n");}  
    return 0;
}