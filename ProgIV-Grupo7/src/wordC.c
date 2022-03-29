#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "wordC.h"
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

#define MAX_NUM_PALABRAS 100

#define USUARIO "c"
#define CLAVE "13"


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


		printf("\n** BIENVENIDO A WORDC **\n \n");
		fflush( stdin);
		printf("1. JUGAR \n");
		fflush( stdin);
		printf("2. ANIADIR PALABRA \n");
		fflush( stdin);
		printf("3. COMPROBAR PUNTOS \n");
		fflush( stdin);
		printf("4.Probar la lectura de los ficheros \n");
		fflush( stdin);
		printf("5. Prueba comparar 2 strings: \n");
		fflush(stdin);
		printf("6.Prueba comparar un char en un string \n");
		fflush( stdin);
		printf("7.Cerrar sesion \n");
		fflush(stdin);
		printf("8.Salir \nOpcion: ");
		fflush(stdin);
		fflush( stdout);
		scanf("%d", &num);
		fflush( stdout);
		fflush( stdin);
		sLocalizadorChar a;
		switch(num){
					case 1:
						jugarWordle();
						break;
					case 2:
						aniadirPalabraFichero();
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
					case 7:
						logIn();
						break;
					case 8:
						system("cls");
						break;
					default:
						printf("Opcion incorrecta \n");
						menuInicial();
						break;
		}



}
bool procesarPalabra(const char* laRespuesta, const char* elIntento){

	// pista
	//char pista[6]={'-', '-', '-', '-', '-', '\0'};
	char pista[]="-----";
	//indicar si la letra en la respuesta se encuentra en la pista
	bool flagsRespuesta[5]={false,false,false,false,false};

	if(strlen(elIntento)==5){ //NOTA: Equivocarse y no poner una palabra de 5 letras implica perder un intento

		// B=Bien= la letra esta justo en esa posicion de la palabra
		for (int i = 0;  i< 5; i++) {
			if (elIntento[i] == laRespuesta[i]) {
				pista[i] = 'B';
				flagsRespuesta[i]=true;
			}

		}

		// S=Si= la letra en esa posicion esta en algun sitio de la palabra
		for (int i = 0;  i< 5; i++) {
				if (pista[i] == '-') {
					for (int j = 0;  j< 5; j++) {
							if (elIntento[i] == laRespuesta[j] && !flagsRespuesta[j]) {
								//Hay coincidencia en otra posicion y no se ha usado como pista

								pista[i] = 'S';

								flagsRespuesta[j]=true;

								break;//terminar loop porque no queremos m�ltiples pistas para la misma letra
							}
						}
				}
			}
	}else{
		printf("La palabra tiene que ser de 5 letras!\n");
		fflush(stdout);
	}


	for (int i = 0; i < strlen(pista); i++)

	{

		if (pista[i]=='B')
		{
			HANDLE consola=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consola,2);
			printf("%c", elIntento[i]);




		}else if (pista[i]=='S'){
			HANDLE consola=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consola,6);
			printf("%c", elIntento[i]);




		}else if (pista[i]=='-'){
			HANDLE consola=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(consola,7);
			printf("%c", elIntento[i]);




		}

	}



	return strcmp(pista, "BBBBB") ==0;//Si coincide con strcmp devuelve 0, significa que se ha acertado la palabra
}


