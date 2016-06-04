/************************** Pr5_Test0.cpp ************************************
 *
 *  Proposito: Programa que lee un fichero de publicaciones y las muestra
 *             por pantalla
 *
 *  Historial del Desarrollo:
 *  Fecha       Autor              Id Cambio  Version  Descripcion del cambio
 *  ----------  ------------------ ---------  -------  ----------------------
 *  16-04-2013  Ricardo Ferris          0      0.9
 *****************************************************************************/

#include <iostream>
#include <Vector>
#include <fstream>
using namespace std;
#include <stdlib.h>

#include "Publicacion.h"
#include "Fecha.h"
#include "Libro.h"
#include "Revista.h"

void MostrarPublicaciones (vector<Publicacion>);
bool LeerPublicacionFichero (ifstream &, Publicacion &);

/*****************************************************************************
 ************************ Programa Principal *********************************
 *****************************************************************************/
int main()
{
    vector<Publicacion> publicaciones;
    Publicacion publicacion;
    ifstream f;
    
    f.open ("Publicaciones01.dat");
    
    if (!f)
        cout << "Error abriendo fichero de publicaciones";
    else
    {
        while (LeerPublicacionFichero (f, publicacion) )
            publicaciones.push_back (publicacion);
        
        MostrarPublicaciones (publicaciones);
    }
    
    return 0;
}

/***** MostrarPublicaciones **************************************************
 *
 * Prototipo:
 *     void MostrarPublicaciones (vector<Publicacion> publicaciones)
 *
 * Proposito:
 *  Mostrar todas las publicaciones contenidas en el vector que se le pasa
 *  como parametro
 *
 * Paramatros:
 *  Nombre        Tipo                E/S  Descripcion
 *  ------        ----------          ---  ------------
 *  publicaciones vector<Publicacion> E    Vector de la STL donde se
 *                                         encuentra la informacion a mostrar
 *
 *  Valor devuelto:
 *  Ninguno
 *****************************************************************************/
void MostrarPublicaciones (vector<Publicacion> publicaciones)
{
	int i;

    cout << "Las publicaciones leidas son:\n";

    for (i = 0; i < publicaciones.size (); i++)
        cout << publicaciones[i] << endl;

    cout << "Se han ledio un total de " << publicaciones.size ();
    cout << " publicaciones.\n";

    return;
}

/***** LeerPublicacionFichero ************************************************
 *
 * Prototipo:
 *     bool LeerPublicacionFichero (ifstream & f, Publicacion & publicacion)
 *
 * Proposito:
 *  Leer del fichero f un objeto del tipo publicacion (codigo, fecha y
 *  editorial) y devolver el objeto leido.
 *
 * Paramatros:
 *  Nombre        Tipo                E/S  Descripcion
 *  ------        ----------          ---  ------------
 *  f             ifstream            E S  Fichero del que leer
 *  publicacion   Publicacion           S  Variable a traves de la que se
 *                                         devuelve la informacion leida
 *
 *  Valor devuelto:
 *  bool  true si la informacion ha sido leida correctamente
 *        false si la informacion NO se ha podido leer de forma correcta
 *****************************************************************************/
bool LeerPublicacionFichero (ifstream & f, Publicacion & publicacion)
{
    bool ok;
    long long codigo;
    string editorial;
	Fecha fecha;
	
    if (f >> codigo)
    {
    	ok = true;
    	
        f >> fecha;
        f.ignore ();
        getline (f, editorial);
        publicacion.IniciarPublicacion (codigo, editorial, fecha);
    }
    else
        ok = false;

    return ok;
}

