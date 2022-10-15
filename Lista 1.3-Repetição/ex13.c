#include <stdio.h>

int main () {
    int n;
    double mp, mi, p, i, cp, ci;
    p = 0;
    i = 0;
    ci = 0;
    cp = 0;

    while(1) {
        scanf("%d", &n);
        if(n==0) {
            break;
        }
        if (n%2==0) {
            p+=n;
            cp++;
        }
        if (n%2!=0) {
            i+=n;
            ci++;
        }
    }

    if (ci == 0 && cp == 0) {
        printf("SEQUENCIA INVALIDA\n");
    }
    else if (ci == 0) {
        mp = (double) p/cp;
        printf("MEDIA PAR: %lf\n", mp);
    }
    else if (cp == 0) {
        mi = (double) i/ci;
        printf("MEDIA IMPAR: %lf\n", mi);
    }
    else {
        mp = (double) p/cp;
        mi = (double) i/ci;
        printf("MEDIA PAR: %lf\nMEDIA IMPAR: %lf\n", mp, mi);
    }
    return 0;
}