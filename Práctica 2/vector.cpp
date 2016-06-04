
#include <iostream>
#include <assert.h>
#include "vector.h"
using namespace std;

/**
 Constructor de Vector
 @param tamanyo Tamaño del vector
*/
Vector::Vector(unsigned tamanyo)
{
    tam = tamanyo;
    vp = new int[tam];
}

/**
 Constructor de copia
 @param v Vector a copiar
*/
Vector::Vector(Vector &v)
{
    tam = v.tam;
    vp = new int[tam];
    for(unsigned i=0; i<tam; i++)
        vp[i] = v.vp[i];
}

/**
 Operador asignación
 @param v Vector a asignar a this
*/
Vector & Vector::operator=(Vector &v)
{
    delete vp;

    tam = v.tam;
    vp = new int[tam];
    for(unsigned i=0; i<tam; i++)
        vp[i] = v.vp[i];
    return v;
}

/**
 Destructor
*/
Vector::~Vector()
{
    delete vp;
}

/**
 Operador de indexación
 @param i Indice
 @return Valor en la posición i
*/
int & Vector::operator[](unsigned i)
{
    assert(i >= 0 && i < tam);
    return vp[i];
}

/**
 Sobrecarga del operador de salida
 @param out Flujo de salida
 @param v Vector a imprimir
 @return Flujo de salida
*/
ostream & operator<<(ostream & out, Vector &v)
{
    for(unsigned i=0; i<v.tam; i++)
        out << v[i] << " ";
        
    return out;
}
