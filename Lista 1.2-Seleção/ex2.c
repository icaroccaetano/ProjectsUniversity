#include <stdio.h>

int main () {

	int n1, n2, n3;
	
	scanf("%i", &n1);
	scanf("%i", &n2);
	scanf("%i", &n3);
	
	if (n1>9) {
		printf("DIGITO INVALIDO\n");
		return 0;
	}
	if (n2>9) {
		printf("DIGITO INVALIDO\n");
		return 0;
	}
	if (n3>9) {
		printf("DIGITO INVALIDO\n");
		return 0;
	}
	
	int numfinal, quad;
	
	numfinal = (n1*100)+(n2*10)+n3;
	quad = numfinal*numfinal;
	
	printf("%i, %i\n", numfinal, quad);

	
	return 0;
}
