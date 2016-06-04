
/************************** Pr05_tarea3.cpp ***********************************
 *
 *  Proposito: Implementacion de los metodos propios de la clase Fecha
 *             asi como las funciones 'friend'
 *
 *  Historial del Desarrollo:
 *  Fecha       Autor              Id Cambio  Version  Descripcion del cambio
 *  ----------  ------------------ ---------  -------  ----------------------
 *  02-05-2013  Sydney Aleixandre
 *  02-05-2013  Jose Ferrús   
 *****************************************************************************/

#include <iostream>
#include <Vector>
#include <fstream>
using namespace std;
#include <stdlib.h>
#include <string>

#include "Publicacion.h"
#include "Fecha.h"
#include "Libro.h"
#include "Revista.h"

#include "PlantillaOrdenarTitulo.h"
#include "PlantillaOrdenarFecha.h"
#include "PlantillaMostrar.h"

void CorregirCaracter(string &);
bool LeerPublicacionFichero (ifstream &, Libro &, Revista &, short &);
void Mostrar (vector<Revista> vr, vector<Libro> vl, Fecha fecha1, Fecha fecha2);

int main ()
{
    Libro li;
    Revista re;
    ifstream f;
    vector<Libro> vl;		//Vector libros
    vector<Revista> vr;		//Vector revistas
    vector<Publicacion> vp;
    short cod;
    int total;				//Total publicaciones
    Fecha fecha1, fecha2;


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
        
        OrdenarTitulo(vr, 0, vr.size() - 1);
		OrdenarTitulo(vl, 0, vl.size() - 1);
		
		OrdenarFecha(vr, 0, vr.size() - 1);
		OrdenarFecha(vl, 0, vl.size() - 1);
		
		cout << "Introduce dos fechas: " << endl;
		cout << "Fecha inicial: ";
		cin >> fecha1;
		cout << "Fecha final: ";
		cin >> fecha2;

		
    	//	Mostrar (vr, fecha1, fecha2); //Mostramos las revistas
     	//  Mostrar (vl, fecha1, fecha2); //Mostramos los libros
        Mostrar (vr, vl, fecha1, fecha2);
        
        total = vl.size () + vr.size ();
        cout << "Se han leido un total de " << total;
    	cout << " publicaciones.\n";
    }
    
    f.close();
    system("PAUSE");
    return 0;
}

/*************** bool LeerPublicacionFichero (ifstream & f, Libro & libro, Revista & revista, short & codigo)*************
 *
 *  Descripcion:  Lee las revistas y libros
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  f             ifstream &   E    Fichero a leer
 *  libro		    Libro &         Un libro
 *  revista		   Revista &		Una revista
 *  Valor devuelto:
 *  bool		devuelve verdadero si ha podido leer correctamente desde fichero	
 *****************************************************************************/


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
        CorregirCaracter(editorial);
        CorregirCaracter(titulo);
        
        if(codigo == 1) //a partir de y una menos fecha
        {
        	getline(f, autor);
        	CorregirCaracter(autor);
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


/*************** void CorregirCaracter(string & titulo)*************
 *
 *  Descripcion:  Quita los acentos de los carácteres
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  titulo           string      E    String a corregir
 *  Valor devuelto:
 *  ninguno	
 *****************************************************************************/

void CorregirCaracter(string & titulo)
{
	unsigned int i;
	
	for(i = 0; i < titulo.size(); i++)
	{
		if(titulo[i] == 'á' || titulo[i] == 'à')
			titulo[i] = 'a';
		else	
			if(titulo[i] == 'Á' || titulo[i] == 'À')
				titulo[i] = 'A';
			else	
				if(titulo[i] == 'é' || titulo[i] == 'è')
					titulo[i] = 'e';
				else	
					if(titulo[i] == 'É' || titulo[i] == 'È')
						titulo[i] = 'E';
					else
						if(titulo[i] == 'í'|| titulo[i] == 'ì')
							titulo[i] = 'i';
						else	
							if(titulo[i] == 'Í' || titulo[i] == 'Ì')
								titulo[i] = 'I';
							else
								if(titulo[i] == 'ó' || titulo[i] == 'ò')
									titulo[i] = 'o';
								else	
									if(titulo[i] == 'Ó' || titulo[i] == 'Ò')
										titulo[i] = 'O';
									else
										if(titulo[i] == 'ú' || titulo[i] == 'ù')
											titulo[i] = 'u';
										else
											if(titulo[i] == 'Ú' || titulo[i] == 'Ù')
												titulo[i] = 'U';
											else
												if(titulo[i] == 'ñ')
													titulo[i] = 'n';
													else
														if(titulo[i] == 'Ñ')
															titulo[i] = 'N';
	}
	
	return;
}

/*************** void Mostrar (vector<Revista> vr, vector<Libro> vl, Fecha fecha1, Fecha fecha2)**
 *
 *  Descripcion:  Quita los acentos de los carácteres
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  vr            vector<Revista>      E    Vector revistas
 *  vl			  vector<Libro>        E	Vector libros
 * fecha1			Fecha			   E     Fecha inicial
 * fecha2			Fecha			   E     Fecha final
 *  Valor devuelto:
 *  ninguno	
 *****************************************************************************/

void Mostrar (vector<Revista> vr, vector<Libro> vl, Fecha fecha1, Fecha fecha2)
{
    int i, j, i2, j2;
    i = 0;
    j = 0;
    i2 = vr.size();
	j2 = vl.size();
    
    
    while(vr[i].ConsultarFecha() < fecha1)//Conjunto de revistas mayores que fecha2
    	i ++;
    	
    while(vl[j].ConsultarFecha() < fecha1)//Conjunto de libros mayores que fecha2
    	j ++;

	while(fecha2 < vr[i2].ConsultarFecha())//Conjunto de revistas menores que fecha2
		i2--;
		
	while(fecha2 < vl[j2].ConsultarFecha()) //Conjunto de libros menores que fecha2
		j2--;


    while(i < i2 || j < j2) //Mostrar de forma ordenada
    {
    	if(vr[i].ConsultarFecha() < vl[j].ConsultarFecha())
    	{
    		   
    		cout << vr[i] << endl;
    		i++;
    	}
    	else
    	{
    		cout << vl[j] << endl;
    		j++;
    	}
    }

}
