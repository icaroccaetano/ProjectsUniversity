#include <stdio.h>

void read_m (int l, int c, int  m[2][2]);
int confere (int v[5], int m[2][2]);
void initv (int *v);

int main(void)
{
    int v[5]; 
    int m[2][2], i, r, j;

    printf("inserir os 5 valores do diferentes do vetor:\n");
    for (i=0;i<5;i++) 
    {
        scanf("%d", &v[i]);
        verificacao:        
        for(j=(i-1);j>=0;j--) 
        {
            if(v[i]==v[j]) 
            {                
                scanf("%d", &v[i]); 
                goto verificacao;
            }
        }
    }
    printf("Inserir os 4 valores da matriz:\n");
    read_m (2,2,m);
    
    r = confere(v,m);

    printf("%d números estão presentes no vetor e na matriz\n", r);

}

void read_m (int l, int c, int  m[2][2])
{
    int al, ac;
    for (al=0;al<l;al++)
    {
        for (ac=0;ac<c;ac++)
        {
            scanf("%d", &m[al][ac]);
        }
    }
    return;
}

void initv (int *v)
{
    int i;
    for (i=0;i<5;i++)
    {
        v[i] = '\0';
    }
    return;
}   

int confere (int v[5], int m[2][2])
{
    int i, l, c, r, j;
    int vc[5];
    initv (vc);
    j = 0;
    r = 0;
    for (i=0;i<5;i++)
    {
        for (l=0;l<2;l++)
        {
            for(c=0;c<2;c++)
            {
                if(m[l][c] == v[i])
                {
                    if (v[i] != vc[0] && v[i] != vc[1] && v[i] != vc[2] && v[i] != vc[3] && v[i] != vc[4])
                    {
                        vc[j] = v[i];
                        r++;
                        j++;
                    }
                }
            }
        }
    }
    return r;
}
