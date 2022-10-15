#include "tad.h"

int main (void)
{
    char i;
    String palavra;

    init (&palavra);
    printf ("Escreva a palavra e termine com um enter:\n");
    while (1)
    {
        scanf("%c", &i);
        if (i == '\n') break;
        add(&palavra,i);
    }
    charQuickSort (&palavra,0,palavra.pos-1);
    print (&palavra);
}