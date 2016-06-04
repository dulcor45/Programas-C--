/*******************************************************************
* Asignatura: Programacion                                        
* Curso 2012-2013                                                 
* Practica 7                                                      
* Colas                                                           
*                                                                 
* PROPÓSITO: Programa principal de prueba de la clase Cola.       
*    Fecha       Autor              Id Cambio  Version  Descripcion del cambio
*  ----------  ------------------ ---------  -------  ----------------------
*  23-05-2013  Sydney Aleixandre
*  23-05-2013  Jose Ferrús                                                       
*******************************************************************/

#include <cstdlib>
#include <iostream>
#include <queue>

#include "alumno.h"
#include "cola.h"
using namespace std;

void MostrarQueue(queue<Alumno>);
Alumno MostrarElementoQueue (queue<Alumno>, int);

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "spanish");
    //
    // Operaciones con la clase Cola
    //
 
    // Creamos objetos alumno de prueba
    Alumno a1(1,"Alumno 1");
    Alumno a2(2,"Alumno 2");
    Alumno a3(3,"Alumno 3");
    Alumno a4(4,"Alumno 4");
    Alumno a5(5,"Alumno 5");
    Alumno a6(6,"Alumno 6");
    Alumno a7(7,"Alumno 7");
    Alumno a8(8,"Alumno 8");

    cout << a1 << a2 << a3 << a4 << a5 << a6 << a7 << a8 << endl;
   
    // Creamos una cola
    Cola c;
    //Creamos un alumno auxiliar
    Alumno a;


	

    // Insertamos todos los objetos en la cola
    cout << "Operacion 1: encolar objetos en la cola" << endl;
    
    c.Encolar(a1);
    c.Encolar(a2);
    c.Encolar(a3);
    c.Encolar(a4);
    c.Encolar(a5);
    c.Encolar(a6);
    c.Encolar(a7);
    c.Encolar(a8);

    // Obtenemos el número de elementos

    cout << "Numero de elementos de la cola: " << c.Elementos () << endl;
    
    // Mostramos el contenido de la cola
    cout << "Mostramos el contenido de la cola:\n" << endl;
    c.Mostrar();

    // Extraemos un elemento y lo mostramos
    c.VerPrimero (a);
    cout << "El primer elemento es: " << a << ", y lo extramos." << endl;
    c.DesEncolar();

    // Mostramos el contenido de la cola 
    cout << "Mostramos el contenido de la cola:\n" << endl;
	c.Mostrar();
    // Mostramos el primer elemento (sin extraerlo)
    c.VerPrimero (a);
    cout << "El primer elemento ahora es: " << a << endl;

    // Mostramos el último elemento (sin extraerlo)
    c.VerUltimo (a);
    cout << "El ultimo elemento es: " << a << endl;

    // Mostramos el elemento en la posición 3 a partir del inicio (sin extraerlo)
    c.VerPosicion(3, a);
    cout << "El elemento que se encuentra en la posicion 3 es: " << a << endl;

    // Extraemos todos los elementos mostrando su valor
    cout << "Mostramos de nuevo la cola y la vaciamos." << endl;
	c.Mostrar();
    c.Vaciar();
    
    // Insertamos 3 elementos (de los iniciales)
    cout << "Encolamos mas elementos..." << endl;
    
    if (c.Encolar(a1) && c.Encolar(a4) && c.Encolar(a7))
    	cout << "Los elementos se encolaron correctamente." << endl;

    // Vaciamos la cola
    cout << "Vaciamos la cola." << endl;
	c.Vaciar();

    // La volvemos a vaciar (¿qué devuelve el método?)
	c.Vaciar();

    // Obtenemos el número de elementos
	cout <<  "Numero de elementos de la cola: " << c.Elementos () << endl;

/*################################################################################################*/
    cout << "...............................................................................\n\n\n";
    //
    // Operaciones con la clase para colas de STD
    //
    // Repetir las mismas operaciones pero ahora con una cola creada con
    // un objeto de la biblioteca STL.
    // Usaremos los mismos objetos alumno definidos en la primera parte


    // Creamos una cola
  	queue <Alumno> q;

    // Insertamos todos los objetos en la cola
	q.push (a1);
    q.push (a2);
    q.push (a3);
    q.push (a4);
    q.push (a5);
    q.push (a6);
    q.push (a7);
    q.push (a8);
    
    // Obtenemos el número de elementos
    cout << "Numero de elementos de la cola: " << q.size() << endl;

    // Mostramos el contenido de la cola
    //cout << q << endl; //HAY QUE DESENCOLAR PARA PODER MOSTRAR
    cout << "Mostramos el contenido de la cola:\n" << endl;
	MostrarQueue(q);
		

    // Extraemos un elemento y lo mostramos
    a = q.front();
    cout << "El primer elemento es: " << a << ", y lo extramos." << endl;
    q.pop();

    // Mostramos el contenido de la cola 
	//cout << q << endl;
    cout << "Mostramos el contenido de la cola:\n" << endl;
    MostrarQueue(q);

    // Mostramos el primer elemento (sin extraerlo)
    a = q.front();
    cout << "El primer elemento es: " << a << ", y lo extramos." << endl;

    // Mostramos el último elemento (sin extraerlo)
    a = q.back();
	cout << "El ultimo elemento es: " << a << endl;


    // Mostramos el elemento en la posición 3 a partir del inicio (sin extraerlo)
    //a = q.front() + 3;						
	a = MostrarElementoQueue (q, 3);
	cout << "El elemento que se encuentra en la posicion 3 es: " << a << endl;
	
    // Extraemos todos los elementos mostrando su valor
    cout << "Mostramos de nuevo la cola y la vaciamos." << endl;
    
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}

    // Insertamos 3 elementos (de los iniciales)
    cout << "Encolamos mas elementos..." << endl;
    q.push (a1);
    q.push (a4);
    q.push (a7);
    //if (q.push (a1) && q.push (a4) && q.push (a7))
    	cout << "Los elementos se encolaron correctamente." << endl;

    // Vaciamos la cola
    cout << "Vaciamos la cola." << endl;
    
    while (!q.empty())
		q.pop();

    // La volvemos a vaciar (¿qué devuelve el método?)
    while (!q.empty())
		q.pop();


    // Obtenemos el número de elementos
	cout << "Numero de elementos de la cola: " << q.size() << endl;


    // Fin
    system("PAUSE");
    return EXIT_SUCCESS;
}
/*************** void MostrarQueue(queue<Alumno> q)*************
 *
 *  Descripcion:  Mostrar una cola (queue)
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  q            queue<Alumno>   E    Cola de alumnos que queremos mostrar
 *  Valor devuelto:
 *  Ninguno.
 *****************************************************************************/
void MostrarQueue(queue<Alumno> q)
{
	Alumno a;
	
	while(!q.empty())
	{
		a = q.front();
		cout << a;
		q.pop();
	}
	
	return;	
}

/*************** Alumno MostrarElementoQueue (queue<Alumno> q, int pos)*************
 *
 *  Descripcion:  Mostrar una cola (queue)
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  q            queue<Alumno>   E    Cola de alumnos que queremos mostrar
 *	pos				int			 E	  Posición del alumno en la cola
 *  Valor devuelto:
 *  Alumno	El alumno que se encuentra en esa posición de la cola
 *****************************************************************************/

Alumno MostrarElementoQueue (queue<Alumno> q, int pos)
{	
	while(pos > 0)
	{
		q.pop();
		pos--;
	}
	
	return q.front();
}
