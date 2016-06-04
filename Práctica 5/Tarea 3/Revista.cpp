#include "Publicacion.h"
#include "Fecha.h"
#include "Revista.h"


/*************** Fecha::Fecha (void) *****************************************
 *
 *  Descripcion:  Constructor por defecto de la clase.
 *                Inicia el objeto a un código correcto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/

Revista::Revista ()
{
    codigo = 2; 
}

/*************** void Revista::IniciarFecha (string edi, Fecha fec, string tit, string per, int num)*************
 *
 *  Descripcion:  Inicia el objeto con un editor, fecha, titulo, periodicidad, ejemplar
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  edi             string     E    Editorial de la revista
 *  fec             Fecha      E    Fecha de la revista
 *  tit             string     E    Título de la revista
 *	per				string	   E	Periodicidad de la revista
 *	num				short		   E	Ejemplar de la revista
 *
 *  Valor devuelto:
 *  ninguno
 *****************************************************************************/

void Revista::IniciarRevista (string edi, Fecha fec, string tit, string per, int num)
{
    editor = edi;
    fecha = fec;
    titulo = tit;
    periodicidad = per;
    ejemplar = num;
    
    return;
}

/*************** void Revista::PonerTitulo (string tit)*************
 *
 *  Descripcion:  Pone el título de una revista
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  tit             string     E    Título de la revista
 *
 *  Valor devuelto:
 *  ninguno
 *****************************************************************************/

void Revista::PonerTitulo (string tit)
{
    titulo = tit;
    
    return;
}

/*************** void Revista::Periodicidad (string per)*************
 *
 *  Descripcion:  Pone la periodicidad de una revista
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *	per				string	   E	Periodicidad de la revista
 *
 *  Valor devuelto:
 *  ninguno
 *****************************************************************************/

void Revista::Periodicidad (string per)
{
    periodicidad = per;
    
    return;
}

/*************** void Revista::Ejemplar (int num)*************
 *
 *  Descripcion:  Pone el número del ejemplar en la revista
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *	num				short		   E	Ejemplar de la revista
 *
 *  Valor devuelto:
 *  ninguno
 *****************************************************************************/

void Revista::Ejemplar (int num)
{
    ejemplar = num;
}

/*************** string Revista::ConsultarTitulo (void)*************
 *
 *  Descripcion:  Consulta el título de una revista
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  string
 *****************************************************************************/


string Revista::ConsultarTitulo (void)
{
    return titulo;
}
/*************** string Revista::ConsultarPeriodicidad (void)*************
 *
 *  Descripcion:  Consulta la periodicidad de una revista
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  string
 *****************************************************************************/

string Revista::ConsultarPeriodicidad (void)
{
    return periodicidad;
}


/*************** int Revista::ConsultarEjemplar (void)*************
 *
 *  Descripcion:  Consulta el número de ejemplar de una revista
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  short
 *****************************************************************************/

int Revista::ConsultarEjemplar (void)
{
    return ejemplar;
}

/*************** ostream& operator<< (ostream& out, Revista rev) ***************
 *
 *  Descripcion:  Sobrecarga del operador <<
 *                Funcion 'friend' de la clase
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  out             ostream     E S  Flujo de salida donde se escribira la 
 *                                   informacion
 *  rev            Fecha       E    Revista a mostrar en el flujo de salida
 *
 *  Valor devuelto:
 *  ostream&   devuelve una referencia al propio flujo de salida
 *****************************************************************************/

ostream& operator<< (ostream& out, Revista rev)
{
    out << "Codigo y fecha: " << rev.codigo << '\t';
    out << rev.fecha << endl;    
    out << "Editorial: " << rev.editor << endl;
    out << "Titulo: " << rev.titulo << endl;
    out << "Periodicidad: " << rev.periodicidad << endl;
    out << "Ejemplar: " << rev.ejemplar << endl;
    
    return out;
}

/*************** Revista& Revista::operator = (const Revista & revs) ***************
 *
 *  Descripcion:  Sobrecarga del operador =

 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  rev            Fecha       E    Revista para pasar su contenido
 *
 *  Valor devuelto:
 *  *this					devuelve el contenido de revs a la Revista
 *****************************************************************************/

Revista& Revista::operator = (const Revista & revs)
{
	if(this != &revs)
	{
		this->ejemplar = revs.ejemplar;
	    this->titulo = revs.titulo;
		this->autor = revs.autor;
		this->periodicidad = revs.periodicidad;
	    this->codigo = revs.codigo;
	    this->editor = revs.editor;
	    this->fecha = revs.fecha;
	}
    return *this;
}
