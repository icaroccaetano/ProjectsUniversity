#include <stdio.h>

int som_dob (int * x, int * b);

int main (void)
{
    int a, b;
    printf("Valores de a e b:\n");
    scanf ("%d %d", &a, &b);

    printf("Soma do dobro dos valores =  %d\n", som_dob (&a, &b));

    return 0;
}

int som_dob (int * x, int * y)
{
    int r;
    *x = *x * 2;
    *y = *y * 2;
    r = *x + *y;
    return r;
}