#include <stdio.h>
int main () {

	double A;
	double B;
	double C;
	
	scanf("%lf", &A);
	scanf("%lf", &B);
	scanf("%lf", &C);
	
	float delta = (B*B) - 4*A*C;
	
	printf("O VALOR DE DELTA E = %.2f\n", delta);

	return 0;
}
