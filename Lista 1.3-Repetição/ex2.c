#include <stdio.h>

int main () {

	double tf, tc;
	int quant;
	
	scanf("%i", &quant);
	
	while (quant > 0) {
		scanf("%lf", &tf);
		tc = (5.00*(tf-32.00))/9.00;
		printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", tf, tc);
		quant --; }
	
	return 0;
}
