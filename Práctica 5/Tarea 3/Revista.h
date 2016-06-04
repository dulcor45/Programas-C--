/*
* Interfaz de la clase revista
*/

#ifndef _REVISTA_H
#define _REVISTA_H

#include <iostream>
#include <string>
using namespace std;
#include "Fecha.h"
#include "Publicacion.h"


class Revista: public Publicacion
{
    public:
        Revista(); //Constructor
        void IniciarRevista (string, Fecha, string, string, int);  //Inicia el objeto revista
        void PonerTitulo (string); //Pone el titulo de la revista
        void Periodicidad (string); //Pone la frecuencia de publicacion de la revista
        void Ejemplar (int); //Pone el numero del ejemplar
        string ConsultarTitulo (void);  //Devuelve el titulo
        string ConsultarPeriodicidad (void); //Devuelve la periodicidad
        int ConsultarEjemplar (void); //Devuelve el numero
        friend ostream& operator<< (ostream&, Revista); //Sobrecarga del operador de salida
        Revista& operator = (const Revista &); //Sobrecarga del operador =
    
    private:
        int ejemplar;
        string titulo, autor, periodicidad;
        short codigo;
};

#endif






