#include <stdio.h>

void swap (int *x, int *y) {
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main () {
    int a, b, c;
    char x, y, z;
    scanf("%d %d %d\n", &a, &b, &c);

    if (b < a) swap (&a, &b);
    if (c < a) swap (&a, &c);
    if (c < b) swap (&b, &c);

    scanf("%c %c %c", &x, &y, &z);

    if (x=='A') {
        if (y=='B') {
            printf("%d %d %d\n", a, b, c);
        }
        if (y=='C') {
            printf("%d %d %d\n", a, c, b);
        }
    }
    if (x=='B') {
        if (y=='A') {
            printf("%d %d %d\n", b, a, c);
        }
        if (y=='C') {
            printf("%d %d %d\n", b, c, a);
        }
    }
    if (x=='C') {
        if (y=='B') {
            printf("%d %d %d\n", c, b, a);
        }
        if (y=='A') {
            printf("%d %d %d\n", c, a, b);
        }
    }
    return 0;
}