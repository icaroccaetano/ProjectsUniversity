#include <stdio.h>
#define nmax 5000

void printinv (int * vec, int * r, int n)
{
    int i, a;
    a = n;
    
    for (i=0;i<a;i++)
    {
        r[n-1] = vec[i];
        n--;
    }
    return;
}

int main ()
{
    int n, v[nmax], i, r[nmax];
    scanf("%d", &n);
    if (n<1 || n>nmax) return 0;

    for (i=0;i<n;i++) 
    {
        scanf("%d", &v[i]);
    }
    printinv (v,r,n);
    for (i=0;i<n;i++) 
    {
        printf("%d ", r[i]);
    }
    printf("\n");
    return 0;
}
