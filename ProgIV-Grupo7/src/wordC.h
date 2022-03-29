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

typedef struct
{
	char caracter;
	int posicion[4];
	int nPosicion;
}sLocalizadorChar;

typedef struct{
	char** listaPalabras;
	int contadorPalabras;

}tListaPalabras;

//Mirar esta posibilidad
typedef struct {
	char palabra[6];
	char tema[10];
}tPalabra;
sLocalizadorChar comprobarCharConString(char c,char *string);
void comprobarStringConString(char *stringUsuario, char *stringPalabra);
void pruebaLecturaFicheros();
void menuInicial();
void adivinarPalabra();
void obtenerPalabra(char *palabra);
void numeroDePalabrasEnFichero();
void jugarWordle();
bool procesarPalabra(const char* laRespuesta, const char* elIntento);
void aniadirPalabraFichero();
int logIn();



#endif /* WORDC_H_ */
