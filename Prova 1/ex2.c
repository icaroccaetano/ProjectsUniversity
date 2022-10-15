#include <stdio.h>

int main () {

	double a, b, c;
	double som, d, m, sub;
	char op;
	
	scanf("%lf%c%lf%*c%lf", &a, &op, &b, &c);
	
	som = a+b;
	
	if (op == '+') {
		if (c == som) {
			printf("CORRETO\n"); }
		else {
			printf("ERRADO! O resultado deveria ser: %lf\n", som); }
	}
	
	sub = a-b;
	
	if (op == '-') {
		if (c == sub) {
			printf("CORRETO\n"); }
		else {
			printf("ERRADO! O resultado deveria ser: %lf\n", sub); }
	}
	
	d = a/b;
	
	if (op == '/') {
		if (c == d) {
			printf("CORRETO\n"); }
		else {
			printf("ERRADO! O resultado deveria ser: %lf\n", d); }
	}
	
	m = a*b;
	
	if (op == '*') {
		if (c == m) {
			printf("CORRETO\n"); }
		else {
			printf("ERRADO! O resultado deveria ser: %lf\n", m); }
	}
	
	return 0;
}
