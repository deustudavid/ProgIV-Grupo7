#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "wordC.h"
#include <string.h>

sLocalizadorChar comprobarCharConString( char c, char *stringUsu){
	int i = 0;
	int longitud;
	sLocalizadorChar a;
	a.nPosicion = 0;
	longitud = strlen(stringUsu);
	a.caracter = c;
	for (i = 0; i < longitud; ++i) {
		if (stringUsu[i] == c) {
			a.posicion[a.nPosicion] = i;
			a.nPosicion ++;
		}
	}return a;
}

void comprobarStringConString(char *stringUsuario, char *stringPalabra){
	int i = 0;
	for(i=0;i <= sizeof stringUsuario;i++){
		sLocalizadorChar c;					//Preguntar a Marian
		c.caracter = stringUsuario[i];
		printf("%c \n",stringUsuario[i]);
		c = comprobarCharConString(c.caracter, stringPalabra);


		 /*printf("%c , ",c.caracter);
		int i;

			for(i=0;i<c.nPosicion;i++){
				printf("%d ",c.posicion[i]);
			}*/
	}
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

void numeroDePalabrasEnFichero(){ //Cambiar a que devuelva un int (return del cont)

	int cont = 0;
	char ca;

	FILE *pf;

	pf = fopen("palabras.txt", "r");
	if(pf != (FILE *)NULL){
		while(1){
			ca = fgetc(pf);

			if(ca == '\n'){
				cont++;
			}
			if(ca == EOF){ //Si el cararcter es EOF End Of Line hemos llegado al final del fichero
				printf("%d\n", cont); // Numero de filas del fichero
				break;
			}
		}
		fclose(pf);
	}else{
		printf("Error al abrir el fichero");
	}
}

void adivinarPalabra(){
	char palabraAdivinar[6];
	obtenerPalabra(palabraAdivinar);
	printf("%s",palabraAdivinar);
	fflush( stdin);
	fflush( stdout);
}

void obtenerPalabra(char *palabra){
	strcpy(palabra,"LIBRO");
}
void menuInicial(){

	int num = 0;


		printf("** BIENVENIDO A WORDC **\n \n");
		fflush( stdin);
		printf("1. JUGAR \n");
		fflush( stdin);
		printf("2. ANIADIR PALABRA \n");
		fflush( stdin);
		printf("3. COMPROBAR PUNTOS \n");
		fflush( stdin);
		printf("4.Probar la lectura de los ficheros\n5. Prueba comparar 2 strings\n");
		fflush( stdin);
		printf("6.Prueba comparar un char en un string \nOpcion: ");
		fflush( stdin);
		fflush( stdout);
		scanf("%d", &num);
		fflush( stdout);
		fflush( stdin);
		sLocalizadorChar a;
		switch(num){
					case 1:
						printf("Todavia no funciona\n");
						fflush(stdout);
						fflush(stdout);
						adivinarPalabra();
						break;
					case 2:
						printf("Dos seleccionado");
						fflush(stdout);
						break;
					case 3:
						printf("Work in progres...");
						fflush(stdout);
						break;
					case 4:
						//pruebaLecturaFicheros();
						numeroDePalabrasEnFichero();
						break;
					case 5:
						comprobarStringConString("libro","arbol");
						break;
					case 6:
						printf("Char: a String: cacac \n");
						fflush(stdout);
						a = comprobarCharConString('j', "alejo");
						printf("%c\n",a.caracter);
						fflush(stdout);
						int i;
						for(i=0;i<a.nPosicion;i++){
							printf("%d ",a.posicion[i]);
							fflush(stdout);
							}
						break;
					default:
						printf("Opción incorrecta \n");
						menuInicial();
						break;
		}



}
