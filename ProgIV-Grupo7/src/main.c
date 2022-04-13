#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "wordC.h"
#include "bbdd.h"
#include "sqlite3.h"

//#include "wordC.c" // es para cuando ejecutemos en Visual Studio Code, que ahi funciona bien el color de las letras

int main(int argc, char **argv) {
	sqlite3 *db;
	int resultadoInicio, resultadoLogin;
	eAdministradores admins;
	int result=sqlite3_open("bd.db",&db);
	if (result != SQLITE_OK)
	{
		printf("Error al abrir la base de datos\n");
		fflush(stdin);
	}
	//mostrarUsuarios(db);
	do{
		resultadoInicio = 4;
		resultadoInicio = menuInicio();
			switch(resultadoInicio){
				case 1: logIn(db, admins);break;
				case 2: menuRegistro(db); break;
				case 3: exit(0); break;
				default: printf("No es una opcion valida\n"); fflush(stdout); resultadoInicio = 4;
			}

		}while(resultadoInicio == 4);

	do{
	resultadoLogin = logIn(db,admins);


	}while(resultadoLogin != 2 || resultadoLogin !=4);



	return 0;

}



