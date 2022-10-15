#include <stdio.h>

int main (void) 
{
    int a[4], b[4], i, s;

    printf("Números do primeiro vetor:\n");
    for (i=0;i<4;i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Números do segundo vetor:\n");
    for (i=0;i<4;i++)
    {
        scanf("%d", &b[i]);
    }

    for (i=0;i<4;i++)
    {
        s = a[i] + b[i];
        printf("Soma dos números do índice %d = %d\n", i, s);
    }
    return 0;
}