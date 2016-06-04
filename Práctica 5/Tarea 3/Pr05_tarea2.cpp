include <iostream>
#include <Vector>
#include <fstream>
using namespace std;
#include <stdlib.h>

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
    vector<Libro> vl;		//Vector libros
    vector<Revista> vr;		//Vector revistas
    short cod;
    int total;				//Total publicaciones
    
    
    f.open("Publicaciones02.dat");
    
    if (!f)
        cout << "Error abriendo fichero de publicaciones" << endl;
    else
    {
        while (LeerPublicacionFichero(f, li, re, cod))
        {
            if (cod == 1)
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
    return 0;
}
       
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
