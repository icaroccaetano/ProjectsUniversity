#include <stdio.h>

int main (void)
{
    int n, a, b;
    char op;

    scanf("%d", &n);
    scanf("%d %c %d", &a, &op, &b);

    switch (op)
    {
        case '+':
            if ((a+b)>n) printf("overflow\n");
            else printf("no overflow\n");
            break;
        case 'x':
            if ((a*b)>n) printf("overflow\n");
            else printf("no overflow\n");
            break;
        default:
            printf("error: unvalid operator\n");
            break;
    }
    return 0;
}