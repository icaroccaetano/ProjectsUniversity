#include <stdio.h>
#define nmax 1000

int main ()
{
    int v[nmax], i, n, c;
    c = 0;
    scanf("%d", &n);
    if (n<1 || n>nmax) return 0;

    for (i=0;i<n;i++)
    {
        scanf("%d", &v[i]);
    }
    for (i=0;i<n;i++)
    {
        if (v[i]%2==0)
        {
            printf("%d ", v[i]);
            c++;
        }
    }
    printf("%d", c);    
    printf("\n");
    return 0;
}
