#include <stdio.h>
#define max 10000

int main () {
    int n, i, l, v, co, a;
    char c[max];
    
    scanf("%d ", &n);
    
    for (i=0;i<n;i++) {
        
        l = 0;
        v = 0;
        co = 0;        

        for(;;a++) {            
            
            scanf("%c", &c[a]);
            
            if(c[a]=='\n') { break; }
    
            if(c[a]>='A' && c[a]<='z') {
                l++; 
            }
            if (c[a] == 'A' || c[a] =='E' || c[a] =='I' || c[a] =='O' || c[a] =='U' || c[a] =='a' || c[a] =='e' || c[a] =='i' || c[a] =='o' || c[a] =='u') {
                v++; 
            }
            else  {
                if(c[a]>='A' && c[a]<='z') {
                    co++;
                } 
            }
        }
        printf("Letras = %d\n", l);
        printf("Vogais = %d\n", v);
        printf("Consoantes = %d\n", co);    
    }
    return 0;
}