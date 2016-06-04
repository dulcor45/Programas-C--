/************************** FRACTION.H ************************************/
/* Declaración de una clase para Fracciones. Una fracción se representa   */
/* por un par de números enteros: el numerador y el denominador           */
/**************************************************************************/

#ifndef _FRACCION_H
#define _FRACCION_H

#include <iostream>
using namespace std;

class Fraccion
{
    public:
        Fraccion(); //Constructor por defecto
        Fraccion(int n, int d); //Constructor modificado

        // Métodos observadores y modificadores
        int ObtenNum() const; // Devuelve el Numerador
        int ObtenDen() const; // Devuelve el Denominador
        void PonNum(int); // Modifica el Numerador
        void PonDen(int); // Modifica el Denominador
   
        // Entrada y salida
        void Leer();     // Leer una fracci¢n desde teclado
        void Escribir() const; // Mostrar una fracci¢n en pantalla

        double Evaluar() const;   // Valor decimal de una fracci¢n

        // Operadores  
        friend Fraccion operator+ (const Fraccion &, const Fraccion &); //Suma
        friend Fraccion operator- (const Fraccion &, const Fraccion &); //Resta
		friend bool operator== (const Fraccion &, const Fraccion &); //Comparacion
		friend ostream & operator<< (ostream &, const Fraccion &); //Salida
		friend istream & operator>> (istream &, Fraccion &); //Entrada
		
		void Simplifica(); //Simplifica las fracciones

		friend Fraccion operator+ (const Fraccion &, int); //Suma una fraccion a un numero
		friend Fraccion operator+ (int, const Fraccion &); //Suma un numero a una fraccion
		
    private:
        int num;   // numerador de la fracción
        int den;   // denominador de la fracción
        int mcd (int, int);
  
};

#endif
