#include <stdio.h>

int main () {

	double a, b, c, p, s, t;
	
	scanf ("%lf", &a);
	scanf ("%lf", &b);
	scanf ("%lf", &c);
	
	if (a>b && a>c) {
		t = a; 
		if (b>c) {
			s = b;
			p = c; }
		if (b<c) {
			s = c;
			p = b; }
			}
	
	if (b>a && b>c) {
		t = b; 
		if (a>c) {
			s = a;
			p = c; }
		if (a<c) {
			s = c;
			p = a; }
			}
	
	if (c>a && c>b) {
		t = c; 
		if (b>a) {
			s = b;
			p = a; }
		if (b<a) {
			s = a;
			p = b; }
			}
	if (a==b || a==c || c==b) {
		if (a==b) {
			if (c>b) {
				t = c;
				p = a; 
				s = b; }
			if (c<b) { 
				p = c;
				t = a;
				s = b; }
			}
		if (a==c) {
			if (b>a) {
				t = b;
				p = a; 
				s = c; }
			if (b<a) { 
				p = b;
				t = a;
				s = c; }
			}
		if (c==b) {
			if (c>a) {
				t = a;
				p = c; 
				s = b; }
			if (c<a) { 
				p = a;
				t = c;
				s = b; }
			}
				
}				

	if (a==b && b==c) {
		p = a;
		s = b;
		t = c; }
		
		

	printf("%.2lf, %.2lf, %.2lf\n", p, s, t);
	
	return 0;
}
