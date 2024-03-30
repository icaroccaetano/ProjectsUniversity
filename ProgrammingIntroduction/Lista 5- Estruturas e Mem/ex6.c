#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int mat;
    int dia;
    int mes;
    int ano;
    char nome[200];
}   Dados;

void swap_char (char *a, char *b);

void swap_int (int *a, int *b);

void swap_struct (Dados a, Dados b);

void ordena (Dados * a, int n);


int main (void)
{
    int n, qta, i;

    scanf("%d", &n);

    qta = (int) calloc (n, sizeof(int));

    Dados dados[qta];

    for (i=0;i<n;i++)
    {
        scanf("%d %d %d %d", &dados[i].mat, &dados[i].dia, &dados[i].mes, &dados[i].ano);
        scanf("%s", &dados[i].nome);
    }

    ordena (dados,n);

    print_struct(dados,n);

    free (&qta);
    return 0;
}

void swap_struct (Dados a, Dados b)
{  
    swap_int (a.ano, b.ano);
    swap_int (a.mes, b.mes);
    swap_int (a.dia, b.dia);
    swap_int (a.mat, b.mat);
    swap_char (a.nome, b.nome);    
    return;
}

void swap_char (char *a, char *b)
{
    char aux[200];
    strcpy (aux, a);
    strcpy (a, b);
    strcpy (b, aux);
}

void swap_int (int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void ordena (Dados * a, int n)
{
    int i, m, y, e;

    for (y=(n-1);y>=0;y--)
    m = 0;
    {
        for (i=0;i<n;i++)
        {
            if(a[i].ano > a[m].ano)
            {
                m = i;
            }
            if(a[i].ano = a[m].ano)
            {
                if(a[i].mes < a[m].mes) {m = i;}
                if(a[i].mes = a[m].mes)
                {
                    if(a[i].dia < a[m].dia) {m = i;}
                }
            }
        }
        swap_struct (a[m],a[0+e]);
        e++;
    }
    return;
}

void print_struct (Dados * a, int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("Matric.: %d Nome.:%s Data Nasc.: %d/%d/%d\n", a->mat, a->nome, a->dia, a->mes, a->ano);
    }
    return;
}