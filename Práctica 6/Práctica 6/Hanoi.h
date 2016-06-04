/*
*  Interfaz de la clase Hanoi
*/

#ifndef _HANOI_H
#define _HANOI_H

#include <iostream>
#include "Pila.h"
using namespace std;


class Hanoi
{
    public:
        Hanoi(); //Constructor
        void IniciarJuego (); //Inizializa el juego Hanoi
        bool MoverCarta (int, int); //Mueve las cartas entre mazos
        bool JuegoFinalizado (); //Determina el fin del juego
        void VaciarMazos(); //Vacia los mazos (pilas)
        friend ostream & operator<< (ostream &, const Hanoi &); //Sobrecarga del operador de salida
        
    private:
        static const int MAX_PILAS = 3;
        int numero_jugadas;
        typedef Pila VectorMazos[MAX_PILAS];
        VectorMazos mazos;
};

#endif
