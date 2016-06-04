
/*******************************************************************/
/* Asignatura: Programacion. Grado Ing. Inform?tica/Multimedia     */
/* Curso 2012-2013                                                 */
/* Laboratorio. Práctica 1                                         */
/* Busqueda en vectores                                            */
/*                                                                 */
/* AUTOR: Jesus Albert, Elena Diaz, Jose F. Garcia, F. Barber      */
/*                                                                 */
/* PROPOSITO: Medir coste empirico de algoritmos de busqueda       */
/*                                                                 */
/*******************************************************************/

#include <iostream>
#include<stdlib.h>
#include <time.h>

using namespace std;

//tamanyo maximo del vector
const int MAX = 100000;

//tipo para el vector
typedef int Vector[MAX];

/*
 * Prototipos de las funciones empleadas,
 * implementadas despues de main()
 */
void CrearVector (Vector, int);
void MostrarResultados (int[], int, int&, float); 
bool BusquedaSecuencial (Vector, int, int, int&);
bool BusquedaSecuencialParada (Vector, int, int, int&);
bool BusquedaSecuencialCentinela (Vector, int, int, int&);
bool BusquedaBinaria (Vector, int, int, int&);
void RealizarBusqueda (int, Vector, int, int, int[], int&);

/*
 * Programa principal
 */
int main ()
{
    //vector sobre el que se busca
    Vector v;
    //Vector de los tamaños
    Vector u;
    //Cantidad de tamaños a comprobar;
    int cant_tam = 5;
    //numero de elementos del vector
    int tam; 
    //el dato a buscar
    int x; 
    //contadores del total de operaciones, 1 x algoritmo
    int total[4]; 
	//Porcentaje de búsquedas realizadas con éxito
	int exito;
	//Declaraciones para medir el tiempo
	clock_t ini_time, fin_time;
	float time_total;

    //Tamaño de los vectores a analizar
    u[0] = 10;
    u[1] = 100;
    u[2] = 1000;
    u[3] = 10000;
    u[4] = 50000;
    
	srand ( time(NULL) );

	//leer el tamanyo del vector
	/*cout << "Numero de elementos en el vector (max. " << MAX << ")? ";
	cin >> tam;*/
	
	for(int j = 0; j < cant_tam; j++)
	{
		//Inicializacion del reloj
		ini_time = clock();
		
		tam = u[j];
		exito = 0;
		//poner contadores a cero
		for (int i=0; i < 4; i++)
		{
			total[i] = 0;
		}
			 
		//crear los elementos de un vector 'v' de 'tam' posiciones
		CrearVector (v, tam);
		
		for (int k = 0; k < 1000; k++)
		{    
			//generar aleatoriamente el valor a buscar entre 0 y tam*2
			//como v contiene solo los valores pares, hay un 50% de probabilidades
			//de generar un valor que este en el vector
			x = rand() % (tam*2);
			cout << "Elemento a buscar: " << x << endl;
			
			
			//buscar  x el vector v mediante los 4 metodos
			//alg=0: Busqueda Secuencial
			//alg=1: Busqueda Secuencial con Parada
			//alg=2: Busqueda Secuencial con Centinela
			//alg=3: Busqueda Binaria
			for (int alg = 0; alg < 4; alg++)
			{
				RealizarBusqueda (alg, v, tam, x, total, exito);
			}
		}
		
		fin_time = clock();
		time_total = (fin_time - ini_time) / (float) CLOCKS_PER_SEC;
		MostrarResultados (total, tam, exito, time_total);
		
	
		system("pause");
	}
   
    system ("PAUSE");
    return (0);    
} 

/*************** CrearVector *********************************************
 *
 *  Prototipo:    void CrearVector (Vector v, int n)
 *
 *  Descripcion:  Inicializa los n primeros elementos del vector v
 *                de forma ordenada con enteros pares
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  v               Vector      E/S  vector cuyos elementos se inicializan
 *  n               int         E    numero de elementos de v a inicializar
 *
 *  Valor devuelto:
 *  ninguno
 ************************************************************************/
void CrearVector (Vector v, int n)
{
    int i;

    for ( i = 0; i < n; i++ )
        v[i] = i*2;
}

/*************** MostrarResultados *********************************************
 *
 *  Prototipo:    void MostrarResultados (int t[])
 *
 *  Descripcion:  Muestra el numero de operaciones realizadas por cada algoritmo
 *                para buscar en el vector
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  t               int[]       E    numero de operaciones realizadas x algoritmo
 *
 *  Valor devuelto:
 *  ninguno
 *****************************************************************************/
