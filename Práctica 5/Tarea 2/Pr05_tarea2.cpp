/*
* Programa principal
*/


#include <iostream>
#include <Vector>
#include <fstream>
#include <stdlib.h>
using namespace std;

#include "Publicacion.h"
#include "Fecha.h"
#include "Libro.h"
#include "Revista.h"

#include "PlantillaMostrar.h"

bool LeerPublicacionFichero (ifstream &, Libro &, Revista &, short &);

int main ()
{
    Libro li;
    Revista re;
    ifstream f;
    vector<Libro> vl;		//Vector de libros
    vector<Revista> vr;		//Vector de revistas
    short cod;
    int total;
    
    f.open("Publicaciones02.dat"); //Abrimos el fichero donde se encuentran las publicaciones
    
    if (!f)
        cout << "Error abriendo fichero de publicaciones" << endl;
    else
    {
        while (LeerPublicacionFichero(f, li, re, cod))
        {
            if (cod == 1)  //Dependiendo del codigo, guardamos en el vector de libros (1) o el de revistas (2)
                vl.push_back (li);
            else
                vr.push_back (re);
        }
        Mostrar (vl); //Mostramos los libros
    	
        Mostrar (vr); //Mostramos las revistas
        
        total = vl.size () + vr.size ();
        
        cout << "Se han leido un total de " << total;
    	cout << " publicaciones.\n";
    }
    
    f.close();
    
    system ("PAUSE");
    return 0;
}

/*************** bool LeerPublicacionFichero (ifstream & f, Libro & libro, Revista & revista, short & codigo)*************
 *
 *  Descripcion:  Nos permite leer las publicaciones de fichero e iniciar los objetos para despues
 *                pasar la informacion a los vectores.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  f               ifstream     E   fichero con las publicaciones
 *  libro           Libro        E   objeto libro
 *  revista         Revista      E   objeto revista
 *  codigo          short        E   codigo identificador de la publicacion
 *  Valor devuelto:
 ************************************************/       
bool LeerPublicacionFichero (ifstream & f, Libro & libro, Revista & revista, short & codigo)
{
    bool ok;
    string editorial, autor, titulo, periodicidad;
    int numero;
	Fecha fecha;
	
    if (f >> codigo)
    {
    	ok = true;
    	
        f >> fecha;
        f.ignore ();
        getline (f, editorial);
        getline(f, titulo);
        
        if(codigo == 1)
        {
        	getline(f, autor);
            libro.IniciarLibro (editorial, fecha, titulo, autor);
    	}
        else
        {
        	getline(f, periodicidad);
        	f >> numero;
            revista.IniciarRevista (editorial, fecha, titulo, periodicidad, numero);
        }

    } 
    else
        ok = false;

    return ok;
}
