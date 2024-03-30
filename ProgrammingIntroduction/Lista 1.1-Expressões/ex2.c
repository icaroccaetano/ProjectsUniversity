#include <stdio.h>

int main () {

	float faren;
	float poleg;

	scanf("%f", &faren);
	scanf("%f", &poleg);
	
	double celsius = (5*(faren-32))/9;
	double mm = poleg*25.4;
	
	printf("O VALOR EM CELSIUS = %.2lf\n", celsius);
	printf("A QUANTIDADE DE CHUVA E = %.2lf\n", mm);
	
	return 0;
}
