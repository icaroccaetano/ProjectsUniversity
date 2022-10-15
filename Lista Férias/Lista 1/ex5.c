#include <stdio.h>
#include <math.h>

void tetrade (int n);
void print (char* a, int c);
char simb (int n);

int main (void)
{
    int t, n, i;

    scanf("%d", &t);
    
    for (i=0;i<t;i++)
    {
        scanf("%d", &n);
        tetrade (n);
    }
    return 0;   
}

void tetrade (int n)
{
    int i;
    char * r;

    for (i=0;;i++)
    {
        if (n<4)
        {
            r[i] = simb(n);
            break;
        }
        r[i] = simb(n%4);
        n = (n-(n%4))/4;        
    }
    print (r,i);
}

char simb (int n)
{
    char c;
    if (n==0) c = 'A';
    if (n==1) c = 'C';
    if (n==2) c = 'G';
    if (n==3) c = 'T';

    return c;
}

void print (char* a, int c)
{
    int i;
    for (;c>=0;c--)
    {
        printf("%c", a[c]);
    }
    printf("\n");
}