/*
*  Interfaz de la clase Lista
*/


#ifndef _LISTA_H
#define _LISTA_H

#include <string>
#include "Producto.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Lista
{
	public:
		Lista (void); //Constructor
		Lista (const Lista &); //Constructor
		~Lista (void); //Destructor
		void Insertar (Producto); //Insertar un producto en la lista
		bool Eliminar (void); //Eliminar un producto de  la lista
		bool Consultar (Producto &); //Consultar un producto de la lista
		bool ListaVacia (void); //Comprueba si la lista esá vacía
		void IrAInicio (void); //Vuelve al inicio de la lista
		bool Avanzar (void); //Avanza en la lista
		void Copiar (const Lista &); //Copia una lista
		void Vaciar (void); //Vacia la lista
		bool Buscar (string); //Busca el nombre de un produco en la lista
		bool FinalLista (void); //Comprueba si es el final de la lista
		
		const Lista & operator= (const Lista &); //Sobrecarga del operador =
		friend ostream& operator << (ostream &, const Lista &); //Sobrecarga del operador <<
		friend ostream& operator >> (ostream &, const Lista &); //Sobrecarga del operador >>
		
	private:	
        struct Nodo;
        typedef Nodo* Puntero;
        struct Nodo
        {
            Producto info;
            Puntero sig;
        };
        Puntero ini; //Puntero al inicio de la lista
        Puntero fin; //Puntero al inicio de la lista
        Puntero pto; //Punto de interés
};

#endif
