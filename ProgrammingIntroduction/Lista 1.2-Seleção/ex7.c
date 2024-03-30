#include <stdio.h>

int main () {

	double sal;
	
	scanf("%lf", &sal);
	
	if (sal <= 300.00) {
		sal = sal + (sal*0.50); }
	
	else {
		sal = sal + (sal*0.30); }

	printf("SALARIO COM REAJUSTE = %.2lf\n", sal);

	return 0;
	
	
}
