/************************** FRACTION.CPP ************************************/
/*              Implementación de la clase para Fracciones                  */
/****************************************************************************/

#include <iostream>
#include <cmath>
#include "fraccion.h"
using namespace std;
/*************** Fraccion ***************************************************/
/*                                                                          */
/*  Descripción: Constructor por defecto de la clase Fracción               */
/*               Inicializa el numerador a 0 y el denominador a 1           */
/*                                                                          */
/*  Parámetros: Ninguno                                                     */
/*  Valor devuelto: Ninguno                                                 */
/****************************************************************************/
Fraccion::Fraccion()
:num(0), den(1)
{}

Fraccion::Fraccion (int n, int d)
{
	if (d == 0)
	cerr << "Error en Fraccion: denominador es 0\n";
	else
	if (n == 0)
	{
		num = 0;
		den = 1;
	}
	else
	{
		num = n;
		den = d;
	}
}

int Fraccion::ObtenNum() const
{
	return num;
}

int Fraccion::ObtenDen() const
{
	return den;
}
void Fraccion::PonNum(int n)
{
	num = n;
}

void Fraccion::PonDen(int d)
{
	if (d==0)
	cerr << "Error en Fraccion: denominador es 0\n";
	else
	den = d;
}


/***************** operator+ ************************************************/
/*                                                                          */
/*  Descripción:  Función miembro de sobrecarga del operador "+" para        */
/*                sumar fracciones.                                         */
/*                                                                          */
/*  Parámetros:                                                             */
/*  Nombre          Tipo        E/S  Descripcion                            */
/*  ------          ----------  ---  ------------                           */
/*  f               Fraccion     E    Fraccion a sumar                      */
/*                                                                          */
/*  Valor devuelto: Fraccion resultado de la suma                           */
/****************************************************************************/
Fraccion operator+ (const Fraccion & f1, const Fraccion & f2)
{
	Fraccion r;
	
    if (f1.num == 0) 
        r = f2;
    else
        if (f2.num == 0)
		    r = f1;
		else 
	    {
            r.num = (f1.num * f2.den) + (f1.den * f2.num);
            r.den = f1.den * f2.den;
        }
      
    return r;
}

Fraccion operator- (const Fraccion & f1, const Fraccion & f2)
{
	Fraccion r;
	
    if (f1.num == 0) 
        r = f2;
    else
        if (f2.num == 0)
		    r = f1;
		else 
	    {
            r.num = (f1.num * f2.den) - (f1.den * f2.num);
            r.den = f1.den * f2.den;
        }
      
    return r;
}

bool operator== (const Fraccion & f1, const Fraccion & f2)
{
	Fraccion r;
	bool igual = false;
	
	if (f1.num == f2.num && f1.den == f2.den)
		igual = true;
	
    return igual;
}

ostream& operator << (ostream & out, const Fraccion & f)
{
	out << f.num;
	out << "/";
	out << f.den;
	
	return out;
}

istream& operator >> (istream & in, Fraccion & f)
{
	char c;
	
	in >> f.num;
	in >> c;
	in >> f.den;
	
	return in;
}

/***************** Leer *****************************************************/
/*                                                                          */
/*  Descripción:  Función miembro para leer una fracción de la entrada      */
/*                estándar en la forma "num/denom".                         */
/*                Comprueba que el denominador no sea 0.                    */
/*                                                                          */
/*  Parámetros: Ninguno                                                     */
/*  Valor devuelto: Ninguno                                                 */
/****************************************************************************/
void Fraccion::Leer()
{
    char Signo;   // utilizado para guardar '/' durante la lectura.
    int n, d;

    cin >> n >> Signo >> d;
    if (d==0)
        cerr << "Error en Fraccion: denominador es 0\n";
    else
        if (n==0) 
        { 
            num = 0; 
            den = 1; 
        }
        else
        {
            num = n;
            den = d; 
        }
}

/***************** Escribir *************************************************/
/*                                                                          */
/*  Descripción:  Funcion miembro que muestra por pantalla una fracción en  */
/*                la forma "num/denom."                                     */
/*                                                                          */
/*  Parámetros: Ninguno                                                     */
/*  Valor devuelto: Ninguno                                                 */
/****************************************************************************/
void Fraccion::Escribir() const
{
    cout << "\n" << num << '/' << den << "\n";
}

/***************** Evaluar **************************************************/
/*                                                                          */
/*  Descripción:  Funcion miembro que calcula el resultado de dividir       */
/*                el numerador por el denominador                           */
/*                                                                          */
/*  Parámetros: Ninguno                                                     */
/*  Valor devuelto: Double, resultado de la división                        */
/****************************************************************************/
double Fraccion::Evaluar() const
{ 
    return ((double) num / (double) den);
}

void Fraccion::Simplifica()
{
	int m;
	
	m = mcd(abs(num), abs(den));
	
	if (m != 1)
	{
		num = num / m;
		den = den / m;
	}
}

int Fraccion::mcd (int a, int b)
{
	int min;
	
	if (b == 0)
		min = a;
	else
		min = mcd(b, a % b);
	
	return min;
}


Fraccion operator+ (const Fraccion & f1, int n)
{
	Fraccion res;
	
    res.num = f1.num + (n*f1.den);
    res.den = f1.den;
      
    return res;
}


Fraccion operator+ (int n, const Fraccion & f1)
{
	Fraccion res;
	
    res.num = f1.num + (n*f1.den);
    res.den = f1.den;
      
    return res;
}





