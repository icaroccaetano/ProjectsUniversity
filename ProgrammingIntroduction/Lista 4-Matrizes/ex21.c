#include <stdio.h>
#include <stdlib.h>

#define N 6
int DIST[N][N] = { {   0 ,  63 , 210 , 190 ,  -1 , 190},
                     {  63 ,   0 , 160 , 150 ,  95 ,  10},
                     { 210 , 160 ,   0 ,  10 ,   1 ,  10},
                     { 190 , 150 ,  10 ,   0 ,  10 ,  20},
                     {  10 ,  95 ,   7 ,  21 ,   0 ,  80},
                     { 190 ,   2 ,  -1 ,  41 ,  80 ,   0}
					};

#define VSIZE 100

int main() {
	int * trj = NULL;
	int tt;
	int i;
	int ip, id;
	int custo = 0;

	scanf("%d", &tt);
	trj = calloc(tt, sizeof(int));

	// leitura do vetor de indices (trajeto)
	for(i=0;i<tt;i++) scanf("%d", trj+i);

	ip = trj[0];
	for(i=1;i<tt;i++) {
		id = trj[i];
		if( DIST[ip][id] == -1 ) {
			printf("rota invalida!\n");
			break;
			//goto finalizar;
		}
		custo += DIST[ip][id];
		ip = id;
	}

	if( DIST[ip][id] != -1 ) printf("%d\n", custo);

// finalizar:
	free(trj);
	return 0;
}