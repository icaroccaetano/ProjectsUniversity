#include <stdio.h>
#include <math.h>

int main () {

	double x1;
	double y1;
	double x2;
	double y2;
	
	scanf("%lf", &x1);
	scanf("%lf", &y1);
	scanf("%lf", &x2);
	scanf("%lf", &y2);
	
	double d = sqrt(pow((x2-x1),2.00) + pow((y2-y1),2.00));
	
	printf("A DISTANCIA ENTRE A e B = %.2lf\n", d);

	return 0;
}
