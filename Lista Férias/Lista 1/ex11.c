#include <stdio.h>
#define nmax 10

void readm (int m[nmax][nmax], int l, int c);
void som (int a[nmax][nmax], int b[nmax][nmax],  int l, int c);
void mult (int a[nmax][nmax], int b[nmax][nmax], int l, int c);


int main (void)
{
    int l, c;
    int a[nmax][nmax], b[nmax][nmax];
    char op;

    scanf("%d %d", &l, &c);
    readm(a,l,c);
    scanf("%*c%c", &op);
    readm(b,l,c);
    switch (op)
    {
        case '+': 
            som(a,b,l,c);
        break;
        case 'x': 
            mult(a,b,l,c);
        break;
        default:
            printf("operacao invalida\n");
    }

    return 0;   
}

void readm (int m[nmax][nmax], int l, int c)
{  
    int cl, cc;
    for (cl=0;cl<l;cl++) {
        for (cc=0;cc<c;cc++) {
            scanf("%d", &m[cl][cc]);
        }
    }    
    return;
}

void som (int a[nmax][nmax], int b[nmax][nmax],  int l, int c)
{
    int cl, cc;
    int r[nmax][nmax];

    for (cl=0;cl<l;cl++)
    {
        for (cc=0;cc<c;cc++)
        {
            r[cl][cc] = a[cl][cc] + b[cl][cc];
        }
    }

    for (cl=0;cl<l;cl++)
    {
        for (cc=0;cc<c;cc++)
        {
            printf("%d ", r[cl][cc]);
        }
        printf("\n");
    }
}

void mult (int a[nmax][nmax], int b[nmax][nmax], int l, int c)
{
    int i, j, x, aux;
    int r[nmax][nmax];
    
    if (l==c)
    {
        for(i=0;i<l;i++) 
        {
            for(j=0;j<c;j++) 
            {			
                r[i][j] = 0;
                for(x = 0; x < l; x++) 
                {
                    aux +=  a[i][x] * b[x][j];
                }

                r[i][j] = aux;
                aux = 0;
            }
        }
        
        for(i=0;i<l;i++) {
            for(j=0;j<c;j++) {
                printf("%d ", r[i][j]);
            }
            printf("\n");
        }
    }
    else printf("ERROR\n");
}
