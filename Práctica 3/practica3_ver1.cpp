/***************************************************************************/
/* Asignatura: Programacion en Grado ing. Informatica/Multimedia           */
/* Curso 2012-2013                                                         */
/* Programación Orientada a Objetos                                        */
/*                                                                         */
/* AUTOR: Jose Fco. García                                                 */
/*                                                                         */
/* PROPOSITO:                                                              */
/* Modificar una clase en C++ para añadir nuevos métodos u operaciones.    */
/* Implementar el concepto de constructor, de sobrecarga de operadores y   */
/* el uso de funciones friend.                                             */
/***************************************************************************/
#include <iostream>
#include <stdlib.h>
#include "fraccion.h"

using namespace std;

int main()
{
    //fracciones sobre las que operaremos
	Fraccion f1, f2, f3;
	int num;
	char x;
	
	do
	{
		cout << "1- Introduce 2 fracciones.\n2- Suma de fracciones.\n3- Resta de fracciones.\n";
		cout << "4- Comparacion de fracciones.\n5- Sumar un numero a una fraccion.\n6- Sumar una fraccion a un numero.\n7- Salir.\n" << endl;
		cout << "Elige la operacion a realizar: ";
		cin >> x;
	
		switch (x)
		{
			case 1:
				//Solicitar la introducción de una fracción
				cout << "Introduce una fraccion (num/den): ";
				cin >> f1;
				cout << "Introduce una fraccion (num/den): " ;
				cin >> f2;
				cout << endl;
				break;
			case 2:
				//Suma de dos fracciones
				f3 = f1 + f2;
				f3.Simplifica();
				cout << "Resultado: " << f3 << endl;
				cout << endl;
				break;
			case 3:
				//Resta de dos fracciones
				f3 = f1 - f2;
				f3.Simplifica();
				cout << "Resultado: " << f3 << endl;
				cout << endl;
				break;
			case 4:
				//Comparacion de fracciones
				if(f1 == f2)
					cout << f1 << " y " << f2 << " son iguales.";
				cout << endl;
				break;
			case 5:
				//Sumar una fraccion a un numero
				cout << "Introduce el numero a sumar: ";
				cin >> num;
				f3 = f1 + num;
				f3.Simplifica();
				cout << "Resultado: " << f3 << endl;
				cout << endl;
				break;
			case 6:
				//Sumar un numero a una fraccion
				cout << "Introduce el numero a sumar: ";
				cin >> num;
				f3 = num + f1;
				f3.Simplifica();
				cout << "Resultado: " << f3 << endl;
				cout << endl;
				break;
		};
	}
	while (x != 7);

    

    //Mostrar el valor real de la fraccion
	cout << "Su valor es: " << f3.Evaluar() << endl;
    
    system("PAUSE");

    return 0;    
    
}
