
#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"
#include "wordC.h"
//#include "sqlite3.c"

void crearTablas(sqlite3 *db);
void insertarUsuario(sqlite3 *db, char *nombre, char *contrasenia);
void insertarPuntuacion(sqlite3 *db ,char *nombre,char * palabra, int intentos);
void borrarUsuario(sqlite3 *db, char *nombre);
void mostrarUsuarios(sqlite3 *db);
int comprobarUsuarios(sqlite3 *db, char*nombre, char *contra);
void mostrarPuntuaciones(sqlite3 * db,  char * nombre);
#endif /* BBDD_H_ */
