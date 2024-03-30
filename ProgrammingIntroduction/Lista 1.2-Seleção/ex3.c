#include <stdio.h>

int main () {

	int conta;
	float cons;
	char tipo;
	
	scanf("%i %f %c", &conta, &cons, &tipo);
	
	double val_final;
	
	//residencial
	if (tipo == 'R') {
		val_final = 5.00 + 0.05*cons;
	}
	
	//comercial
	if (tipo == 'C') {
		if (cons < 80.00) {
		val_final = 500.00;
	}
		else {
		val_final = ((cons-80.00)*0.25) + 500.00;
		}
	}
		
	//industrial
	if (tipo == 'I') {
		if (cons < 100.00) {
		val_final = 800.00;
		}
		else {
		val_final = ((cons-100.00)*0.04) + 800.00;
		}
	}
	
	printf("CONTA = %i\nVALOR DA CONTA = %.2f\n", conta, val_final);
	
	return 0;
}
