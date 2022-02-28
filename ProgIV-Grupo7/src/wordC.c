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
			printf("Con el fscanf:\n palabra1: %s\n Palabra2: %s\n Palabra3: %s \n Palabra4: %s \nhasta aqui \n" , palabra1,palabra2,palabra3,palabra4);
			fclose(f);
		}else{
			printf("El fichero no se ha abierto\n");
		}

}
void menuInicial(){

	int num = 0;


		printf("** BIENVENIDO A WORDC **\n \n");
		fflush( stdin);
		printf("1. JUGAR \n");
		fflush( stdin);
		printf("2. Aniadir palabra \n");
		fflush( stdin);
		printf("3. Comprobar puntos \n");
		fflush( stdin);
		printf("4. Salir \n");
		fflush( stdin);
		printf("Opcion: ");
		fflush( stdin);
		fflush( stdout);
		scanf("%d", &num);
		fflush( stdout);
		fflush( stdin);
		switch(num){
					case 1:
						printf("HEee");
						adivinarPalabra();
						printf("HEee");
						fflush( stdout);
						fflush( stdin);
						break;
					case 2:
						printf("Dos seleccionado");
						break;
					case 3:
						break;
					default:
						printf("Opción incorrecta \n");
						menuInicial();
						break;
		}


}
void adivinarPalabra(){
	printf("Aqui estoy");
	char palabraAdivinar[6];
	obtenerPalabra(&palabraAdivinar);
	printf("%s",palabraAdivinar);
	fflush( stdin);
	fflush( stdout);
	printf("AAAA");
	fflush( stdin);
	fflush( stdout);
}
void obtenerPalabra(char *palabra[6]){
	strcpy(*palabra,"LIBRO");
}
