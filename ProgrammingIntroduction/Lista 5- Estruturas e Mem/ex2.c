#include <stdio.h>
#include <string.h>

typedef struct  
{
    char nome [36];
    double preco;
} alimento;

int main (void)
{
    int n, i, m, a, p, cp, qt;
    char prod[36];
    double soma;

    scanf("%d", &n);
    for (i=0;i<n;i++)
    {
        soma = 0.0;
        scanf("%d", &m);
        alimento disp[m];
        for (a=0;a<m;a++)
        {
            scanf("%s %lf", &disp[m].nome, &disp[m].preco);
        }
        scanf("%d", &p);
        for (cp=0;cp<p;cp++)
        {
            scanf("%s %d", &prod, &qt);
            for (p=0;p<m;p++)
            {
                if (disp[p].nome == prod)
                {
                    soma += disp[p].preco*qt;
                }
            }
        }
        printf ("R$ %.2lf\n", soma);
    }
    return 0;
}