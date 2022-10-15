#include <stdio.h>

int main () {
	
	double x;
	char conceito;

	scanf("%lf", &x);
	
	if (9.0<= x && x <10.0) {
			conceito = 'A'; }
	if (7.5<= x && x <9.0) {
			conceito = 'B'; }
	if (6.0<= x && x <7.5) {
			conceito = 'C'; }
	if (x <6.0) {
			conceito = 'D'; }	
	
	printf("NOTA = %.1lf CONCEITO = %c\n", x, conceito);
	
	return 0;
}
