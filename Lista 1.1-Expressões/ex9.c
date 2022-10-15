#include <stdio.h>

int main () {

	float number;
	
	scanf("%f", &number);
	
	printf("%.1f00000\n", number);
	printf("%.2f0000\n", number);
	printf("%.3f000\n", number);

	return 0;
}

