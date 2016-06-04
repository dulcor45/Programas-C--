/*
*  Interfaz de la clase Producto
*/

#ifndef _PRODUCTO_H
#define _PRODUCTO_H

#include <string>
#include <iostream>

using namespace std;

class Producto
{
	public:
		void InicializarProducto(string, string, string, string, int);  //Constructor explicito
		void AsignaNombre (string); 
		void AsignaTienda(string); 
		void AsignaSeccion(string); 
		void AsignaObservaciones(string);
		void AsignaCantidad(int);
		string DevuelveNombre(void);
		string DevuelveTienda(void);
		string DevuelveSeccion(void);
		string DevuelveObservaciones(void);
		int DevuelveCantidad(void);
		friend ostream& operator<< (ostream &, Producto &);  //Sobrecarga del operador salida
		friend istream& operator>> (istream &, Producto & ); //Sobrecarga del operador entrada
		
	private:
		string nombre, tienda, seccion, observaciones;
		int cantidad;
		
};

#endif //_PRODUCTO_H
