/*
*  Implementacion de la clase Hanoi
*/


#include <iostream>
#include <stdlib.h>
#include "Pila.h"
#include <time.h>
#include <cstdlib>
#include <vector>
#include "Hanoi.h"
using namespace std;



/*************** Hanoi::Hanoi () *****************************************
 *
 *  Descripcion:  Constructor por defecto de la clase.
 *                Inicia el objecto con un nuevo juego.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/
Hanoi::Hanoi ()
{
    IniciarJuego ();
}


/*************** void Hanoi::IniciarJuego () *****************************************
 *
 *  Descripcion:  Inicia el juego con tres pilas desordenadas de numeros.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/
void Hanoi::IniciarJuego ()
{
    int i, j, numero_cartas = 9;
    vector<int> x(numero_cartas);

    numero_jugadas = 0;
    i = 0;
    
    VaciarMazos(); //Vacia los mazos
    srand(time(NULL));
    	
    while (i < numero_cartas)
    {
    	x[i] = rand() % numero_cartas + 1; //Generamos un numero aleatorio para apilar en los mazos
    	
    	j = 0;
    	
    	while (x[j] != x[i])
    		j++;

    	if(j == i)
    	{	
    		if (i < 3)
            mazos[0].Apilar (x[i]);
        	else if (i < 6)
                 	mazos[1].Apilar (x[i]);
                 else
                 	mazos[2].Apilar (x[i]);
            i++;
    	}
    }
    
  return;  
}

/*************** bool Hanoi::MoverCarta (int pila_origen, int pila_destino) ************
 *
 *  Descripcion:  Mueve una carta desde una cima de una pila a otra elegida por el usuario
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  pila_origen     int          E    Pila desde la cual movemos el numero
 *  pila_destino    int          E    Pila donde depositamos la carta elegida
 *
 *  Valor devuelto:
 *  bool - Logico. Asegura que la operacion se ha realizado.
 ****************************************************************************/
bool Hanoi::MoverCarta (int pila_origen, int pila_destino)
{
     bool ok;
     int carta1, carta2;

     //Este if sirve para comprobar si la pila está vacía y 
	 // además que las pilas introducidas sean válidas
     if (mazos[pila_origen].PilaVacia () || !(pila_origen >= 0 && pila_origen <= 2 && pila_destino >= 0 && pila_destino <= 2))
        ok = false;
     else
     {
         mazos[pila_origen].CimaPila(carta1);
         mazos[pila_destino].CimaPila(carta2);
         
         //Comprobamos si la cima donde queremos apilar es mayor que la cima que queremos mover         
         if (carta1 < carta2) 
         {
             mazos[pila_origen].CimaPila(carta1);
             ok = mazos[pila_destino].Apilar(carta1);
             mazos[pila_origen].Desapilar();
             numero_jugadas ++;
         }
	}
	
     return ok;
}   

/*************** bool Hanoi::JuegoFinalizado () *****************************
 *
 *  Descripcion:  Determina cuando el juego finaliza segun las reglas, es decir, en 
 *                cuanto hay dos pilas vacias.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  bool - Logico. Asegura que la operacion se ha realizado.
 ****************************************************************************/
bool Hanoi::JuegoFinalizado ()
{
     bool finalizado;
     int i, cont;
     
     cont = 0;
     
     for (i = 0; i < MAX_PILAS; i++)
     {
         if (mazos[i].PilaVacia())
            cont ++;
     }
     if (cont == 2) //Comprobamos que hay dos pilas vacías
         finalizado = true;
     else
         finalizado = false;
         
    return finalizado;
}

/*************** ostream & operator<< (ostream & out, const Hanoi & h) *****************************
 *
 *  Descripcion:  Sobrecarga del operador salida por pantalla.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  out             ostream     E/S   Flujo de datos
 *  h               Hanoi       E/S   Objeto de la clase
 *
 *  Valor devuelto:
 *  ostream 
 ****************************************************************************/
ostream & operator<< (ostream & out, const Hanoi & h)
{
    out << "Número jugada: " << h.numero_jugadas << endl;
    out << "------------------------------------" << endl;
    out << "Pila #1: " << h.mazos[0] << endl;
    out << "Pila #2: " << h.mazos[1] << endl;
    out << "Pila #3: " << h.mazos[2] << endl;
    out << "------------------------------------" << endl;
    
    return out;
}

/*************** void Hanoi::VaciarMazos() *****************************
 *
 *  Descripcion:  Vacia las pilas.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 * 	ninguno
 ****************************************************************************/
void Hanoi::VaciarMazos()
{
	int i;
	
	for(i = 0; i < MAX_PILAS; i++)
		mazos[i].VaciarPila();

	return;
}

