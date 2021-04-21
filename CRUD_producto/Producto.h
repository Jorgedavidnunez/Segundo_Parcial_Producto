#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"
class Producto
{
private: 
	string producto, descripcion, imagen, fecha_ingreso;
	int idmarca = 0, existencia = 0;
	double precio_costo = 0, precio_venta = 0;

public:
	Producto() {
	}
	Producto(string pro, int idm, string des, string img, double pcos, double pven, int exis, string fi) {
		producto = pro;
		idmarca = idm;
		descripcion = des;
		imagen = img;
		precio_costo = pcos;
		precio_venta = pven;
		existencia = exis;
		fecha_ingreso = fi;
	}
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string ia = to_string(idmarca);
			string pc = to_string(precio_costo);
			string pv = to_string(precio_venta);
			string e = to_string(existencia);
			string insert = "insert into productos(producto,idmarca,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingreso) values('" + producto + "'," + ia + ",'" + descripcion + "', '" + imagen + "', " + pc + ", " + pv + ", " + e + ", '" + fecha_ingreso + "')";
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
			string consulta = "select *  from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				cout << "-----------------------------PRODUCTOS-----------------------------\n";
				cout <<"ID , PRODUCTO , IDMARCA , DESCRIPCION , IMAGEN , PRECIO COSTO , PRECIO VENTA , EXISTENCIA , FECHA INGRESO"<< endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << " , " << fila[8] << endl;
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

	void modificar(int idproducto) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string ip = to_string(idproducto);
			string ia = to_string(idmarca);
			string pc = to_string(precio_costo);
			string pv = to_string(precio_venta);
			string e = to_string(existencia);
			string modificar = "update productos set producto = '" + producto + "', idmarca = " + ia + ", descripcion = '" + descripcion + "', imagen = '" + imagen + "', precio_costo = " + pc + ", precio_venta = " + pv + ", existencia = " + e + ", fecha_ingreso = '" + fecha_ingreso + "' where idproducto = "+ ip +"";
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

	void eliminar(int idproducto) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string ip = to_string(idproducto);
			string eliminar = "delete from productos where idproducto =" + ip + "";
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

