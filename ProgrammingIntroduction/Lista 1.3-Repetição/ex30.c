#include <stdio.h>
int somadiv (int n) {
    int som, div;
    som = 0;
    for(div=1;div<n;div++) {
        if (n%div==0) {
            som += div;
        }
    }
    return som;
}
int main () {
    int n, x, y, i;
    i=0;
    scanf("%d", &n);

        for (x=1;i<n;x++) {
            y = somadiv (x);
            
            if (somadiv(y) == x && x>y) {
                printf ("(%d,%d)\n", y, x);
                i++;
            }
        }
    return 0;
}