/************************** p8.cpp ***********************************
 *
 *  Proposito: Realizar una aplicación para la gestión de la lista de la compra de una familia
 *
 *  Historial del Desarrollo:
 *  Fecha       Autor              Id Cambio  Version  Descripcion del cambio
 *  ----------  ------------------ ---------  -------  ----------------------
 *  30-05-2013  Sydney Aleixandre
 *  30-05-2013  Jose Ferrús   
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <string>

#include "Producto.h"
#include "Lista.h"
using namespace std;

int main()
{
	int op; //Código de operación
	Producto p, q; //Productos
	string nombre; //Nombre de un producto
	Lista l; //Lista de productos
	bool parar; //Comprueba si se ha de parar

	setlocale(LC_ALL, "spanish");

	do
	{
		cout << "1. Ingresar producto\n2. Borrar Producto\n3. Ver lista en orden directo\n4. Ver lista en orden inverso\n5. Salir\n";
		cout << "\nOpcion: "; 
        cin >> op; //Introduce el código de operación
	
		switch(op)
		{
			case 1: //Inserta un producto
			    cout << "Ingresa un producto: " << endl;
			    cin >> p;
			    
			    parar = false;
			    
			    if(!l.Buscar(p.DevuelveNombre()))//Comprueba si no existe ese producto
			    {
			    	l.IrAInicio();
			    	
				    while (!l.FinalLista() && !parar)
				    {
				        l.Consultar(q); //Consulta un producto en la lista
				        
				        if (p.DevuelveSeccion() < q.DevuelveSeccion()) //Avanza hasta la sección correspondiente
				             parar = true;
				        else
				             l.Avanzar(); //Avanza el punto de interés de la lista
				    }
				    
			    	l.Insertar(p); //Inserta un producto en la lista
				}
                else
                	cout << endl << "¡ESE PRODUCTO YA EXISTE!" << endl;
			    
				break;
				
			case 2: //Elimina un producto
			    cout << "Nombre del producto que desea borrar: ";
			    cin >> nombre;
			    
			    if (l.Buscar(nombre)) //Busca el nombre del producto en la lista
			    {
			        if(l.Eliminar()) //Borra el producto
			        	cout << "La lista de productos ha sido actualizada." << endl;
			        else
			        	cout << "El producto no ha sido encontrado." << endl;
			    }
			    else
			         cout << "El producto no ha sido encontrado." << endl;
			         
				break;
				
			case 3: //Muestra la lista en orden directo
			    cout << l << endl;
			    
				break;
				
			case 4: //Muestra la lista en orden inverso
			    cout >> l << endl;
			    
				break;
        }
        
        system("PAUSE");
        system("cls");
	}
	while(op != 5); //Sale del menú cuando el código de operación es 5
	
	
	return 0;
}
