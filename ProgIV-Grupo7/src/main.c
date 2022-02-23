#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	char palabra1[6], palabra2[6], palabra3[6], palabra4[6];

	FILE *f;

	f = fopen("palabras.txt", "r");


	fscanf(f,"%s %s %s %s ", palabra1, palabra2, palabra3, palabra4);
	system("color 4");
	printf("Con el fscanf:\n palabra1: %s\n Palabra2: %s\n Palabra3 %s \n Palabra4: %s \nhasta aqui" , palabra1,palabra2,palabra3,palabra4);

	fclose(f);

	return 0;
}
