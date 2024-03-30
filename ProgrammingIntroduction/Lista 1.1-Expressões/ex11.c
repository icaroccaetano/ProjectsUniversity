#include <stdio.h>

int main () {

	float preco_fab, dist, imp;
	
	scanf("%f", &preco_fab);
	scanf("%f", &dist);
	scanf("%f", &imp);

	float preco_final = preco_fab + ((dist/100)*preco_fab) + ((imp/100)*preco_fab);
	
	printf("O VALOR DO CARRO E = %.2f\n", preco_final);
	
	return 0;
}
