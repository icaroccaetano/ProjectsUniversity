#include <stdio.h>
#define max 10
int main () {
    int m[max][max];
    int l, c, cl, cc, bt;
    scanf("%d %d", &l, &c);
    printf("P2\n%d %d\n1\n\n", c, l);
        
    for (cl=0;cl<l;cl++) {        
        
        for (cc=0;cc<c;cc++) {            
            if (cl==0 || cl%2==0) {
                if (cc==0 || cc%2==0) {
                    printf("1 ");
                    continue;
                }
                else if (cc%2!=0) {
                    printf("0 ");
                    continue;
                }
            }
            else if (cl%2!=0) {
                if (cc==0 || cc%2==0) {
                    printf("0 ");
                    continue;
                }
                else if (cc%2!=0) {
                    printf("1 ");
                    continue;
                }
            }
        }
        printf("\n");
    }
    return 0;
}