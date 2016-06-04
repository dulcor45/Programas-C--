#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "Fundacion.h"
#include "Persona.h"
using namespace std;

int main()
{
	Fundacion f;
	int op;
	string nombref, presidente, nombre, apellido1, apellido2, dni;
	float dineros;
	Persona p;
	
	
	
	do
	{
		cout << "1. Cambiar nombre" << endl << "2. Ingresar dinero" << endl << "3. Retirar dinero" << endl;
		cout << "4. Cambiar presidente" << endl << "5. Agregar miembro" << "\n6. Desligar miembros\n" << "7. Salir" << endl;
		cin >> op;
		
		switch(op)
		{
				case 1:
					cout << "Introduce un nombre para la fundacion: ";
					cin >> nombref;
					f.AsignarNombre(nombref);
				break;
				case 2:
					cout << "Introduce la cantidad de dinero a ingresar (euros): ";
					cin >> dineros;

					f = f + dineros;
					cout << "El dinero fue ingresado correctamente. El saldo actual es " << f.DevuelveSaldo() << "." << endl;

					/*if (f.Ingresar(dineros))
						cout << "El dinero fue ingresado correctamente. El saldo actual es " << f.DevuelveSaldo() << "." << endl;
					else
						cerr << "No se pudo realizar la operacion" << endl;*/
				break;
				case 3:
					cout << "Introduce la cantidad de dinero a retirar (euros): ";
					cin >> dineros;

					f = f - dineros;
					cout << "El dinero fue retirado correctamente. El saldo actual es " << f.DevuelveSaldo() << "." << endl;
					
					/*if (f.Retirar(dineros))
						cout << "El dinero fue retirado correctamente. El saldo actual es " << f.DevuelveSaldo() << "." << endl;
					else
						cerr << "No se pudo realizar la operacion" << endl;*/
				break;
				case 4:
					cout << "Introduce el DNI del presidente (9 digitos): ";
					cin >> presidente;

					if (f.AsignarPresidente(presidente))
						cout << "El nuevo presidente es " << f.DevuelvePresidente() << "." << endl;
					else
						cerr << "No se pudo realizar la operacion" << endl;
				break;				
				case 5:
					cout << "Introduce un nuevo miembro" << endl;
					cout << "	Introduce DNI: "; 
					cin >> dni;
					cout << "	Introduce el nombre: ";
					cin >> nombre;
					cout << "	Introduce el primer apellido: ";
					cin >> apellido1;
					cout << "	Introduce el segundo apellido: ";
					cin >> apellido2;
					
					p.AsignarDatos(dni, nombre, apellido1, apellido2);
					
					f = f + p;
					/*if (f.AgregarMiembro(p))
						cout << p;
					else
						cerr << "No se pudo realizar la operacion" << endl;*/
				break;
				case 6:
					cout << "Introduce el DNI del miembro de la fundacion que desea eliminar: ";
					cin >> dni;
					
					f = f - dni;
					/*if (f.DesligarMiembro(dni))
					{
						cout << "El miembro fue eliminado con exito." << endl;
					}
					else
						cerr << "No se pudo realizar la operacion" << endl;*/
				break;
		}
	}
	while(op != 7);
	
	system("PAUSE");
	return 0;
}


