#include <stdio.h>

int main() {

	float a, b, c, d, e, f, x, y;
	
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	scanf("%f", &d);
	scanf("%f", &e);
	scanf("%f", &f);

	
	float g = (a*f)/d;
	float h = (a*e)/d;
	
	y = (c-g)/(b-h);
	x = f/d-(e*y)/d;
	
	printf("O VALOR DE X E = %.2f\n", x);
	printf("O VALOR DE Y E = %.2f\n", y);
	
	return 0;
}



