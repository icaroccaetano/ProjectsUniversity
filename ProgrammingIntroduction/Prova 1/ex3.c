#include <stdio.h>

int main () {

	int seq, uf, dv;
	
	scanf("%i %i", &seq, &uf);
	
	int s1, s2, s3, s4, s5, s6, s7, s8;
	
	
	s1 = (int) seq/10000000;
	s2 = (int) (seq%10000000)/1000000;
	s3 = (int) ((seq%10000000)%1000000)/100000;
	s4 = (int) (((seq%10000000)%1000000)%100000)/10000;
	s5 = (int) ((((seq%10000000)%1000000)%100000)%10000)/1000;
	s6 = (int) (((((seq%10000000)%1000000)%100000)%10000)%100)/100;
	s7 = (int) ((((((seq%10000000)%1000000)%100000)%10000)%1000)%100)/10;
	s7 = (int) (((((((seq%10000000)%1000000)%100000)%10000)%1000)%100)%10);
	
	int BC1d = (s1*2)+(s2*3)+(s3*4)+(s4*5)+(s5*6)+(s6*7)+(s7*8)+(s8*9);
	
	
	int d1 = BC1d%11;
	
	if (d1 < 10) {
		d1 == '0'; }
		
	int uf1, uf2;
	uf1 = uf/10;
	uf2 = uf%10;
	
	
	int BC2d = uf1*7 + uf2*8 * d1*9;

	int d2 = BC1d%11;	
	
	if (d2 < 10) {
		d2 = '0'; }
		
	printf("%i0%i/%i%i\n", seq, uf, d1, d2);
	return 0;

}
