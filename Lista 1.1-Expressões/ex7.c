#include <stdio.h>
#include <math.h>

int main () {

	float h, a, ab, v;

	scanf("%f %f", &h, &a);

	ab = (3.00*pow(a,2.00)*sqrt(3.00))/2.00;
	v = (1.00/3.00)*ab*h;
	
	printf("O VOLUME DA PIRAMIDE E = %.2lf METROS CUBICOS\n", v);

	return 0;
}
