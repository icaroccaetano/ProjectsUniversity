#include <stdio.h>

int main () {
    
    int num, a, b, c, d, e;

    scanf ("%d", &num);

    if (num>99999) {
        printf("NUMERO INVALIDO\n");
        return 0;
    }
    a = num/10000;
    b = num%10000/1000;
    c = num%1000/100;
    d = num%100/10;
    e = num%10;

    if (num<9) {
        printf("PALINDROMO\n");
        return 0;
    }
    if (num<99) {
        if (d==e) printf("PALINDROMO\n");
        else      printf("NAO PALINDROMO\n");
        return 0;
    }
    if (num<999) {
        if (c==e) printf("PALINDROMO\n");
        else      printf("NAO PALINDROMO\n");
        return 0;
    }
    if (num<9999) {
        if (b==e && c==d) printf("PALINDROMO\n");
        else      printf("NAO PALINDROMO\n");
        return 0;
    }
    if (num<99999) {
        if (a==e && b==d) printf("PALINDROMO\n");
        else      printf("NAO PALINDROMO\n");
        return 0;
    }
    return 0;
}
