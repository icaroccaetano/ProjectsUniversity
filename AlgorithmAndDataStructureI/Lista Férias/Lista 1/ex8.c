#include<stdio.h>
 
int main() {
    int t, num, i, r;
 
    scanf("%d", &t);
    for (t;t>0;t--)
    {
        scanf("%d", &num);
        r = 0;
        for (i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
            r++;
            break;
            }
        }
    
        if (r == 0) printf("primo\n");
        else printf("composto\n");
    }
    return 0;
}