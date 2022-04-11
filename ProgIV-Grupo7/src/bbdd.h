
#ifndef BBDD_H_
#define BBDD_H_
#include "sqlite3.h"
//#include "sqlite3.c"

void crearTablas(sqlite3 *db);
void insertarUsuario(sqlite3 *db, char *nombre, char *contrasenia);
void borrarUsuario(sqlite3 *db, char *nombre);
void mostrarUsuarios(sqlite3 *db);
#endif /* BBDD_H_ */
