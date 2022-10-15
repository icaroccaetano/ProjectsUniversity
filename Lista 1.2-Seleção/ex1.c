#include <stdio.h>

int main () {
	
	double n1, n2, n3;
	
	scanf("%lf %lf %lf", &n1, &n2, &n3);
	
	double media;

	media = (n1 + n2 + n3)/3.00;
	
	if (media >= 6.00) {
		printf("MEDIA = %.2lf\nAPROVADO\n", media);
	}
	else {
		printf("MEDIA = %.2lf\nREPROVADO\n", media);
	}
	
	return 0;
}
