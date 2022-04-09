	/*
 * wordC.h
 *
 *  Created on: 23 feb 2022
 *      Author: susil
 */
#include <stdbool.h>

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
	char * usuario;
	char * contrasena;
}sUsuario;

typedef struct {
	sUsuario * listaAdministradores;
	int numeroAdministadores;
}eAdministradores;


void menuInicial();
void numeroDePalabrasEnFichero(char * fichero);
void jugarWordle();
bool procesarPalabra(const char* laRespuesta, const char* elIntento);
void aniadirPalabraFichero();
int logIn();
void esAdministrador(char * usuario, char * contra,eAdministradores admins);



#endif /* WORDC_H_ */
