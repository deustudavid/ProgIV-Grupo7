#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "wordC.h"
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include "bbdd.h"

#define MAX_NUM_PALABRAS 100
#define LINEA_MAX 2048
#define TAMANYO_NOMBREFICHERO 1024

#define USUARIO "c"
#define CLAVE "13"

void menuUsuario(sqlite3 * db){
	char nombre[51];
	int num = 0;
			printf("\n****BIENVENIDO, JUGADOR****\n \n");
			fflush( stdin);
			printf("1. JUGAR \n");
			fflush( stdin);
			printf("2.Ver puntuaciones \n");
			fflush(stdin);
			printf("3.Cerrar sesion \n");
			fflush(stdin);
			printf("4.Salir \nOpcion: ");
			fflush(stdin);
			fflush( stdout);
			scanf("%d", &num);
			fflush( stdout);
			fflush( stdin);
			switch(num){
						case 1:
							jugarWordle(db);
							break;
						case 2:
							printf("\nUSUARIO: ");
							fflush(stdout);
							fflush(stdin);
							gets(nombre);
							mostrarPuntuaciones(db, nombre);
							break;

						case 3:
							menuInicio();
							break;
						case 4:
							exit(0);
							break;
						default:
							printf("Opcion incorrecta \n");
							menuUsuario(db);
							break;
		}
}

int menuInicio(){

    int num = 0;
    printf("\n ****BIENVENIDO A WORDC**** \n \n");
    fflush( stdin);
    printf("1. INICIAR SESION \n");
    fflush( stdin);
    printf("2. REGISTRARSE \n");
    fflush( stdin);
    printf("3.Salir \n Opcion: ");
    fflush(stdin);
    fflush( stdout);
    scanf("%d", &num);
    fflush( stdout);
    fflush( stdin);

    return num;
}
void menuAdministrador(){

	int num = 0;
		printf("\n**** MENU ADMINISTRADOR ****\n \n");
		fflush( stdin);

		printf("1. ANIADIR PALABRA \n");
		fflush( stdin);
		printf("2.BORRAR PALABRA \n");
	    fflush( stdin);
		printf("3.Cerrar sesion \n");
		fflush(stdin);
		printf("4.Salir \nOpcion: ");

		fflush(stdin);
		fflush( stdout);
		scanf("%d", &num);
		fflush( stdout);
		fflush( stdin);
		switch(num){

			case 1:
				aniadirPalabraFichero();
				break;
			case 2:
				mostrarPalabradeUnaPosicion();
				break;
			case 3:
				menuInicio();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("Opcion incorrecta \n");
				menuAdministrador();
				break;
}

}

int numeroDePalabrasEnFichero(char * fichero){ //Cambiar a que devuelva un int (return del cont)

	int cont = 0;
	char ca;

	FILE *pf;

	pf = fopen(fichero, "r");
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
	return cont;
}






