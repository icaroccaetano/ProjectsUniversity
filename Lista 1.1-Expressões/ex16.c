#include <stdio.h>

int main () {

	int num;
	
	scanf("%d", &num);
	
	int a, b, c;
	
	a = num/100;
	b = (num - (a*100))/10;
	c = num - (a*100) - (b*10);
	
	printf("%d%d%d", c, b, a);

	return 0;
}
