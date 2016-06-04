/*
* Interfaz de la clase Libro
*/


#ifndef _LIBRO_H
#define _LIBRO_H

#include <iostream>
#include <string>
using namespace std;

#include "Fecha.h"
#include "Publicacion.h"

class Libro: public Publicacion
{
    public:
        Libro(); //Constructor
        void IniciarLibro (string, Fecha, string, string); //Inicia el objeto
        void PonerTitulo (string); //Asignamos el titulo
        void PonerAutor (string); //Asignamos el autor
        string ConsultarTitulo (void);  //Devuelve el titulo
        string ConsultarAutor (void);  //Devuelve el autor
        friend ostream& operator<< (ostream&, Libro); //Sobrecarga del operador de salida por pantalla
        
    private:
        string titulo, autor;
        short codigo;
};

#endif
