#include <stdio.h>
#define vTam 10
#define MAXTAM 10

void quicksort (int *vec, int esq, int dir);
void mostra_vetor(int v[]);

int main (void)
{
    int vet[vTam] = {3,2,4,1,5,8,7,9,10,6};
    int i;

    quicksort(vet,0,10);

    for (i=0;i<vTam;i++)
    {
        printf ("%d ", vet[i]);
        if (i%5==0 && i!=0) printf ("\n");
    }
}

void quicksort (int *vec, int esq, int dir)
{
    int i, j, pivo, aux;    
    i = esq;
    j = dir;
    pivo = vec[(esq + dir) / 2];
     
    while(i <= j) {
        while((int)(vec[i] < pivo) && i < dir) {
            i++;
        }
        while((int)(vec[j]) > pivo && j > esq) {
            j--;
        }
        if(i <= j) {
            aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
            i++;
            j--;
        }
    }
     
    if(j > esq) {
        quicksort(vec, esq, j);
    }
    if(i < dir) {
        quicksort(vec, i, dir);
    }
}