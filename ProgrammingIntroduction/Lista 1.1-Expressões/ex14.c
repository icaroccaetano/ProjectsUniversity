#include <stdio.h>

int main () {

	int n;
	int a, b, c, d;
	
	scanf("%d" , &n);
	
	a = n/100;
	b = (n%100)/10;
	c = n%10;
	d = (a + (b*3) + (c*5)) % 7;
	
	n = n*10+d;

	printf("O NOVO NUMERO E = %d\n", n);

	return 0;
}
