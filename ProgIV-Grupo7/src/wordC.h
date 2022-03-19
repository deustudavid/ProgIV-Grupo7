	/*
 * wordC.h
 *
 *  Created on: 23 feb 2022
 *      Author: susil
 */

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

sLocalizadorChar comprobarCharConString(char c,char *string);
void comprobarStringConString(char *stringUsuario, char *stringPalabra);
void pruebaLecturaFicheros();
void menuInicial();
void adivinarPalabra();
void obtenerPalabra(char *palabra);
void numeroDePalabrasEnFichero();





#endif /* WORDC_H_ */
