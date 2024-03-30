#include <stdio.h>
#define PMP 0.7
#define PML 0.15
#define PNT 0.15

int main () {

	int mat, i, n;
	double np, nl, nt, pres;
	double mp, ml, nf;

	while (1) {
	scanf("%i", &mat);

	n = mat/1000000;

	if (n>0) {
		mp = 0;
		ml = 0;

		for (i=0; i<8; i++) {
			scanf("%lf", &np);
			mp += np;
		}
		mp /= 8;

		for (i=0; i<5; i++) {
			scanf("%lf", &nl);
			ml += nl;
		}
		ml /= 5;

		scanf("%lf", &nt);

		scanf("%lf", &pres);

		printf("Matricula: %i, ", mat);
			
		
		nf = PMP*mp + PML*ml + PNT*nt;
		
		printf("Nota Final: %.2lf, ", nf);
			
		if (pres/128<0.75 && nf>=6) {
				printf("Situacao Final: REPROVADO POR FREQUENCIA\n");
			}
		if (pres/128<0.75 && nf < 6) {
				printf("Situacao Final: REPROVADO POR NOTA E POR FREQUENCIA\n");
			}
		if (pres/128>=0.75 && nf < 6) {
				printf("Situacao Final: REPROVADO POR NOTA\n");
			}
		if (pres/128>=0.75 && nf >= 6) {
				printf("Situacao Final: APROVADO\n");
			}
	}
	else { return 0; }
	}

	
	return 0;
}

