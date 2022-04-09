#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "wordC.h"
//#include "wordC.c" // es para cuando ejecutemos en Visual Studio Code, que ahi funciona bien el color de las letras

int main(int argc, char **argv) {

	if(logIn()){
		menuInicial();
	}

	return 0;

}

