#include <stdio.h>
#define nmax 1000

void read_m (int l, int c, int  m[nmax][nmax]);
int diag_p (int l, int c, int m[nmax][nmax]);

int main (void)
{
    int n;
    int m[nmax][nmax];

    read_m (n,n,m);

    return 0;
}

void read_m (int l, int c, int  m[nmax][nmax])
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

int diag_p (int l, int c, int m[nmax][nmax]) {
    int s, al, ac;
    s = 0;
    for(al=0;al<l;al++) {
        for(ac=0;ac<c;ac++) {
            if(al==ac) {
                s += m[al][ac];
            }
        }
    }
    return s;
}