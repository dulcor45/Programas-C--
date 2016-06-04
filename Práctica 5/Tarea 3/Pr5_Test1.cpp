/************************** Pr5_Test1.cpp ************************************
 *
 *  Proposito: Programa que sirve para comprobar el correcto funcionamiento
 *             de las clases derivadas 'Libro' y 'Revista'
 *
 *  Historial del Desarrollo:
 *  Fecha       Autor              Id Cambio  Version  Descripcion del cambio
 *  ----------  ------------------ ---------  -------  ----------------------
 *  16-04-2013  Ricardo Ferris          0      0.9
 *****************************************************************************/

#include <iostream>
using namespace std;
#include <stdlib.h>

#include "Publicacion.h"
#include "Libro.h"
#include "Revista.h"
#include "Fecha.h"

void ProbamosLaClaseLibro (Libro);
void ProbamosLaClaseRevista (Revista);

/*****************************************************************************
 ************************ Programa Principal *********************************
 *****************************************************************************/
int main()
{
    Libro lib;
    Revista rev;
    
    /*
	 * Mostramos los objetos sin valores definidos o iniciados por defecto
	 */
    cout << "--------------------------------------------------------------\n";
    cout << "---> Datos originales (iniciacion por defecto):\n\n";
    cout << "---> Libro:\n\n";
    cout << lib;
    cout << "\n---> Revista:\n\n";
    cout << rev;
    cout << endl;
    
    system ("PAUSE");
    system ("cls");

    ProbamosLaClaseLibro (lib);
    
    ProbamosLaClaseRevista (rev);
   
    return 0;
}

void ProbamosLaClaseLibro (Libro lib)
{
    Fecha fec;
    /*
	 * Iniciamos el libro con un titulo, un autor, una editorial y 
	 * una fecha determinadas y lo mostramos por pantalla
	 */
    lib.IniciarLibro("Espasa y Calpe", fec.IniciarFecha (1, 1, 1939), 
	                 "Primer viaje en torno del globo", "Antonio Pigafetta");
    
    cout << "--------------------------------------------------------------\n";
    cout << "---> El libro con los datos iniciales:\n\n";
	cout << lib;

    /*
	 * Modificamos el campo del titulo y de la fecha y mostramos solo esos 
	 * campos y luego de nuevo el objeto completo
	 */
     lib.PonerTitulo ("El diario de tapas rojas");
     lib.PonerFecha(fec.IniciarFecha(17, 5, 2006) );

    cout << "\n--------------------------------------------------------------\n";
    cout << "---> Modificando el libro:\n\n";
     
    cout << "Nuevo titulo: " << lib.ConsultarTitulo() << endl;
    cout << "Nueva fecha: " << lib.ConsultarFecha() << endl;
     
    cout << "\n---> El registro ha quedado como sigue:\n\n";
    cout << lib;
    cout << endl;

    system ("PAUSE");
    system ("cls");
    return;
}

void ProbamosLaClaseRevista (Revista rev)
{
    Fecha fec;
    /*
	 * Iniciamos la revista con un titulo, una periodicidad, un numero,
	 * una editorial y  una fecha determinadas y lo mostramos por pantalla
	 */
    rev.IniciarRevista("Imprenta de Miguel Domingo", fec.IniciarFecha (1, 3, 1822), 
	                 "El Amolador", "Mensual", 3);
    
    cout << "--------------------------------------------------------------\n";
    cout << "---> La revista con los datos iniciales:\n\n";
	cout << rev;

    /*
	 * Modificamos el campo del titulo y de la fecha y mostramos solo esos 
	 * campos y luego de nuevo el objeto completo
	 */
     rev.PonerTitulo ("El archivo: revista literaria semanal");
     rev.PonerFecha(fec.IniciarFecha(12, 5, 1887) );

    cout << "--------------------------------------------------------------\n";
    cout << "---> Modificando la revista:\n\n";
     
    cout << "Nuevo titulo: " << rev.ConsultarTitulo() << endl;
    cout << "Nueva fecha: " << rev.ConsultarFecha() << endl;
     
    cout << "\n---> El registro ha quedado como sigue:\n\n";
    cout << rev;

    return;
}


