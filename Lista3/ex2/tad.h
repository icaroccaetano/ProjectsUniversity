#include <stdio.h>
#include <string.h>
#define nmax 64

typedef struct
{
    char palavra[nmax];
    int pos;
} String;

void init (String *palavra);
void add (String *palavra, char lt);
void print (String *palavra);
void charQuickSort (String * Palavra, int inicio, int fim);