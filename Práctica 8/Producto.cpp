/*
*  Implementacion de la clase Producto
*/

#include "Producto.h"
#include <string>

/*************** Producto::InicializarProducto(string n, string t, string s, string o, int c)********************
 *
 *  Descripcion:  Constructor del producto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 ************************************************/
void Producto::InicializarProducto(string n, string t, string s, string o, int c)
{
	nombre = n;
	tienda = t;
	seccion = s;
	observaciones = o;
	cantidad = c;
	
	return;
}

/*************** Producto::AsignaNombre (string n)********************
 *
 *  Descripcion:  Asigna el nombre del producto
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *    n             string      E    Asigna el nombre
 *
 *
 *  Valor devuelto:
 ************************************************/
void Producto::AsignaNombre (string n)
{
	nombre = n;
	
	return;
}

/*************** Producto::AsignaTienda(string t)********************
 *
 *  Descripcion:  Asigna la tienda a la que pertenece el producto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *    t             string      E    Asigna el nombre de la tienda
 *
 *
 *  Valor devuelto:
 ************************************************/
void Producto::AsignaTienda(string t)
{
	tienda = t;
	
	return;
}

/*************** Producto::AsignaSeccion(string t)********************
 *
 *  Descripcion:  Asigna la seccion del producto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *    t             string      E    Asigna la seccion del producto
 *
 *
 *  Valor devuelto:
 ************************************************/
void Producto::AsignaSeccion(string s)
{
	seccion = s;
	
	return;
}

/*************** Producto::AsignaObservaciones(string o)********************
 *
 *  Descripcion:  Asigna cualquier observacion sobre el producto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *    o             string      E    Asigna observaciones
 *
 *
 *  Valor devuelto:
 ************************************************/
void Producto::AsignaObservaciones(string o)
{
	observaciones = o;
	
	return;
}

/*************** Producto::AsignaCantidad(int c)********************
 *
 *  Descripcion:  Asigna la cantidad de productos.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *    c            string      E    Asigna la cantidad de productos
 *
 *
 *  Valor devuelto:
 ************************************************/
void Producto::AsignaCantidad(int c)
{
	cantidad = c;
	
	return;
}

/*************** Producto::DevuelveNombre (void)********************
 *
 *  Descripcion:  Devuelve el nombre del producto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *    
 *
 *
 *  Valor devuelto: string. Devuelve el nombre del producto
 ************************************************/
string Producto::DevuelveNombre(void)
{
	return nombre;
}

/*************** Producto::DevuelveTienda (void)********************
 *
 *  Descripcion:  Devuelve el nombre de la tienda del producto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *    
 *
 *
 *  Valor devuelto: string. Devuelve la tienda del producto
 ************************************************/
string Producto::DevuelveTienda(void)
{
	return tienda;
}

/*************** Producto::DevuelveSeccion (void)********************
 *
 *  Descripcion:  Devuelve la seccion del producto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *    
 *
 *
 *  Valor devuelto: string. Devuelve la seccion del producto
 ************************************************/
string Producto::DevuelveSeccion(void)
{
	return seccion;
}

/*************** Producto::DevuelveObservaciones (void)********************
 *
 *  Descripcion:  Devuelve las observaciones del producto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *    
 *
 *
 *  Valor devuelto: string. Devuelve las observaciones del producto
 ************************************************/
string Producto::DevuelveObservaciones(void)
{
	return observaciones;
}

/*************** Producto::DevuelveCantidad (void)********************
 *
 *  Descripcion:  Devuelve el nombre del producto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *    
 *
 *
 *  Valor devuelto: int. Devuelve la cantidad de productos
 ************************************************/
int Producto::DevuelveCantidad(void)
{
	return cantidad;
}

/*************** ostream& operator<< (ostream & out, Producto & p) ********************
 *
 *  Descripcion:  Sobrecarga del operador salida para mostrar el producto entero por pantalla.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  out             ostream      S   Flujo de datos
 *  p               Producto     E   Producto a mostrar
 *
 *  Valor devuelto: ostream.
 ************************************************/
ostream& operator<< (ostream & out, Producto & p)
{
    out << "Nombre: " << p.nombre << endl;
	out << "Tienda: " << p.tienda << endl;
	out << "Sección: " << p.seccion << endl;
	out << "Observaciones: " << p.observaciones << endl;
	out << "Cantidad: " << p.cantidad << endl;
	
	return out;
}

/*************** istream& operator>> (istream & in, Producto & p) ********************
 *
 *  Descripcion:  Sobrecarga del operador entrada para mostrar el producto entero por pantalla.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  in              istream      S   Flujo de datos
 *  p               Producto     E   Producto a mostrar
 *
 *  Valor devuelto: istream.
 ************************************************/
istream& operator>> (istream & in, Producto & p)
{
	
	cout << "Nombre: ";
	in >> p.nombre;
	cout << "Tienda: ";
	in >> p.tienda;
	cout << "Sección: ";
	in >> p.seccion;
	cout << "Observaciones: ";
	in >> p.observaciones;
	cout << "Cantidad: ";
	in >> p.cantidad;
	
	return in;
}
