#include<stdlib.h>
#include<stdio.h>
#include<graph.h>

void jeux() {
	FILE* flux;
	int enable_IA;

	printf("%d\n", enable_IA);

	flux = fopen("options", "r");
	fread(&enable_IA, sizeof(int), 1, flux);

	printf("%d\n", enable_IA);
	
	fclose(flux);
}