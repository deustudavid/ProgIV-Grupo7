	/*
 * wordC.h
 *
 *  Created on: 23 feb 2022
 *      Author: susil
 */
#include <stdbool.h>
#include "sqlite3.h"

#ifndef WORDC_H_
#define WORDC_H_




typedef struct
{
	char jugador[20], palabra[6]; //Hay que meter si eso el tipo de la palabra
	int intentos;
}sPuntuacion;


typedef struct{
	char** listaPalabras;
	int contadorPalabras;

}tListaPalabras;

//Mirar esta posibilidad
typedef struct {
	char palabra[6];
	char tema[10];
}tPalabra;

typedef struct{
	char  usuario[100];
	char  contrasena[20];
}sUsuario;

typedef struct {
	sUsuario * listaAdministradores;
	int numeroAdministadores;
}eAdministradores;

int menuInicio();
void menuUsuario(sqlite3 * db);
void menuAdministrador();
//int menuAdministrador();
void menuRegistro(sqlite3 *db);
int numeroDePalabrasEnFichero(char * fichero);
void jugarWordle(sqlite3 * db);
bool procesarPalabra(const char* laRespuesta, const char* elIntento);
void aniadirPalabraFichero();
int logIn();
int esAdministrador(char * usuario, char * contra);
void mostrarPalabradeUnaPosicion();
void eliminarPalabraDeUnaPosicion();


#endif /* WORDC_H_ */
