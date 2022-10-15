#include <stdio.h>

int main () {

	int num;
	
	scanf("%i", &num);
	
	if (num<=0 || num>9999) {
		
		printf("Numero invalido!\n"); 
		return 0; }
		
	else if (num/1000>0) {
		int a, b, c, d;
		
		a = num/1000;
		b = num%1000/100;
		c = num%100/10;
		d = num%10/1;
		
		if (a!=0 && b!=0 && c!=0 && d!=0) {
			if (a!=1 && b!=1 && c!=1 && d!=1) {
				printf("(quarta ordem) %i = %i unidades de milhar + %i centenas + %i dezenas + %i unidades = %i000 + %i00 + %i0 + %i\n", num, a, b, c, d, a, b, c, d); }
			if (a==1 && b!=1 && c!=1 && d!=1) {
				printf("(quarta ordem) %i = %i unidade de milhar + %i centenas + %i dezenas + %i unidades = %i000 + %i00 + %i0 + %i\n", num, a, b, c, d, a, b, c, d); }
			else {
				printf("(quarta ordem) %i = %i unidades de milhar + %i centenas + %i dezenas + %i unidades = %i000 + %i00 + %i0 + %i\n", num, a, b, c, d, a, b, c, d); }
}
		if (b==0) {
			if (d!=0 && c!=0) {
				printf("(quarta ordem) %i = %i unidade de milhar + %i dezenas + %i unidades = %i000 + %i0 + %i\n", num, a, c, d, a, c, d); }
			if (d!=0 && c==0) {
				printf("(quarta ordem) %i = %i unidade de milhar + %i unidades = %i000 + %i\n", num, a, d, a, d); }
			if (d==0 && c==0) {
				printf("(quarta ordem) %i = %i unidade de milhar = %i000\n", num, a, a); }
			if (d==0 && c!=0) { 
			printf("(quarta ordem) %i = %i unidade de milhar + %i dezenas = %i000 + %i0\n", num, a, c, a, c); }
}
		
		if (c==0) {
			if (b!=0 && d!=0) {
				printf("(quarta ordem) %i = %i unidade de milhar + %i centenas + %i unidades = %i000 + %i00 + %i\n", num, a, b, d, a, b, d); }
			if (b!=0 && d==0) {
				printf("(quarta ordem) %i = %i unidade de milhar + %i centenas = %i000 + %i00\n", num, a, b, a, b); }
}

		if (d==0) {
			if (b!=0 && c!=0) {
			printf("(quarta ordem) %i = %i unidade de milhar + %i centenas + %i dezenas = %i000 + %i00 + %i0\n", num, a, b, c, a, b, c); }
}
	return 0;
}			
				
			
	else if (num/100>0) {
		int a, b, c;
		
		a = num/100;
		b = num%100/10;
		c = num%10/1;
		
		if (a!=0 && b!=0 && c!=0) {
			printf("(terceira ordem) %i = %i centenas + %i dezenas + %i unidades = %i00 + %i0 + %i\n", num, a, b, c, a, b, c); }
		if (b==0) {
			if (c==0) {
				printf("(terceira ordem) %i = %i centenas = %i00\n", num, a, a); }		
			if (c!=0) {
				printf("(terceira ordem) %i = %i centenas + %i unidades = %i00 + %i\n", num, a, c, a, c); }
			}
		if (c==0 && b!=0) {
			printf("(terceira ordem) %i = %i centenas + %i dezenas = %i00 + %i0\n", num, a, b, a, b); }
		
		return 0;
		}
		
	if (num/10>0) {
		int a, b;
		
		a = num/10;
		b = num%10/1;
		
		if (b==0) {
			printf("(segunda ordem) %i = %i dezena = %i0\n", num, a, a); }
		else {						
			printf("(segunda ordem) %i = %i dezena + %i unidades = %i0 + %i\n", num, a, b, a, b); }
		
		return 0;
		}	
			
	if (num < 10) {
		printf("(primeira ordem) %i = %i unidade = %i\n", num, num, num); }	


	return 0;
}
