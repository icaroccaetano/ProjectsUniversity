#include <stdio.h>
#define nmax 499
int findchar (char c, char s[nmax]) {
    int r, i;
    r = -1;

    for (i=0;s[i]!= '\n';i++) 
        if (s[i] == c) {
            r = i;
            return r;
        }
    return r;
}

int main () {
    int ct, i, as;
    char v[nmax], c;
    scanf("%d ", &ct);

    for (ct;ct>0;ct--) {
        scanf("%c ", &c);
        
        for (i=0;i<=nmax;i++) {
            scanf("%c", &v[i]);
            if(v[i] == '\n')
            break;
        }
        as = findchar(c, &v[0]);
        if (as == -1) {
            printf("Caractere %c nao encontrado.\n", c);
        }
        else {
            printf("Caractere %c encontrado no indice %d da string.\n", c, as);
        }
    }

    return 0;
}