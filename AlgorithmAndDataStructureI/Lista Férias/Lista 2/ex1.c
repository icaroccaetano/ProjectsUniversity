#include <stdio.h>

void count (int n);

int main (void)
{
    int n;
    
    scanf("%d", &n);
    count(n);
    printf("\n");
    return 0;
}

void count (int n)
{
    if (n==1) printf("%d ", n);

    else
    {
        count (n-1);   
        printf("%d ", n);
    }
} 