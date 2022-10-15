#include <stdio.h>
#define vTam 10

void mergesort (int *vec, int ini, int fim);
void merge (int *vec, int ini, int meio, int fim);

int main (void)
{
    int vec[vTam] = {10,5,4,7,2,8,1,6,3,9};
    int i;

    mergesort (vec,0,vTam-1);


    for (i=0;i<vTam;i++)
    {
        printf ("%d ", vec[i]);
        if (i!=0 && i%5==0) printf ("\n");
    }
    if (i-1==0 || i-1%5!=0) printf("\n");
}

void mergesort (int *vec, int ini, int fim)
{
    int meio;
    if (ini<fim)
    {   
        meio = (ini+fim)/2;
        mergesort (vec,ini,meio);
        mergesort (vec,meio+1,fim);
        merge (vec,ini,meio,fim);
    }
}

void merge (int *vec, int ini, int meio, int fim)
{
    int com1 = ini, com2 = meio+1, comaux = 0, vetaux[(fim-ini)+1];
    while (com1<=meio && com2<=fim)
    {
        if (vec[com1]<=vec[com2])
        {
            vetaux[comaux] = vec[com1];
            com1++;
        }
        else
        {
            vetaux[comaux] = vec[com2];
            com2++;
        }
        comaux++;
    }
    while (com1<=meio) //enquanto ainda esteja mexendo na primeira parte (for menor que o meio) (vai mexer nele ainda e a seg parte ja ta pronta)
    {
        vetaux[comaux] = vec[com1];
        comaux++;
        com1++;
    }
    while (com2<=fim) //enquanto ainda esteja mexendo na primeira parte (for menor que o meio) (vai mexer nele ainda e a seg parte ja ta pronta)
    {
        vetaux[comaux] = vec[com2];
        comaux++;
        com2++;
    }
    for(comaux=ini;comaux<=fim;comaux++) //irei sobrepor o vetor original pelo vetro auxiliar que foi o que eu mexi
    {
        vec[comaux] = vetaux[comaux-ini];
    }
}