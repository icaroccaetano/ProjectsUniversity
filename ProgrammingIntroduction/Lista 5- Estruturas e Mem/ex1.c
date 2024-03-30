#include <stdio.h>
#include <stdlib.h>

int main (void) 
{
    int * num;
    int * den;
    int ct, nf, cct, cnf, i, a;
    double f1, f2;
    a = 0;

    scanf("%d", &ct);
    if (ct>30)
    {
        printf("Quantidade de casos de teste invalida\n");
        return 0;
    }

    for (cct=1;cct<=ct;cct++)
    {
        scanf("%d", &nf);
        if (nf>50)
    {
        printf("Quantidade de fracoes invalida\n");
        return 0;
    }

        num = (int*) calloc (nf, sizeof(int));
        den = (int*) calloc (nf, sizeof(int));

        for (cnf=0;cnf<nf;cnf++)
        {
            scanf("%d/%d", &num[cnf], &den[cnf]);
            if(den[cnf]==0) 
            {
                printf("Alerta: Divisao por zero encontrada\n");
                return 0;
            }
        }
        printf("Caso de teste %d\n", cct);

        for (cnf=0;cnf<nf;cnf++)
        {
            f1 = (double) num[cnf]/den[cnf];
            for (i=cnf;i<nf;i++)
            {
                f2 = (double) num[i]/den[i];
                if (f1==f2)
                {
                    if (num[cnf]!=num[i] || den[cnf]!=den[cnf])
                    {
                        printf("%d/%d equivalente a %d/%d\n", num[cnf], den[cnf], num[i], den[i]);
                        a++;
                    }
                }         
            }
        }
        if (a==0)
        {
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }
        free (num);
        free (den);
    }
    return 0;
} 