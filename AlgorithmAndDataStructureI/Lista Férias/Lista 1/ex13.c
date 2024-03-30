#include <stdio.h>

int fibo (int i);

int main (void)
{
    int i, q, n;
    
    scanf("%d", &q);

    for (i=0;i<q;i++)
    {
        scanf("%d", &n);
        printf("%d\n", fibo (n));
    }
    return 0;
}

int fibo (int i)
{
    if (i==0 || i==1 || i==2) return 1;

    return (fibo(i-1) + fibo(i-2));
}