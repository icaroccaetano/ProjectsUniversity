#include <stdio.h>

int main () {

	int num;
	
	scanf("%d", &num);
	
		if (num > 255 && num < 0) {
			printf("Numero invalido!\n");
}
		else {
			int a, b, c, d, e, f, g, h;
		
				a = num % 2;
				b = (num/2) % 2;
				c = ((num/2)/2) % 2;
				d = ((((num/2)/2)/2)) % 2;
				e = (((((num/2)/2)/2)/2)) % 2;
				f = ((((((num/2)/2)/2)/2)/2)) % 2;
				g = (((((((num/2)/2)/2)/2)/2)/2)) % 2;
				h = ((((((((num/2)/2)/2)/2)/2)/2)/2)) % 2;
	
					printf("%d%d%d%d%d%d%d%d\n", h, g, f, e, d, c, b, a);
		
}	 

	return 0;
}
