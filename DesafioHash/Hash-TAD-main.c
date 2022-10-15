/* Compilacao */
/* gcc -o Hash-TAD Hash-TAD-C.c Hash-TAD-main.c -lm */

#include <stdio.h>
#include "Hash-TAD-H.h"
#include <stdlib.h>
#include <sys/time.h>

#define GET_MS(ini, fim) ((fim.tv_sec * 1000000 + fim.tv_usec) - (ini.tv_sec * 1000000 + ini.tv_usec))
struct timeval inicio, fim;

int main()
{
    Lista tab[M];
    
    CriaHash(tab);
    float media = 0;
    int chaves[10] = {4899088, 3281705, 6413155, 540335, 6015638, 509519, 3991975, 5623570, 2940594, 625130};

    for (int i = 0; i < 10; i++)
    {
        gettimeofday(&inicio, NULL);

        hashSearch(tab, chaves[i]);

        gettimeofday(&fim, NULL);
        printf("\nTempo de execução: %ld ms\n\n", GET_MS(inicio, fim));
        if (i > 0)
        {
            media += GET_MS(inicio, fim);
        }
    }
    printf("\nTempo Medio execução: %f ms\n\n", media / 9);
    return 0;
}