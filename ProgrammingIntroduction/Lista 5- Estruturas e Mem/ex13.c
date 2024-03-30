#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    float real;
    float imag;
} Complex;

typedef struct
{
    Complex x1;
    Complex x2;
} RaizEqu2;

RaizEqu2 calcula_raiz_equ_2 (float a, float b, float c);
void complex_print (Complex c);

int main (void)
{
    float a,b,c;

    scanf("%f %f %f", &a, &b, &c);

    RaizEqu2 Resp;

    Resp = calcula_raiz_equ_2(a,b,c);
    //printando resposta
    printf("x1 = ");
    complex_print(Resp.x1);
    printf("x2 = ");
    complex_print(Resp.x2);

    return 0;
}

RaizEqu2 calcula_raiz_equ_2 (float a, float b, float c)
{
    RaizEqu2 Raiz;
    if ((b*b-4*a*c)<0) 
    {
        Raiz.x1.imag = +1;
        Raiz.x2.imag = -1;
    }
    Raiz.x1.real = -b + sqrt((b*b-4*a*c));
    Raiz.x2.real = -b - sqrt((b*b-4*a*c));

    return Raiz;
}

void complex_print (Complex c)
{
//    printf("a parte  real ta valendo %f e a imag %f\n", c.real, c.imag);
    if (c.real != 0)
    {
        printf ("%lf", c.real);
        if (c.imag == 1 || c.imag == -1)
        {
            if (c.imag = 1) {printf("+i\n");}
            if (c.imag = -1) {printf("-i\n");}
            return;
        }
    }
    if (c.real = 0)
    {
        if (c.imag == 1 || c.imag == -1)
        {
            if (c.imag = 1) {printf("i\n");}
            if (c.imag = -1) {printf("-i\n");}
            return;
        }
    }
    if (c.real==0 && c.imag==0)
    {
        printf("0\n");
        return;
    }
    return;
}

