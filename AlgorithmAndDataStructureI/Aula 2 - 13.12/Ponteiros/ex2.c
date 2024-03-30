#include <stdio.h>

void comp_end (int x, int y);

int main (void)
{
    int a, b;

    comp_end (a,b);

    return 0;
}

void comp_end (int x, int y)
{
    if (&x>&y)  printf("Maior endereço = %d\n", &x);
    else        printf("Maior endereço = %d\n", &y);    
}