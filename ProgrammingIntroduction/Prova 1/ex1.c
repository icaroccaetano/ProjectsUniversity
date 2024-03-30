#include <stdio.h>

int main () {

	int v, w, x, y, z;
	
	scanf("%i %i %i %i %i", &v, &w, &x, &y, &z);
	
	int maior, menor;
	
	menor = v;	
	if (menor > w) {
		menor = w; }	
	if (menor > x) {
		menor = x; }	
	if (menor > y) {
		menor = y; }	
	if (menor > z) {
		menor = z; }
	
	maior = v;	
	if (maior < w) {
		maior = w; }	
	if (maior < x) {
		maior = x; }	
	if (maior < y) {
		maior = y; }	
	if (maior < z) {
		maior = z; }

	
	printf("MENOR: %i, MAIOR: %i\n", menor, maior);
	
		
	if (v < w && w < x && x < y && y < z) {
		printf("ORDENADO CRESCENTE\n"); }
	
		else if (v > w && w > x && x > y && y > z) {
			printf("ORDENADO DECRESCENTE\n"); }
	
		else {
			printf("DESORDENADO\n"); }
	
	return 0;
}
