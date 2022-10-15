#include <stdio.h>

int dfat (int n);

int main (void)
{
    int n;

    scanf("%d", &n);
    printf("%d\n", dfat(n));

    return 0; //:)
}

int dfat (int n)
{
    if (n==1) return 1;
    else
    {
        if (n%2==0) return dfat(n-1);
        return n*dfat(n-1);
    }
}