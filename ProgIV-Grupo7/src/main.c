#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "wordC.h"


int main(int argc, char **argv) {
	int resul = 0;

	resul = comprobarCharConString('c',"cc");
	printf("%d\n",resul);
	pruebaLecturaFicheros();

	menuInicial();


	return 0;

}

