#include <stdio.h>
#include <math.h>

int main () {
	
	int n, i, r;
	
	scanf("%i", &n);
	
	i = 2;
	
	while (i <= n) {
		r = i*i;
		printf("%i^2 = %i\n", i, r);
		i += 2;
		}
	
	
	return 0;
}

