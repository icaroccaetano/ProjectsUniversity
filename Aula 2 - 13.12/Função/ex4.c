#include <stdio.h>

float media (float a, float b, float c, char m);

int main (void)
{
    float n1, n2, n3;
    char m;

    printf("Insira as tres notas e o tipo de media:\n");
    printf("   Formato = <n1> <n2> <n3> <tipo de media>\n");
    printf("Legenda da media:\n   A - Aritmetica\n   P - Ponderada\n");
    scanf("%f %f %f %c", &n1, &n2, &n3, &m);

    if (m!=65 && m!=80 && m!=97 && m!=112)
    {
        printf("Letra para media inválida");
        return 0;
    }

    printf("Media = %f\n", media (n1,n2,n3,m));

    return 0;
}

float media (float a, float b, float c, char m)
{
    float r;

    printf("soma dos valores da %f\n", a+b+c);
    //printf(Dividido por 3)
    
    if (m == 65) r = (a+b+c)/3; 
    if (m == 97) r = (a+b+c)/3;
    if (m == 80) r = (a*5+b*3+c*2)/10;
    if (m == 112) r = (a*5+b*3+c*2)/10;

    return r;
}
