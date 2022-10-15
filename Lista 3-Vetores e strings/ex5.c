#include <stdio.h>
#define nmax 5000

int main () 
{
    int v[nmax], i, n;
    scanf("%d", &n);

    if (n<1 || n>nmax) return 0;
    for (i=0;i<n;i++) 
    {
        scanf("%d", &v[i]);
    }
    for (i=0;i<n;i++) 
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}