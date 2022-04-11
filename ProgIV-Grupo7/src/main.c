#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "wordC.h"
#include "bbdd.h"
#include "sqlite3.h"

//#include "wordC.c" // es para cuando ejecutemos en Visual Studio Code, que ahi funciona bien el color de las letras

int main(int argc, char **argv) {
	sqlite3 *db;
	int result=sqlite3_open("bd.db",&db);
	if (result != SQLITE_OK)
	{
		printf("Error al abrir la base de datos\n");
		fflush(stdin);
	}
	//mostrarUsuarios(db);

	if(logIn()){
		menuUsuario();
	}

	return 0;

}