void MostrarResultados (int t[], int tam, int& exito, float time_total)
{
	
	int tam_total = 0;
	
	for(int i = 0; i < 4; i ++)
	    tam_total += t[i];
	
	/*cout << ".........................................." << tam_total << endl;
	cout << "??????????????????????????????????????????" << endl;*/
    //Calculamos las medias
	float media_sec = t[0] / 1000.0;
    float media_sec_par = t[1] / 1000.0;
    float media_sec_cent = t[2] / 1000.0;
    float media_bin = t[3] / 1000.0;
	
	
	//Calculamos los tiempos de ejecución
    float tiempo_sec = (time_total * t[0]) / (tam_total);
	float tiempo_sec_par = (time_total * t[1]) / (tam_total);
	float tiempo_sec_cent = (time_total * t[2]) / (tam_total);
	float tiempo_bin = (time_total * t[3]) / (tam_total);
	
	
	//Calculamos los porcentajes de búsquedas con éxito
	float porc;
	
	porc = (exito / 4000.0 ) * 100;

    cout << endl;
    cout << "Resultados" << endl;
    cout << "-------------------------------------------" << endl;
    
    cout << "Busqueda Secuencial:" <<endl;
    cout << "\tTotal op. = " << t[0] << endl;
    cout << "Media Busqueda Secuencial = " << media_sec << endl;
    cout << "Tiempo de ejecucion por algoritmo: = " << tiempo_sec << " s" << endl;
    
    cout << "Busqueda Secuencial con Parada:" <<endl;
    cout << "\tTotal op.= " << t[1] << endl;
    cout << "Media Busqueda Secuencial con Parada = " << media_sec_par << endl;
    cout << "Tiempo de ejecucion por algoritmo: = " << tiempo_sec_par << " s" << endl;

    cout << "Busqueda Secuencial con Centinela:" <<endl;
    cout << "\tTotal op.= " << t[2] << endl;
    cout << "Media Busqueda Secuencial con Centinela = " << media_sec_cent << endl;
    cout << "Tiempo de ejecucion por algoritmo: = " << tiempo_sec_cent << " s" << endl;
    
    cout << "Busqueda Binaria:" <<endl;
    cout << "\tTotal op.= " << t[3] << endl;
    cout << "Media Busqueda binaria = " << media_bin << endl;
    cout << "Tiempo de ejecucion por algoritmo: = " << tiempo_bin << " s" << endl;
    
    cout << "Porcentaje de busquedas realizadas con exito: " << porc << " %" << endl;
    cout << "Tamanyo del vector sobre el que hemos buscado: " << tam << endl; //muestra el tamaño del vector

    cout << "-------------------------------------------" << endl;
}

/*************** BusquedaSecuencial *************************************
 *
 *  Prototipo:    bool BusquedaSecuencial (Vector v, int n, int x, int& total)
 *
 *  Descripcion:  Implementa el metodo de busqueda secuencial (sin parada):
 *                busca 'x' en los 'n' primeros elementos de 'v'
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  v               Vector      E    vector sobre el que se busca
 *  n               int         E    numero de elementos de v
 *  x               int         E    dato a buscar
 *  pasos           int         E/S  numero total de pasos realizados
 *
 *  Valor devuelto:
 *  bool, true si se localiza el dato 'x', false en caso contrario
 ************************************************************************/
bool BusquedaSecuencial (Vector v, int n, int x, int& pasos)
{
    int i;
    bool enc = false;

    i = 0;

    //contabilizar las 2 asignaciones anteriores
    pasos += 2; 

    while (i < n)
    {
        if (v[i] == x)
        {
            enc = true;
            //contabilizar la asignacion
            pasos++;
        }
        //contabilizar la comparacion del vector del if
        pasos++;
        i++;
        //contabilizar la comparacion del while y el incr. de i
        pasos += 2;
    }

    //contabilizar la comp. de salida del while
    pasos++;

    return enc;
}

/*************** BusquedaSecuencialParada *********************************
 *
 *  Prototipo:    bool BusquedaSecuencialParada (Vector v, int n, int x, int& total)
 *
 *  Descripcion:  Implementa el metodo de busqueda secuencial (con parada):
 *                busca 'x' en los 'n' primeros elementos de 'v'
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  v               Vector      E    vector sobre el que se busca
 *  n               int         E    numero de elementos de v
 *  x               int         E    dato a buscar
 *  pasos           int         E/S  numero total de operaciones realizadas
 *
 *  Valor devuelto:
 *  bool, true si se localiza el dato 'x', false en caso contrario
 ************************************************************************/
