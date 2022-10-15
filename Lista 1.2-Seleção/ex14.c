#include <stdio.h>

int main () {
	int input;
	int d, m, a;
	
	scanf("%d", &input);

	d = input/1000000;
	m = input%1000000/10000;
	a = input%10000;
	
	
	if (d<1 || d>31) {
		printf("Data invalida!\n");
		return 0; }
	
		
	if (m==1) {
		if (d<1 || d>31) {
			printf("Data invalida!\n"); 
			return 0; }
		printf("%d de janeiro de %d\n", d, a); }
		
	else if (m==2) {
		if (d<1 || d>28) {
			printf("Data invalida!\n");
			return 0; }
		printf("%d de fevereiro de %d\n", d, a); }
	else if (m==3) {
		if (d<1 || d>31) {
			printf("Data invalida!\n"); 
			return 0; }
		printf("%d de março de %d\n", d, a); }
	else if (m==4) {
		if (d<1 || d>30) {
			printf("Data invalida!\n");
			return 0; }
		printf("%d de abril de %d\n", d, a); }
	else if (m==5) {
		if (d<1 || d>31) {
			printf("Data invalida!\n");
			return 0; }
		printf("%d de maio de %d\n", d, a); }
	else if (m==6) {
		if (d<1 || d>30) {
			printf("Data invalida!\n");
			return 0; }
		printf("%d de junho de %d\n", d, a); }
	else if (m==7) {
		if (d<1 || d>31) {
			printf("Data invalida!\n");
			return 0; }
		printf("%d de julho de %d\n", d, a); }
	else if (m==8) {
		if (d<1 || d>31) {
			printf("Data invalida!\n");
			return 0; }
		printf("%d de agosto de %d\n", d, a); }
	else if (m==9) {
		if (d<1 || d>30) {
			printf("Data invalida!\n");
			return 0; }
		printf("%d de setembro de %d\n", d, a); }
	else if (m==10) {
		if (d<1 || d>31) {
			printf("Data invalida!\n");
			return 0; }
		printf("%d de outubro de %d\n", d, a); }
	else if (m==11) {
		if (d<1 || d>30) {
			printf("Data invalida!\n");
			return 0; }
		printf("%d de novembro de %d\n", d, a); }
	else if (m==12) {
		if (d<1 || d>31) {
			printf("Data invalida!\n");
			return 0; }
		printf("%d de dezembro de %d\n", d, a); }
	else {
		printf("Data invalida!\n"); }
		

	return 0;
}
		
