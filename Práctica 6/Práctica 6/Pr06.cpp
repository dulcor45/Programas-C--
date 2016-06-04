#include <iostream>
#include <Vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "Hanoi.h"
#include "Pila.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "spanish");
    
    Hanoi h; //Objeto de la clase
    int origen, destino; //Pila origen y pila destino
    bool comprobar_movimiento; //Comprueba si el movimiento de la carta es correcto
    char continuar_jugando; //Comrpueba si se quiere continuar jugando
    
    
    
    continuar_jugando = 'S';
          
    do
    {         	 
          cout << "Juego: Torres de Hanoi" << endl;
   		  cout <<"*************************" << endl;
          cout << h << endl;
          
          cout << "Introduzca la siguiente jugada:\n";
          cout << "Pila Origen (1-3): ";
          cin >> origen;
          cout << "Pila Destino (1-3): ";
          cin >> destino;
          
          origen --; //Decrementamos el origen para que se adapte al vector
          destino --;//Decrementamos el destino para que se adapte al vector
          
          comprobar_movimiento = h.MoverCarta(origen, destino); 
		  
          if(!comprobar_movimiento)//Comprueba si el movimiento es correcto
          {
			cout << "\n¡MOVIMIENTO INCORRECTO!" << endl;
			system("PAUSE");
          }
          
          system ("cls");
          
          if(h.JuegoFinalizado()) //Comprueba si el juego a terminado
          {
          	  cout << h << endl;
          	  cout << "¡Has ganado!" << endl;
              cout << "¿Desea iniciar una nueva partida? (S/N): ";
              cin >> continuar_jugando;
              
              if(continuar_jugando == 'S' || continuar_jugando == 's')
              	 h.IniciarJuego (); //Inicia el juego de nuevo
          }
          
    }
    while (continuar_jugando == 'S' || continuar_jugando == 's');
    

    
    system ("PAUSE");
    return 0;
}
