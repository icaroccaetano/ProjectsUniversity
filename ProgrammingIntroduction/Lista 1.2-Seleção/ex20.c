#include <stdio.h>


int main () {
    int pf, esc, etn;
    double rb;

    scanf("%lf %d %d %d", &rb, &pf, &esc, &etn);

    if (esc==2) {
        if ((rb/pf)<=1405.5) {
            if (etn == 4) {
                printf("ALUNO COTISTA (L1)\n");
            }
            else {
                printf("ALUNO COTISTA (L2)\n");
            }
        }
        else {
            if (etn == 4) {
                printf("ALUNO COTISTA (L3)\n");
            }
            else {
                printf("ALUNO COTISTA (L4)\n");
            }
        }
    }
    else {
        printf("ALUNO NAO COTISTA\n");
    }
    return 0;
}