
/*******************************************************************/
/* Asignatura: Programacion                                        */
/* Curso 2012-2013                                                 */
/* Practica 2                                                      */
/* Ordenacion de Vectores. Costes                                  */
/*                                                                 */
/* AUTOR: Fernando Barber                                          */
/*                                                                 */
/* PROPOSITO: Medir coste empirico de algoritmos de ordenacion     */
/*                                                                 */
/*******************************************************************/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "vector.h"

using namespace std;

//tamanyo maximo del Vectortor
const int MAX = 10000;

/*
 * Prototipos de las funciones empleadas,
 * implementadas despues de main()
 */
void CrearVectortor(Vector &, unsigned);
void OrdenarInsercion (Vector &, int, int&);
bool VerificarOrden (Vector &, int);
void MostrarResultados (int, int, int, int, double, double, double, ofstream &, ofstream &);
void OrdenarQuicksort(Vector & v, int izq, int der, int & ope);
void OrdenarSeleccion (Vector &, int, int &); 

/*
 * Programa principal
 */
int main ()
{
    //Para comprobar la ordenación, numero de elementos a ordenar = MAX-1
    // (por el centinela)
    //tam = MAX - 1;
    
    
    int i;
    int izq = 0;       //Elemento por el cual comienza el vector
    bool ok; //indica si el Vectortor esta ordenado
    int tam; //numero de elementos a ordenar del Vectortor
    int opera_inser, opera_quick, opera_selec; //contador de asignaciones y comparaciones 
                    //realizadas durante la ordenacion
    clock_t time_ini, time_fin, prueba;
    double time_total_inser, time_total_quick, time_total_selec;
    ofstream t, c;
    
    t.open("tiempo.txt");
    c.open("coste.txt"); 
        
        t << "Talla";
        t.put('\t');
        t << "Insercion";
        t.put('\t');
        t << "Seleccion";
        t.put('\t');
        t << "Quicksort";
        t.put('\n');
        
		c << "Talla";
		c.put('\t');
		c << "Insercion";
		c.put('\t');
		c << "Quicksort";
		c.put('\t');
		c << "Seleccion";
		c.put('\n');
        
    //ordenar el Vectortor v mediante el metodo de Insercion
    for (tam = 9; tam <= 4809; tam += 200)
    {   
        Vector v(tam + 1);
        prueba = time(NULL);
        srand(prueba);
        
        //inicializar contador de operaciones    
        time_ini = clock();
        
        
        opera_inser = 0;
        for (i = 0; i < 100; i++)
        {
            //inicializar contador de operaciones    
            
            // Insertamos valores en el Vectortor
            CrearVectortor (v,tam);
            //cout << v << endl;
            
            //ordenar el Vectortor v mediante el metodo de Inserción
            //cout << "Ordenando ...";

            OrdenarInsercion (v, tam, opera_inser);
            
            //cout << " fin" << endl;
            //cout << v << endl;
    
            //verificar que la ordenacion ha sido correcta
            ok = VerificarOrden (v, tam);
            //mostrar numero de operaciones y coste temporal
            //cout << opera_inser << endl;
        }
        
        
        time_fin = clock();
        
         if ( ok == true )
            {
                time_total_inser = (time_fin - time_ini) / (double)CLOCKS_PER_SEC; 
            }
            else //indicar error
                cout << "Error en la ordenacion" << endl;

        srand(prueba);
        //inicializar contador de operaciones    
        opera_quick = 0;
        time_ini = clock();
        
        for (i = 0; i < 100; i++)
        {    
            
            
            // Insertamos valores en el Vectortor
            CrearVectortor (v,tam);
            //cout << v << endl;
            
            //ordenar el Vectortor v mediante el metodo de Quicksort
            //cout << "Ordenando ...";
            OrdenarQuicksort(v, izq, tam, opera_quick);
           // cout << " fin" << endl;
            //cout << v << endl;
    
        	//verificar que la ordenacion ha sido correcta
            ok = VerificarOrden (v, tam);
            //mostrar numero de operaciones y coste temporal
           
        }
        
        
        
        time_fin = clock();
        
         if ( ok == true )
            {
                time_total_quick = (time_fin - time_ini) / (double)CLOCKS_PER_SEC;
            }
            else //indicar error
                cout << "Error en la ordenacion" << endl;
        

        srand(prueba);
        //inicializar contador de operaciones    
        opera_selec = 0;
        time_ini = clock();
        
        for (i = 0; i < 100; i++)
        {
           //inicializar contador de operaciones    
            
            // Insertamos valores en el Vectortor
            CrearVectortor (v,tam);
            //cout << v << endl;
        
            //ordenar el Vectortor v mediante el metodo de selección
            //cout << "Ordenando ...";
            time_ini = clock();
            OrdenarSeleccion(v, tam, opera_selec);
            time_fin = clock();
            //cout << " fin" << endl;
            //cout << v << endl;
    
        	//verificar que la ordenacion ha sido correcta
            ok = VerificarOrden (v, tam);
            //mostrar numero de operaciones y coste temporal
            
        }
        
        if ( ok == true )
            {
                time_total_selec = (time_fin - time_ini) / (double)CLOCKS_PER_SEC;
            }
            else //indicar error
                cout << "Error en la ordenacion" << endl;
        
        MostrarResultados (tam + 1, opera_inser, opera_quick, opera_selec, time_total_inser, time_total_quick, time_total_selec, t, c);
        
    }
    
    t.close();
	c.close();
	
	
return (0);    
} 

