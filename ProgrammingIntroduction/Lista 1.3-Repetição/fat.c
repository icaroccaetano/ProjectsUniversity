#include <stdio.h>
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
    int n;
    scanf("%d", &n);

    printf("%d\n", fat(n));
    return 0;
}