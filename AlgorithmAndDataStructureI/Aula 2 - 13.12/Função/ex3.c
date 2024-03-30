#include <stdio.h>
#include <math.h>

float dist (float x1, float y1, float x2, float y2);

int main (void)
{
    float x1, x2, y1, y2;

    printf("Insira os valores das coordenadas dos dois pontos\n");
    printf("    Formato = <x1> <y1> <x2> <y2>\n");

    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);

    printf("Distancia entre os dois pontos = %f\n", dist(x1, y1, x2, y2));

    return 0;
}

float dist (float x1, float y1, float x2, float y2)
{
    float r, s;
    if (x1==x2 && y1!=y2)
    {
        r = y1 -y2;
    }
    else if (y1==y2 && x1!=x2)
    {
        r = x1 -x2;
    }
    else if (x1==x2)
    {
        if (y1==y2) r = 0;
    }
    else 
    {
        s = (pow((x1-x2),2)+pow((y1-y2),2));
        r = sqrt((pow((x1-x2),2)+pow((y1-y2),2)));
    }

    if (r<0) r = -r;

    return r;
}