/*************** CrearVectortor *********************************************
 *
 *  Descripcion:  Almacena en el Vectortor v los datos almacenados en el
 *                archivo f
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  v               Vectortor      E/S  Vectortor cuyos elementos se inicializan
 *  tam             unsigned    E    numero de elementos
 *
 *  Valor devuelto:
 *  ninguno
 ************************************************************************/
void CrearVectortor (Vector & v, unsigned tam)
{
    for(unsigned i = 0; i < tam; i++)
        v[i] = rand() % (tam*2);
}


/*************** OrdenarInsercion *********************************************
 *
 *  Descripcion:  Ordena por el metodo Insercion los n primeros
 *                elementos del Vectortor v. Ademas, contabiliza el numero de
 *                asignaciones y comparaciones de elementos del Vectortor que
 *                se realizan.
 * Precondición: Para que se contabilice correctamente el numero de operaciones,
 *              el parametro ope debe estar inicializado a 0 fuera de la funcion
 *               El Vectortor debe tener una posición extra para guardar 
 *              el centinela !!
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  v               Vectortor      E/S  Vectortor cuyos elementos se ordenan
 *  n               int         E    numero de elementos de v que se ordenan
 *  ope             int         E/S  numero de asig. + comp realizadas
 *
 *  Valor devuelto:
 *  ninguno
 *****************************************************************************/
void OrdenarInsercion (Vector & v, int n, int& ope)
{
     //solo se computan operaciones que implican a elementos del Vectortor v
    int i, j;

    for (i = n-2; i>=0; i--)
    {
        v[n] = v[i]; //centinela
        ope++; //una asignacion mas
        j = i+1;
        while ( v[j] < v[n] )
        {
            ope++; //una comparacion mas
            v[j-1] = v[j];
            ope++; //una asignacion mas
            j++;
        }
        ope++; //al salir del bucle una comparacion false
        v[j-1] = v[n];
        ope++; //una asignacion mas
    }
}

/*************** VerificarOrden *********************************************
 *
 *  Descripcion:  Verifica que los n primeros elementos del Vectortor v
 *                estan ordenados (true) o no (false).
 *                El objetivo es comprobar el correcto funcionamiento
 *                del proceso de ordenacion
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  v               Vectortor      E    Vectortor cuyo ordenacion se verifica
 *  n               int         E    numero de elementos de v
 *
 *  Valor devuelto:
 *  bool
 *****************************************************************************/
bool VerificarOrden (Vector & v, int n)
{
    int i;
    bool ordenados = true;
    
    i = 0;
    while ( (i < n - 1) && ordenados )
    {
        if ( v[i] > v[i + 1] )
            ordenados = false;
        i++;
    }

    return ordenados;
}

/*************** MostrarResultados *********************************************
 *
 *  Descripcion:  Muestra el numero de operaciones realizadas para ordenar
 *                  el Vectortor
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  t               TipoOrden   E    tipo de organizacion inicial del Vectortor
 *  a               int         E    numero de asignaciones realizadas
 *  c               int         E    numero de comparaciones realizadas
 *
 *  Valor devuelto:
 *  ninguno
 *****************************************************************************/
