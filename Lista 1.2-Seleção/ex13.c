#include <stdio.h>

int main () {
		
	int a, b, c, d;
	int soma;
	
	scanf("%d", &a);		
	scanf("%d", &b);
	scanf("%d", &c);	
	scanf("%d", &d);
	
	
	if (a>=b && a>=c && a>=d) {
		soma = b+c+d; }
	
	else if (b>=a && b>=c && b>=d) {
		soma = a+c+d; }

	else if (c>=b && c>=a && c>=d) {
		soma = a+b+d; }

	else if (d>=b && d>=c && d>=a) {
		soma = a+b+c; }

	
	printf("%d\n", soma);
	
	
	return 0;
}

