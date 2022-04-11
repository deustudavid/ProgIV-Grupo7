#include "bbdd.h"
#include "sqlite3.h"
#include <stdio.h>
#include <string.h>

void crearTablas(sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "create table IF NOT EXISTS puntuacion(usuario varchar2(100) PRIMARY KEY NOT NULL, palabra varchar2(20),intentos int)";
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt); //Ejecuta la sentencia
	sqlite3_finalize(stmt);
	

}

void insertarUsuario(sqlite3 *db ,char *nombre, char *contrasenia){
	sqlite3_stmt *stmt;

	char sql[100];

	sprintf(sql, "insert into usuario values(%s, %s)",nombre,contrasenia);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void borrarUsuario(sqlite3 *db, char *nombre){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from usuario where nombre = %s",nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void mostrarUsuarios(sqlite3 *db){
	int resul,nombre;
	sqlite3_stmt *stmt;
	char sql[100],*nom,*cad;
	char letra;

	sprintf(sql,"select * from usuario");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	do{
		resul = sqlite3_step(stmt);
		nombre = sqlite3_column_int(stmt, 0);
		strcpy(nom, (char*)sqlite3_column_text(stmt, 1));
		
		printf("%d %s\n",nombre,nom);
	}while(resul == SQLITE_ROW);


	sqlite3_finalize(stmt);

}















