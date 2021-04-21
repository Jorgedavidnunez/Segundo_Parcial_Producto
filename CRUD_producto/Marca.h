#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
class Marca
{
private:
	string marca;
public:
	Marca() {
	}
	Marca(string mar) {
		marca = mar;
	}
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string insert = "insert into marcas(marca) values('" + marca + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "Ingreso exitoso\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "-----------------------------MARCAS-----------------------------\n";
				cout << "ID , MARCA"<< endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << endl;
				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}

	void modificar(int idmarca) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string im = to_string(idmarca);
			string modificar = "update marcas set marca = '" + marca + "' where idmarca = " + im + "";
			const char* m = modificar.c_str();
			q_estado = mysql_query(cn.getconectar(), m);
			if (!q_estado) {
				cout << "Modificacion exitosa\n";
			}
			else {
				cout << "Error al modificar\n";
			}
		}
		else {
		cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}

	void eliminar(int idmarca) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string im = to_string(idmarca);
			string eliminar = "delete from marcas where idmarca =" + im + "";
			const char* d = eliminar.c_str();
			q_estado = mysql_query(cn.getconectar(), d);
			if (!q_estado) {
				cout << "Eliminacion exitosa\n";
			}
			else {
				cout << "Error al eliminar\n";
			}
		}
		else {
			cout << "Error en la conexion\n";
		}
		cn.cerrar_conexion();
	}
};