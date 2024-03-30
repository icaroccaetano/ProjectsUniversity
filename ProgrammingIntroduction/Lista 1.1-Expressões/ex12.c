#include <stdio.h>
#include <math.h>

int main () {

	double massa, acel, tempo_dec;

	scanf("%lf", &massa);
	scanf("%lf", &acel);
	scanf("%lf", &tempo_dec);
	
	double veloc = (acel * tempo_dec)*3.60;
	double espac = (acel * pow(tempo_dec, 2.00))/2;
	double traba = ((massa*1000)*pow((veloc/3.60), 2.00))/2.00;

	printf("VELOCIDADE = %.2lf\nESPACO PERCORRIDO = %.2lf\nTRABALHO REALIZADO = %.2lf\n", veloc, espac, traba);
	
	return 0;
}
