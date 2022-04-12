#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "wordC.h"
#include "bbdd.h"
#include "sqlite3.h"

//#include "wordC.c" // es para cuando ejecutemos en Visual Studio Code, que ahi funciona bien el color de las letras

int main(int argc, char **argv) {
	sqlite3 *db;
	int resultado;
	eAdministradores admins;
	int result=sqlite3_open("bd.db",&db);
	if (result != SQLITE_OK)
	{
		printf("Error al abrir la base de datos\n");
		fflush(stdin);
	}
	//mostrarUsuarios(db);
	do{
		resultado = 4;
		resultado = menuInicio();
			switch(resultado){
				case 1: break;
				case 2: menuRegistro(db); break;
				case 3: exit(0); break;
				default: printf("No es una opcion valida\n"); fflush(stdout); resultado = 4;
			}

		}while(resultado == 4);
	do{
	resultado = logIn(db,admins);
		switch(resultado){
			case 0: printf("ERROR! Usuario desconocido\n"); fflush(stdout); break;
			case 1: printf("ERROR! Contraseña incorrecta\n"); fflush(stdout); break;
			case 2: menuUsuario(); break;
			case 3: menuAdministrador(); break;
		}

	}while(resultado < 2);



	return 0;

}



