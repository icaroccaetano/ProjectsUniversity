#include <stdio.h>

int main () {

	int tot, cem, cin, dez, um;
	
	scanf("%d", &tot);
	
	cem = tot/100;
	cin = (tot%100)/50;
	dez = (tot-(cem*100)-(50*cin))/10;
	um = (tot-(cem*100)-(50*cin))%10;
	
	printf("NOTAS DE 100 = %d\n", cem);
	printf("NOTAS DE 50 = %d\n", cin);
	printf("NOTAS DE 10 = %d\n", dez);
	printf("MOEDAS DE 1 = %d\n", um);
	

	return 0;
}
