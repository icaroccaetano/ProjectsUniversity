#include <stdio.h>

int a=0;
int ninv (int n);

int main (void)
{
    int n;
    scanf("%d", &n);
    ninv(n);
    printf("\n");
    return 0;
}

int ninv (int n)
{
    if (n==0) return n;
    else
    {
        if (n-(n%10)!=n || a!=0) 
        {
            a++;
            printf("%d", n%10);
        }
        n /= 10;
        return ninv(n);
        
    }
}