#include <stdio.h>
#include <math.h>

int main () {

	double a, b, c, d, x1, x2;
	
	scanf("%lf %lf %lf", &a, &b, &c);	
		
	d = (b*b) - (4.00*a*c);
	
	int delta;	
	if (d==0) {
		delta = 1; 
	}
	if (d>0) {
		delta = 2; 
	}
	if (d<0) {
		delta = 3; 
	}
	
	switch (delta) {
		case 1:
		printf("RAIZ UNICA\n");
		x1 = -b/(2.00*a);
		printf("X1 = %.2lf\n", x1);
		break;
		
		case 2:
		printf("RAIZES DISTINTAS\n");
		x1 = (-b+sqrt(d))/(2.00*a);
		x2 = (-b-sqrt(d))/(2.00*a);
		if (x2>x1)
			printf("X1 = %.2lf\nX2 = %.2f\n", x1, x2);
		else 
			printf("X1 = %.2lf\nX2 = %.2f\n", x2, x1);
		break;
		
		case 3:
		printf("RAIZES IMAGINARIAS\n");
		break;
	}
	
	return 0;
}

