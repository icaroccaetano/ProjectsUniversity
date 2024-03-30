#include <stdio.h>
int main () {

    unsigned long int cod;
    double pc, pv, rv, x, y, z, auxu;
    int vendas, r, s, t, u, v, auxv, c;
    r = 0;
    s = 0;
    t = 0;
    auxu = 0;
    auxv = 0;
    x = 0;
    y = 0;

    while (scanf("%li %lf %lf %d", &cod, &pc, &pv, &vendas) != EOF) {     

        rv = (pv/pc);

        if (rv<1.1) {r+=1;}
        if (rv>=1.1 && rv<=1.2) {s+=1;}
        if (rv>1.2) {t+=1;}

        if (rv>auxu) {
            auxu = rv;
            u = cod;
        }

        if (vendas>auxv) {
            auxv = vendas;
            v = cod;
        }

        x += (pc*vendas);
        y += (pv*vendas);        
    } 

    z = (y/x);
    if (z>=1) {z -= 1;}
    if (z>=2) {z -= 2;}
    if (z>=3) {z -= 3;}
    if (z>=4) {z -= 4;}
    z *= 100;

    printf("Quantidade de mercadorias que geraram lucro menor que 10%%: %d\nQuantidade de mercadorias que geraram lucro maior ou igual a 10%% e menor ou igual a 20%%: %d\nQuantidade de mercadorias que geraram lucro maior do que 20%%: %d\n",r, s, t);

    printf("Codigo da mercadoria que gerou maior lucro: %d\nCodigo da mercadoria mais vendida: %d\n", u, v);

    printf("Valor total de compras: %.2lf, valor total de vendas: %.2lf e percentual de lucro total: %.2f%%\n", x, y, z);

    return 0;
}