bool BusquedaSecuencialParada (Vector v, int n, int x, int& pasos)
{
    int i;                                                 
    bool enc;                                             

    i = 0;
    
    pasos += 1;
    
    while ( (i < n) && (v[i] != x) )
    {
        i++;
        pasos = pasos + 5; //comparaciones
    }

    if (i == n)
    {
        enc = false;
        pasos++;
    }
    else
    {
        enc = true;
        pasos++;
    }
    
    //contabilizar la comp. de salida del while
    pasos++;
    pasos++; //comparación del if

    return enc;
}

/*************** BusquedaSecuencialCentinela *******************************
 *
 *  Prototipo:    bool BusquedaSecuencialCentinela (Vector v, int n, int x, int& total)
 *
 *  Descripcion:  Implementa el metodo de busqueda secuencial con centinela:
 *                busca 'x' en los 'n' primeros elementos de 'v'
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  v               Vector      E    vector sobre el que se busca
 *  n               int         E    numero de elementos de v
 *  x               int         E    dato a buscar
 *  pasos           int         E/S  numero total de operaciones realizadas
 *
 *  Valor devuelto:
 *  bool, true si se localiza el dato 'x', false en caso contrario
 ************************************************************************/
bool BusquedaSecuencialCentinela (Vector v, int n, int x, int& pasos)
{
    int i;                                                 
    bool enc;                                             

    v[n] = x;
    i = 0;
    
    pasos += 2; 
    
    while ( v[i] != x )
    {
        i++;
        pasos = pasos + 2;
    }

    if (i == n)
    {
        enc = false;
        pasos++;
    }
    else
    {
        enc = true;
        pasos++;
    }

    //contabilizar la comp. de salida del while
    pasos++;
    
    pasos++; //comparacion del if
    
    return enc;
}

/*************** BusquedaBinaria *************************************
 *
 *  Prototipo:    bool BusquedaBinaria (Vector v, int n, int x, int& total)
 *
 *  Descripcion:  Implementa el metodo de busqueda binaria:
 *                busca 'x' en los 'n' primeros elementos de 'v'
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  v               Vector      E    vector sobre el que se busca
 *  n               int         E    numero de elementos de v
 *  x               int         E    dato a buscar
 *  pasos           int         E/S  numero total de operaciones realizadas
 *
 *  Valor devuelto:
 *  bool, true si se localiza el dato 'x', false en caso contrario
 ************************************************************************/
bool BusquedaBinaria (Vector v, int n, int x, int& pasos)
{
    int izq, der, cen;
    bool enc = false;
    izq = 0;
    der = n - 1;
    cen = (izq + der) / 2;
    
    pasos += 7;

    while ( (izq <= der) && (v[cen] != x) )
    {
        if (x < v[cen])
        {
            der = cen - 1;
            pasos = pasos + 2;
        }
        else
        {
            izq = cen + 1;
            pasos = pasos + 2;
        }
        pasos++; //comparacion del if
        cen = (izq + der) / 2;
        pasos = pasos + 3;
    }
    
    if (izq > der)
    {
        enc = false;
        pasos++;
    }
    else
    {
        enc = true;
        pasos++;
	}
    
    pasos++; //comparacion del if
    //contabilizar la comp. de salida del while
    pasos++;
       
    return enc;
}

/*************** RealizarBusqueda *************************************
 *
 *  Prototipo:    void RealizarBusqueda (int alg, Vector v, int n, int x, int total[])
 *
 *  Descripcion:  Permite seleccionar el algoritmo de busqueda emplear para:
 *                busca 'x' en los 'n' primeros elementos de 'v'
 *                alg=0: Busqueda Secuencial
 *                alg=1: Busqueda Secuencial con Parada
 *                alg=2: Busqueda Secuencial con Centinela
 *                alg=3: Busqueda Binaria
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  alg             int         E    identificador de algoritmo a emplear
 *  v               Vector      E    vector sobre el que se busca
 *  n               int         E    numero de elementos de v
 *  x               int         E    dato a buscar
 *  total           int[]       E/S  numero total de operaciones realizadas
 *
 *  Valor devuelto:
 *  Ninguno
 ************************************************************************/
void RealizarBusqueda (int alg, Vector v, int n, int x, int total[], int& exito)
{
    bool ok = false;
    
    cout << "Buscando ...";
    switch (alg)
    {
        case 0:
            ok = BusquedaSecuencial (v, n, x, total[0]);
            break;
        case 1:
            ok = BusquedaSecuencialParada (v, n, x, total[1]);
            break;
        case 2:
            ok = BusquedaSecuencialCentinela (v, n, x, total[2]);
            break;
        case 3:
            ok = BusquedaBinaria (v, n, x, total[3]);
            break;
    }
    
    if (ok)
	{    
        cout << " Encontrado" << endl;
		exito++;
	}
    else 
        cout << " NO encontrado" << endl;
}
