#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "wordC.h"
#include <string.h>

int comprobarCharConString( char c, char *stringUsu){
	int i = 0;
	int resul = 0;
	int longitud;
	longitud = strlen(stringUsu);

	for (i = 0; i < longitud; ++i) {
		if (stringUsu[i] == c) {
			resul = 1;
		}
	}


	return resul;
}

void pruebaLecturaFicheros(){
	char palabra1[6], palabra2[6], palabra3[6], palabra4[6];

		FILE *f;

		f = fopen("palabras.txt", "r");
		//f = fopen("C:\\Users\\susil\\git\\ProgIV-Grupo7\\ProgIV-Grupo\\palabras.txt","r");
		if(f!=(FILE*)NULL){
			fscanf(f,"%s %s %s %s ", palabra1, palabra2, palabra3, palabra4);
			system("color 4");
			printf("Con el fscanf:\n palabra1: %s\n Palabra2: %s\n Palabra3: %s \n Palabra4: %s \nhasta aqui" , palabra1,palabra2,palabra3,palabra4);
			fclose(f);
		}else{
			printf("El fichero no se ha abierto\n");
		}

}
void menuInicial(){
	int num = 0;


	printf(" BIENVENIDO A WORDC \n \n");
	printf("1. JUGAR \n");
	printf("2. Salir");
	scanf("%d", &num);
	switch(num){
	case 1:
		printf("Uno seleccionado");
		break;
	case 2:
		printf("Dos seleccionado");
		break;
	case 3:
		break;
	default:
		printf("Opción incorrecta");
		break;
	}


}
