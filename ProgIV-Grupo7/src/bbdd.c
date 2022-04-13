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
	
	char sql2[] = "create table IF NOT EXISTS usuario(nom varchar2(100) PRIMARY KEY NOT NULL, con varchar2(20))";
	sqlite3_prepare_v2(db, sql2, -1, &stmt, NULL) ;
	sqlite3_step(stmt); //Ejecuta la sentencia
	sqlite3_finalize(stmt);

}

void insertarUsuario(sqlite3 *db ,char *nombre, char *contrasenia){
	sqlite3_stmt *stmt;

	char sql[100];

	sprintf(sql, "insert into usuario values('%s', '%s')",nombre,contrasenia);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void insertarPuntuacion(sqlite3 *db ,char *nombre,char * palabra, int intentos){
	sqlite3_stmt *stmt;

	char sql[100];//

	sprintf(sql, "insert into puntuacion values('%s', '%s', %d)",nombre,palabra, intentos);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void borrarUsuario(sqlite3 *db, char *nombre){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from usuario where nombre = '%s'",nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void mostrarUsuarios(sqlite3 *db){
	int resul;
	sqlite3_stmt *stmt;
	char sql[100],nom[101] ,con[21];

	sprintf(sql,"select * from usuario");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	do{
		resul = sqlite3_step(stmt);
		strcpy(nom,(char*)sqlite3_column_text(stmt, 0));
		strcpy(con, (char*)sqlite3_column_text(stmt, 1));
		printf("%s %s\n",nom,con); fflush(stdout);
	}while(resul == SQLITE_ROW);


	sqlite3_finalize(stmt);

}

int comprobarUsuarios(sqlite3 *db, char*nombre, char *contra){
	int resul;
	sqlite3_stmt *stmt;
	char sql[100],/*nom[101] ,*/con[21];
	int resultado = 0;
	sprintf(sql,"select * from usuario where nom='%s'",nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	resul = sqlite3_step(stmt);
	if(resul == SQLITE_ROW){
		strcpy(con, (char*)sqlite3_column_text(stmt, 1));
		if(strcmp(contra,con)==0){// usuario correcto en BD
			resultado = 2;
		}else{
			resultado = 1;    // usuario incorrecto en BD
		}
	}else{
		resultado= 3;  // No existe en la BD, tenemos que mirar en el txt a ver si es administrador

	}


	sqlite3_finalize(stmt);
	return resultado;
}
















