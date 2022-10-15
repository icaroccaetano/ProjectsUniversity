#include <stdio.h>
#define CC 7
#define DR 50
#define RT 80000

int main () {
    int cc, dr, rt; 
    char tc, td, tr;

    scanf ("%d", &cc);
    scanf ("%d", &dr);
    scanf ("%d", &rt);

    if (cc < CC) {tc = 'v';}
    else {tc = 'f';}
    if (dr > DR) {td = 'v';}
    else {td = 'f';}
    if (rt > RT) {tr = 'v';}
    else {tr = 'f';}

    if (tc == 'v' && td == 'v' && tr == 'v') {
        printf("ACO DE GRAU = 10\n");
    }
    else if (tc == 'v' && td == 'v' && tr == 'f') {
        printf("ACO DE GRAU = 9\n");
    }
    else if (tc == 'v' && td == 'f' && tr == 'f') {
        printf("ACO DE GRAU = 8\n");
    } 
    else {
        printf("ACO DE GRAU = 7\n");
    }
    


    return 0;
}
