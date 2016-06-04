/*
* Interfaz de la clase Pila
*/

#ifndef _PILA_H
#define _PILA_H

#include <iostream>
using namespace std;

class Pila
{
    public:
        Pila (); //Constructor
        void VaciarPila(); //Vacía la pila
        bool PilaVacia (); //Comprueba si la pila está vacía
        bool Apilar (int); //Apila un elemento en la pila
        bool Desapilar (); //Desapila un elemento de la pila
        bool CimaPila (int &); //Consulta la cima de la pila
        friend ostream & operator<< (ostream &, const Pila &); //Sobrecarga del operador <<
        
    private:
        static const int MAX = 9;
        typedef int Vector[MAX];
        Vector datos;
        int cima;
};

#endif