void MostrarResultados (int n, int ope_inser, int ope_quick, int ope_selec, double tiempo_inser, double tiempo_quick, double tiempo_selec, ofstream & t, ofstream & c)
{
	if(!t)
	{
		 cout << "Error abriendo el fichero" << endl; 
	}
	else
	{
		//tiempo
		t << fixed << n;
		t.put('\t');
		t << fixed << tiempo_inser / 100.;
		t.put('\t');
		t << fixed << tiempo_quick / 100.;
		t.put('\t');
		t << fixed << tiempo_selec / 100.;
		t.put('\n');
	}
	
	


	if(!c)
	{
		cout << "Error abriendo el fichero" << endl; 
	}
	else
	{
		//coste
		c << fixed << n;	
		c.put('\t');
		c << fixed << ope_inser / 100;
		c.put('\t');
		c << fixed << ope_quick / 100;
		c.put('\t');
		c << fixed << ope_selec / 100;
		c.put('\n');
	}
	
	/*
    cout << endl;
    cout << "Resultados ==> ";
    cout << "n = " << n << endl;
    cout << "   - Operaciones: " << ope_inser << endl;
    cout << "   - Coste en segundos: " << tiempo_inser << endl;
    cout << "-------------------------------------------" << endl;*/
} 


/*************** OrdenarQuicksort *********************************************
 *
 *  Descripcion:  Ordena por el metodo Quicksort los n primeros
 *                elementos del Vectortor v. Ademas, contabiliza el numero de
 *                asignaciones y comparaciones de elementos del Vectortor que
 *                se realizan.
 * Precondición: Para que se contabilice correctamente el numero de operaciones,
 *              el parametro ope debe estar inicializado a 0 fuera de la funcion
 *               El Vectortor debe tener una posición extra para guardar 
 *              el centinela !!
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  v               Vectortor   E/S     Vectortor cuyos elementos se ordenan
 *  izq             int         E       elemento de la izquierda
 *  der             int         E       elemento de la derecha
 *  ope             int         E/S     numero de asig. + comp realizadas
 *
 *  Valor devuelto:
 *  ninguno
 *****************************************************************************/

void OrdenarQuicksort(Vector & v, int izq, int der, int& ope)
{
	int i, j;
	//i(j) recorre desde la izquierda(derecha) el vector
	int aux, piv;
	//asume que v almacena int
	piv = v[(izq + der) / 2];
	//eleccion del pivote (elemento central)
	i = izq;
	j = der;
	
	while (i <= j)
	{
		while (v[i] < piv)
		{
			i++;
			ope++; //una comparacion mas
		}
		
		ope++; //al salir del bucle una comparacion false
		
		while (v[j] > piv)
		{
			ope++; //una comparacion mas
			j--;
		}
			
		ope++; //al salir del bucle una comparacion false
		
		if (i < j)
		{
			ope++; //una comparacion mas
			aux = v[i];
			v[i] = v[j];
			ope++; //una asignacion mas
			v[j] = aux;
			ope++; //una asignacion mas
			i++;
			j--;
		}
		else
		{
			if (i == j)
			{
				i++;
				j--;
			}
		}
	}
		if (izq < j)
			OrdenarQuicksort(v, izq, j, ope);
		if (i < der)
			OrdenarQuicksort(v, i, der, ope);
		
		return;
}



/*************** OrdenarSeleccion *********************************************
 *
 *  Descripcion:  Ordena por el metodo Seleccion los n primeros
 *                elementos del Vectortor v. Ademas, contabiliza el numero de
 *                asignaciones y comparaciones de elementos del Vectortor que
 *                se realizan.
 * Precondición: Para que se contabilice correctamente el numero de operaciones,
 *              el parametro ope debe estar inicializado a 0 fuera de la funcion
 *               El Vectortor debe tener una posición extra para guardar 
 *              el centinela !!
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  v               Vectortor   E/S     Vectortor cuyos elementos se ordenan
 *  n               int         E       numero de elementos del vector
 *  ope             int         E/S     numero de asig. + comp realizadas
 *
 *  Valor devuelto:
 *  ninguno
 *****************************************************************************/
void OrdenarSeleccion (Vector & v, int n, int & ope)
{
    int i, j, pos_min, i_aux;

    for (i = 0; i < n - 1; i++)
    {
        pos_min = i; 
        
        for (j = i + 1; j < n; j++)
        {
            ope++;
            if (v[j] < v[pos_min])
                pos_min = j;
        }
                
        if (pos_min != i)
        {
            i_aux = v[i]; 
            v[i] = v[pos_min];
            v[pos_min] = i_aux;
            ope = ope + 3;
        }
    }
    
return;
}
