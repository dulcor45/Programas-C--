/*
* Implementacion de la clase Libro
*/

#include "Publicacion.h"
#include "Fecha.h"
#include "Libro.h"

/*************** Libro::Libro()*************
 *
 *  Descripcion:  Constructor del libro. Inicia el codigo a 1.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 ************************************************/
Libro::Libro ()
{
    codigo = 1;
}


/*************** void Libro::IniciarFecha (string edi, Fecha fec, string tit, string aut)*************
 *
 *  Descripcion:  Inicia el objeto con el libro.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  edi              string      E    editorial del libro
 *  fec              Fecha       E    Fecha de publicacion
 *  tit              string      E    titulo del libro
 *  aut              string      E    autor del libro
 *
 *  Valor devuelto:
 *  Nada.
 *****************************************************************************/
void Libro::IniciarLibro (string edi, Fecha fec, string tit, string aut)
{
    editor = edi;
    fecha = fec;
    titulo = tit;
    autor = aut;

    return;   
}

/*************** void Libro::PonerTitulo (string tit)*************
 *
 *  Descripcion:  Pone el titulo del libro.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  tit              string      E    titulo del libro
 *
 *  Valor devuelto:
 *  Nada.
 *****************************************************************************/
void Libro::PonerTitulo (string tit)
{
    titulo = tit;
    
    return;
}

/*************** void Libro::PonerAutor (string aut)*************
 *
 *  Descripcion:  Pone el autor del libro.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  aut             string      E    autor del libro
 *
 *  Valor devuelto:
 *  Nada.
 *****************************************************************************/
void Libro::PonerAutor (string aut)
{
    autor = aut;
    
    return;
}

/*************** void Libro::ConsultarTitulo (void)*************
 *
 *  Descripcion:  Devuelve el titulo del libro.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 *  string. El titulo del libro
 *****************************************************************************/
string Libro::ConsultarTitulo (void)
{
    return titulo;
}

/*************** void Libro::ConsultarAutor (void)*************
 *
 *  Descripcion:  Devuelve el titulo del libro.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 *  string. El autor del libro
 *****************************************************************************/
string Libro::ConsultarAutor (void)
{
    return autor;
}

/*************** ostream& operator<< (ostream& out, Libro lib)*************
 *
 *  Descripcion:  Sobrecarga del operador salida para que muestre toda la informacion correspondiente
 *                a un libro.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  out              ostream    E S   Flujo de datos de salida
 *  lib              Libro       E    Libro que vamos a mostrar
 *  Valor devuelto:
 *  string. El titulo del libro
 *****************************************************************************/
ostream& operator<< (ostream& out, Libro lib)
{
    out << "Codigo y fecha: " << lib.codigo << '\t';
    out << lib.fecha << endl;    
    out << "Editorial: " << lib.editor << endl;
    out << "Titulo: " << lib.titulo << endl;
    out << "Autor: " << lib.autor << endl;
    
    return out;
}

/*************** Libro& Libro::operator = (const Libro & libs) ***************
 *
 *  Descripcion:  Sobrecarga del operador =
 *
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  libs           Fecha       E    Libro para pasar su contenido
 *
 *  Valor devuelto:
 *  *this					devuelve el contenido de revs al Libro
 *****************************************************************************/

Libro& Libro::operator = (const Libro & libs)
{
	if(this != &libs)
	{
	    this->titulo = libs.titulo;
		this->autor = libs.autor;
	    this->codigo = libs.codigo;
	    this->editor = libs.editor;
	    this->fecha = libs.fecha;
	}
    return *this;
}
