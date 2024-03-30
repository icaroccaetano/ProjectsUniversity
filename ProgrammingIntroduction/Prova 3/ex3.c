#include <stdio.h>
#define MAX 256

void tiravogal(char *ch, int * v) {
   int i=0,j=0;
   
   for(i=0;ch[i]!='\0';i++)
   {
   if(ch[i] == 'A' || ch[i] == 'a') {
        for(j=i; ch[j]!='\0'; j++)
            ch[j]=ch[j+1];   
        v[0] ++;
   }
   if(ch[i] == 'E' || ch[i] == 'e') {
        for(j=i; ch[j]!='\0'; j++)
            ch[j]=ch[j+1];   
        v[1] ++;
   }
   if(ch[i] == 'I' || ch[i] == 'i') {
        for(j=i; ch[j]!='\0'; j++)
            ch[j]=ch[j+1];   
        v[2] ++;
   }
   if(ch[i] == 'O' || ch[i] == 'o') {
        for(j=i; ch[j]!='\0'; j++)
            ch[j]=ch[j+1];   
        v[3] ++;
   }
   if(ch[i] == 'U' || ch[i] == 'u') {
        for(j=i; ch[j]!='\0'; j++)
            ch[j]=ch[j+1];   
        v[4] ++;
   }

   } 
}
int main() {
   char str[MAX]={0};
   int v[5] = {0, 0, 0, 0, 0};
   
   scanf("%[^\n]s",str);
   
   tiravogal(str, v);

   tiravogal(str, v);
   
   printf("%s\n",str);

   printf("a: %d\ne: %d\ni: %d\no: %d\nu: %d\n", v[0], v[1], v[2], v[3], v[4]);
   
   return 0;
}


