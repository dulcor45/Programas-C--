/*
* Implementacion de la clase Pila
*/

#include "Pila.h"
using namespace std;

/*************** Pila::Pila()********************
 *
 *  Descripcion:  Constructor de la pila. Inicia la cima a -1.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 ************************************************/
Pila::Pila ()
{
    cima = -1;
}

/*************** void Pila::VaciarPila()*************
 *
 *  Descripcion:  Vacía la pila.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 *  Nada.
 *****************************************************/
void Pila::VaciarPila()
{
	cima = -1;
}

/*************** bool Pila::PilaVacia ()*************
 *
 *  Descripcion:  Comprueba si la pila está vacía.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 *  Nada.
 *****************************************************************************/
bool Pila::PilaVacia ()
{
     return (cima == -1);
}
/*************** bool Pila::Apilar (int x)*************
 *
 *  Descripcion:  Apila un número en la pila.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *    x				int			E     El número que queremos apilar
 *
 *  Valor devuelto:
 *  bool	Devuelve si se ha podido apilar correctamente
 *****************************************************************************/
bool Pila::Apilar (int x)
{
    bool ok;
    
    if (cima == MAX-1) //No hay espacio
        ok = false;
    else //Hay espacio y se puede apilar
    {
        cima++;
        datos[cima] = x;
        ok = true;
    }
    return ok;
}
/*************** bool Pila::Desapilar (void)*************
 *
 *  Descripcion:  Apila un número en la pila.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 *  bool	Devuelve si se ha podido desapilar correctamente
 *****************************************************************************/
bool Pila::Desapilar (void)
{
    bool ok;
    
    if (cima == -1) //Pila vacia y no se puede desapilar
        ok = false;
    else //Hay elementos y es posible eliminar la cima
    {
        cima--;
        ok = true;
    }
    return (ok);
}
/*************** bool Pila::CimaPila (int & x)*************
 *
 *  Descripcion:  Apila un número en la pila.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *	x				int			 S		Devuelve la cima de la pila
 *  Valor devuelto:
 *  bool	Devuelve si se ha podido encontrar la cima
 *****************************************************************************/
bool Pila::CimaPila (int & x)
{
    bool ok;
    
    if (cima == -1) //Pila vacia y no hay elementos en la cima
        ok = false;
    else //Hay elementos y es posible consultar la cima
    {
        x = datos[cima];
        ok = true;
    }
    return (ok);
}
/*************** ostream & operator<< (ostream & out, const Pila & p)*************
 *
 *  Descripcion:  Sobrecarga del operador salida para que muestre toda la informacion correspondiente
 *                a una pila..
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  out              ostream    E S   Flujo de datos de salida
 *  p                Pila       E     Pila que vamos a mostrar
 *  Valor devuelto:
 *  out		Los datos de la pila
 *****************************************************************************/
ostream & operator<< (ostream & out, const Pila & p)
{
    int i;
    
    for (i = 0; i <= p.cima; i++)
        out << p.datos[i] << " ";

    return out;
}


