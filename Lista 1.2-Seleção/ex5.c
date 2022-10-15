#include <stdio.h>

int main () {

	int hrs;
	
	scanf("%i", &hrs);
	
	double total;
	int aux1, aux2;
	
	aux1 = hrs/3;
	aux2 = hrs%3;
	
	total = (aux1*10.00) + (aux2*5.00);
	
	printf("O VALOR A PAGAR E = %.2lf\n", total);
	
	return 0;
}
