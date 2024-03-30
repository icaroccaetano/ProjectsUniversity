#include <stdio.h>

int main () {

	int num;
	
	scanf("%i", &num);
	
	int resto3, resto5, soma;
	
	resto3 = num%3;
	resto5 = num%5;
	soma = resto3 + resto5;
	
	if (soma != 0) {
		printf("O NUMERO NAO E DIVISIVEL\n");
	}		
	else {
		printf("O NUMERO E DIVISIVEL\n");
	}
				
	return 0;
}
