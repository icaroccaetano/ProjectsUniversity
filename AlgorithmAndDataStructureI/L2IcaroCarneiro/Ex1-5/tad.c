#include "tad.h"

void newlist (Lista* a)
{
    a->nelem = 0;
}
int add (Lista* a, int x)
{
    if (a->nelem<nmax)
    {
        a->l[a->nelem] = x;
        a->nelem++;
        return SUCCESS;
    }
    else return ERROR;
}
void print (Lista*a)
{
    int i;
    for (i=0;i<a->nelem;i++)
    {
        printf("%d ", a->l[i]);
        if (i%6==0 && i!=0) printf ("\n");
    }
    printf("\n");
}
int check (Lista* a, int x)
{
    int i;
    for (i=0;i<a->nelem;i++)
    {
        if (a->l[i] == x) return ERROR;
    }
    return SUCCESS;
}
Lista concatena (Lista* a, Lista* b)
{
    Lista r;
    newlist(&r);
    int i, j;
    for (i=0;i<a->nelem;i++) /*adicionando os termos da lista a*/
    {
        add(&r,a->l[i]);
    }
    for (j=0;j<b->nelem;j++) /*adicionando os termos da lista b*/
    {
        if(check(&r,b->l[j]) == SUCCESS)
        {
            add(&r,b->l[j]); /* conferindo se o termo ja esta na sequencia*/
            i++;
        }
    }
    return r;
} 
void auxremove (Lista* a)
{
    int i, j;
    if (a->nelem>0)
    {
        for (i=0;i<a->nelem;i++)
        {
            a->l[i] = a->l[i+1];
        }
        a->nelem--;
    }
}
void remove_ (Lista *a, int x)
{
    int i;
    for (i=0;i<x;i++)
    {
        auxremove (a);
    }
}
int maiorValor (Lista* a, int* pos, int* val)
{
    int i, ps, aux;
    ps = 0;
    for (i=0;i<a->nelem;i++)
    {
        if (a->l[i]>a->l[ps])
        {
            ps = i;
        }
    }
    *pos = ps;
    *val = a->l[ps];

    if (a->l[*pos] != *val) ERROR;
    else return SUCCESS;
}
int par (Lista* a)
{
    int i, r=0;
    for (i=0;i<a->nelem;i++)
    {
        if (a->l[i]%2 == 0) r++;
    }
    return r;
}
double media (Lista* a)
{
    int i, r=0;
    for (i=0;i<a->nelem;i++)
    {
        r += a->l[i];
    }
    return ((double) r/a->nelem);
}