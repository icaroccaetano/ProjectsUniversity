#include <stdio.h>

//dificuldade em como acelerar o processo, nao conseguiu resolver o n=100 :(

int  fibo (int i);
void fato (int n);

int main (void)
{
    int i, q, n;
    
    scanf("%d", &q);

    for (i=0;i<q;i++)
    {
        scanf("%d", &n);
        fato(fibo (n));
        printf("\n");
    }
    return 0;
}

void fato (int n)
{
    int div;
    for (div=2;n>1;)
    {
        if (n%div==0) 
        {
            printf("%d ", div);
            n /= div;
        }
        else div++;
    }
}

int fibo (int i)
{
    if (i==0 || i==1 || i==2) return 1;
    
    return (fibo(i-1) + fibo(i-2));
}