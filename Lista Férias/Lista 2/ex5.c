#include <stdio.h>

void bin (int n);

int main (void)
{
    int i, t, n;

    scanf("%d", &t);
    for (i=0;i<t;i++)
    {
        scanf("%d", &n);
        bin (n);
        printf("\n");
    }
    return 0;
}

void bin (int n) 
{
   if (n==0) printf("%c", '\0');

    else
    {
        bin((n-(n%2))/2);
        printf("%d", n%2);
    }
}