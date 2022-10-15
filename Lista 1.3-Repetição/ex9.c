#include <stdio.h>

int main () {
    int n, f;
    scanf("%d", &n);
    f = 1;
    
    printf("%d! ", n);
    
    if (n==0) {
        f = 1;
    }
    else {
        for (n;n>0;n--) {
            f *= n;
        }
    }
    
    printf("= %d\n", f);
    
    return 0;
}