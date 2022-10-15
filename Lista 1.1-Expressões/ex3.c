#include <stdio.h>
#define PI 3.14159

int main () {

	float raio;
	float altura;
	
	scanf("%f", &raio);
	scanf("%f", &altura);
	
	float al = 2*PI*raio*altura;
	float ac = PI*(raio*raio);
	float at = 2*ac+al;
	float preco = at * 100.00;
	
	printf("O VALOR DO CUSTO E = %.2f\n", preco);


	return 0;
}
