#include <stdio.h>
#define Popular	1.00
#define Geral		5.00
#define Arquibancada	10.00
#define Cadeira	20.00

int main () {
	
	int caso, num, lot;
	double p, g, a, c, renda;
	
	scanf("%i", &caso);
	num =0;
	while  (caso>0) {
		scanf("%i %lf %lf %lf %lf", &lot, &p, &g, &a, &c);
		num ++;
		renda = ((p/100.00)*lot)*Popular+((g/100.00*lot))*Geral+((a/100.00)*lot)*Arquibancada+((c/100.00)*lot)*Cadeira;
		printf("A RENDA DO JOGO N. %d E = %.2lf\n", num, renda);
		caso --; }
	
	
	
	return 0;
}




