#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "wordC.h"

int main(int argc, char **argv) {
	int resul = 0;

	//menuInicial();

	resul = comprobarCharConString('c',"cc");
	printf("%d",resul);
	pruebaLecturaFicheros();
	return 0;
}