void jugarWordle(sqlite3 * db){
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
					jugarWordle(db);
					break;
				case 2:
					menuUsuario(db);
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
									jugarWordle(db);
									break;
							case 2:
									menuUsuario(db);
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

void aniadirPalabraFichero(){




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
						//fprintf(pf,"\n");

						printf("Palabra anadida correctamente\n");
						fflush(stdout);
						fclose(pf);
						menuAdministrador();

					}
					else{
						printf("Error al abrir el fichero");
						fflush(stdout);
						menuAdministrador();
					}

			} else {
				printf("Error. La palabra tiene que ser de 5 letras\n");
				fflush(stdout);
				aniadirPalabraFichero();
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

int logIn(sqlite3 *db,eAdministradores admins){


	char usuario[51];
	char clave[51];
	int resultado;
		printf("\n****INICIAR SESION****\n\n");
		printf("USUARIO: \n");
		fflush(stdout);
		fflush(stdin);
		gets(usuario);
		printf("CONTRASENA: \n");
		fflush(stdout);
		fflush(stdin);
		gets(clave);

		resultado = comprobarUsuarios(db, usuario, clave);

		if(resultado==1){
			printf("\nContrasenia incorrecta!\n ");
			fflush(stdout);

		}
		else if(resultado == 2){
			printf("\nUsuario correcto\n ");
			fflush(stdout);
			menuUsuario(db);
		}
		else if(resultado ==3){//vamos a mirar en el txt a ver si es administrador
			if (esAdministrador(usuario, clave) ==1) {
				printf("\nEntrando como administrador...\n ");
				fflush(stdout);
				resultado=4;
				menuAdministrador();
			}else{
				resultado=3;
				printf("\nEse usuario no existe...\n ");
				fflush(stdout);

			}
		}
		return resultado;
		/*Devuelve un 0 si el usuario no existe, un 1 si existe pero la contraseña no es correcta,
		 * un 2 para nombre y con correctos y un 4 si es admin*/
}
int esAdministrador(char * usuario, char * contra){
	int i, result=0;
	eAdministradores admins;
	admins.numeroAdministadores = numeroDePalabrasEnFichero("administradores.txt");

	admins.listaAdministradores = (sUsuario*)malloc(admins.numeroAdministadores*sizeof(sUsuario));

			FILE* pf = fopen("administradores.txt", "r");

			if(pf != (FILE*)NULL){
				for(i=0;i<admins.numeroAdministadores;i++){
					fscanf(pf,"%s%s",admins.listaAdministradores[i].usuario,admins.listaAdministradores[i].contrasena);
				}
			}
			for(i=0;i<admins.numeroAdministadores;i++){
				if ( (strcmp(admins.listaAdministradores[i].usuario, usuario) == 0) && (strcmp(admins.listaAdministradores[i].contrasena, contra) == 0)) {
					result=1;
					break;
				}
			}
				fclose(pf);


	return result;
}

void menuRegistro(sqlite3 *db){
	char usuario[51];
	char clave[51];
	int resultado = 0;
	printf("\n****REGISTRAR NUEVO USUARIO****\n\n ");
	fflush(stdout);
	printf("USUARIO:\n ");
	fflush(stdout);
	fflush(stdin);
	gets(usuario);
	printf("CONTRASENIA:\n ");
	fflush(stdout);
	fflush(stdin);
	gets(clave);
	resultado = comprobarUsuarios(db, usuario, clave);
	if(resultado < 3){
		printf("Ya existe un usuario con ese nombre\n");
		fflush(stdout);
		menuRegistro(db);
	}
	insertarUsuario(db ,usuario, clave);

}
void mostrarPalabradeUnaPosicion(){
	FILE *pf;
	int linea_a_leer = 0;
	char buffer[LINEA_MAX];
	 bool seguir_leyendo = true;
	 int linea_actual = 1;

	printf("Nº de linea cuya palabra quieres saber: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &linea_a_leer);
		pf = fopen("palabras.txt", "r");
		if(pf != (FILE *)NULL){
			do
			  {
			    fgets(buffer, LINEA_MAX, pf);

			    if (feof(pf))
			    {

			      seguir_leyendo = false;
			      printf("El fichero tiene %d lineas.\n", linea_actual-1);
			      fflush(stdout);
			      printf("No se pudo encontrar la linea %d.\n", linea_a_leer);
			      fflush(stdout);
			    }
			    else if (linea_actual == linea_a_leer)
			    {
			      seguir_leyendo = false;
			      printf("La linea contiene la palabra:\n%s", buffer);
			      fflush(stdout);
			    }

			    linea_actual++;

			  } while (seguir_leyendo);
			fclose(pf);
		}else{
			printf("Error al abrir el fichero");
			fflush(stdout);
		}
		eliminarPalabraDeUnaPosicion();
}
void eliminarPalabraDeUnaPosicion(){


    FILE *pf, *temporal;

      char nombre_ficheroTemporal[TAMANYO_NOMBREFICHERO];

      char buffer[LINEA_MAX];
      int linea_a_borrar = 0;

      printf("Introduce la linea cuya palabra quieras eliminar del fichero: ");
      fflush(stdout);
      fflush(stdin);
      scanf("%d", &linea_a_borrar);

      strcpy(nombre_ficheroTemporal, "temp");
      strcat(nombre_ficheroTemporal, "palabras.txt");



      pf = fopen("palabras.txt", "r");
      temporal = fopen(nombre_ficheroTemporal, "w");


      if (pf == NULL || temporal == NULL)
      {
        printf("Error abriendo el fichero\n");

      }


      bool seguir_leyendo = true;
      int linea_actual = 1;
      do
      {

        fgets(buffer, LINEA_MAX, pf);


        if (feof(pf)) seguir_leyendo = false;
        else if (linea_actual != linea_a_borrar)
          fputs(buffer, temporal);


        linea_actual++;

      } while (seguir_leyendo);

      fclose(pf);
      fclose(temporal);


      remove("palabras.txt");
      rename(nombre_ficheroTemporal, "palabras.txt");
      printf("Palabra eliminada\n");
      fflush(stdout);
      menuAdministrador();
}


