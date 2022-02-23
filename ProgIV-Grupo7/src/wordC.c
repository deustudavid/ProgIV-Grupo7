#include "wordc.h"
#include <string.h>

int comprobarCharConString(char c, char string)
{
	int i = 0;
	int resul = 0;
	int longitud = strlen(string);
	int resultadoComparacion;

	for (i = 0; i < longitud; ++i) {
		resultadoComparacion = strcmp(c,string+1);
		if (resultadoComparacion == 0){

		}

		}


	return resul;
}