void jugarWordle(){
	HANDLE consola=GetStdHandle(STD_OUTPUT_HANDLE);

	//CARGAR PALABRAS
		//char** listaPalabras= calloc(MAX_NUM_PALABRAS,sizeof(char*));
		//int contadorPalabras=0;
		char* palabra5letras=malloc(6*sizeof(char));
		FILE* ficheroPalabras= fopen("palabras.txt", "r");

		tListaPalabras lp ;
		lp.listaPalabras = calloc(MAX_NUM_PALABRAS,sizeof(char*));
		lp.contadorPalabras = 0;
		while(fscanf(ficheroPalabras, "%s", palabra5letras) != EOF && lp.contadorPalabras < MAX_NUM_PALABRAS){
			lp.listaPalabras[lp.contadorPalabras]= palabra5letras;
			lp.contadorPalabras++;
			palabra5letras=malloc(6*sizeof(char));

		}
		fclose(ficheroPalabras);

		//EMPEZAR JUEGO Y SELECCIONAR UNA PALABRA RANDOM
		srand(time(NULL));
		char* respuesta= lp.listaPalabras[rand()%lp.contadorPalabras];

		// LOOP PARA SEGUIR JUGANDO
		int numIntentos=6;
		bool seHaAcertado=false;
		char* intento= malloc(6*sizeof(char));
		while(numIntentos>0 && !seHaAcertado){
			//RECIBIR PALABRA INSERTADA POR EL USUARIO
			SetConsoleTextAttribute(consola,7);
			printf("\n%d intentos restantes\n", numIntentos);
			fflush(stdout);
			printf("Introduce palabra de 5 letras. Presiona ENTER para verificar.\n ");
			fflush(stdout);
			gets(intento);

			//CONVERTIR LA PALABRA EN MINUSCULA
			for(int i = 0; i<strlen(intento); i++){
				intento[i] = tolower(intento[i]);
			}

			numIntentos--;

			//VER SI SE ACIERTA O NO LA PALABRA
			seHaAcertado=procesarPalabra(respuesta, intento);


		}

		//MOSTRAR MENSAJE DE FIN DE JUEGO
		if (seHaAcertado) {
			int opcion;
			SetConsoleTextAttribute(consola,7);

			printf("\nFelicidades, has acertado la palabra en %d intentos\n", (6-numIntentos));
			fflush(stdout);

			printf("1= Seguir jugando\n2= Volver al menu\n");
			fflush(stdout);

			scanf("%d",&opcion);
			fflush(stdout);
			fflush(stdin);


			switch(opcion){
								case 1:
									jugarWordle();
									break;
								case 2:
									menuInicial();
									break;

								default:
									printf("Opcion incorrecta \n");
									break;
					}


		}else{
			int opcion;
			SetConsoleTextAttribute(consola,7);


			printf("\nHas agotado los intentos...La palabra correcta era %s\n", respuesta);
			fflush(stdout);

			printf("1= Seguir jugando\n2= Volver al menu\n");
			fflush(stdout);
			fflush(stdin);
			scanf("%d",&opcion);
			fflush(stdin);


			switch(opcion){
							case 1:
									jugarWordle();
									break;
							case 2:
									menuInicial();
									break;

							default:
									printf("Opcion incorrecta \n");
									break;
								}

		}

		for (int i = 0;  i< lp.contadorPalabras; i++) {
			free(lp.listaPalabras[i]);
		}
		free(lp.listaPalabras);
		free(palabra5letras);
		free(intento);



}
//Añadir una función para el menú que aparece después de jugar
void aniadirPalabraFichero(){

	int salir=0;
	do {
		char* palabraNueva=malloc(6*sizeof(char));


			printf("Introduce una palabra de 5 letras:\n");
			fflush(stdout);
			gets(palabraNueva);

			if (strlen(palabraNueva)==5) {
				FILE *pf;

					pf = fopen("palabras.txt", "a");
					if(pf != (FILE *)NULL){
						fprintf(pf,"\n");
						fputs(palabraNueva,pf);

						int opc;
						printf("1= Volver al menu\nOtra tecla= seguir\n");
						fflush(stdout);
						fflush(stdin);
						scanf("%d",&opc);
						fflush(stdin);

						switch(opc){
								case 1:
										menuInicial();
										break;
								default:
									break;
						}


					}

					else{
						printf("Error al abrir el fichero");
						fflush(stdout);
					}
					fclose(pf);
			} else {
				printf("Error. La palabra tiene que ser de 5 letras\n");
				fflush(stdout);
				aniadirPalabraFichero();


			}
	} while (salir==0);



}

int logIn(){

	char usuario[51];
		char clave[51];
		int intento= 0;
		//int ingresaAdministrador= 0;
		int ingresaUsuario=0;


			do {
				system("cls");
				printf("\nINICIAR SESI�N\n");
				printf("\nUSUARIO: ");
				fflush(stdout);

				fgets(usuario, 51, stdin);
				usuario[strcspn(usuario, "\r\n")] = 0; //Quitamos el salto de línea que fgets introduce en la cadena

				printf("CONTRASE�A: ");

				fflush(stdout);


				fgets(clave, 51, stdin);

				clave[strcspn(clave, "\r\n")] = 0;





				if(strcmp(usuario,USUARIO)==0 && strcmp(clave,CLAVE)==0){
		            ingresaUsuario=1;

		        }else {
					printf("\n\t Usuario y/o clave son incorrectos\n");
					fflush(stdout);
					intento++;
					getchar();

				}
			} while (intento<3 && ingresaUsuario==0);

			/*if(ingresaUsuario==1){

				menuInicial();

			}else{
				printf("\n Has sobrepasado el nucmero macximo de intentos\n");
				fflush(stdout);

			}*/
			if(!ingresaUsuario){
				printf("\n Has sobrepasado el nucmero macximo de intentos\n");
				fflush(stdout);

			}
			return ingresaUsuario;
}
