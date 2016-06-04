#include "Alumno.h"
using namespace std;

/*************** Alumno::Alumno()********************
 *
 *  Descripcion:  Constructor de la pila. Inicia el 
 					*nombre y el código a 0.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 ************************************************/
 
Alumno::Alumno ()
{
    nombre = "";
    cod = 0;
}

/*************** Alumno::Alumno (int codigo, string nom)*************
 *
 *  Descripcion:  Constructor de la pila. Inicia el nombre y el 
 *					código a los valores que les pasamos.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 *  Nada.
 *****************************************************/
 
Alumno::Alumno (int codigo, string nom)
{
    nombre = nom;
    cod = codigo;
}

/*************** int Alumno::dameCodigo (void)*************
 *
 *  Descripcion:  Devuelve el código.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 *  int		  Devuelve el código del alumno
 *****************************************************/
 
int Alumno::dameCodigo (void)
{
    return (cod);
}

/*************** string Alumno::dameNombre (void)*************
 *
 *  Descripcion:  Devuelve el código.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 *  string		Devuelve el nombre del alumno
 *****************************************************/

string Alumno::dameNombre (void)
{
    return (nombre);
}

/*************** ostream & operator<< (ostream & out, const Pila & p)*************
 *
 *  Descripcion:  Sobrecarga del operador salida para que muestre toda la informacion correspondiente
 *                a un alumno.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  out              ostream    E S   Flujo de datos de salida
 *  a                Alumno     E     Alumno que vamos a mostrar
 *  Valor devuelto:
 *  out		Los datos del alumno
 *****************************************************************************/

ostream& operator << (ostream & out,const Alumno & a)
{
    out << "Nombre del alumno: " << a.nombre << endl;
    out << "Código del alumno: " << a.cod << endl;
    
    return out;
}
