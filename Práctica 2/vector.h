/***************************************************************
* Clase Vector con funcionamiento similar a los arrays de C/C++
* pero con algunas mejoras:
*   - Da error si salimos de rango
*   - Permite dar tamaño en tiempo de ejecución
*   - Permite la asignación de Vectores
*   - Se puede elegir si se pasa por valor (por defecto) o 
*   por referencia (usando &)
*   - Se muestra por pantalla/fichero usando el operador <<
****************************************************************/

#ifndef _VECTOR_H
#define _VECTOR_H

#include<iostream>
using namespace std;

// Clase Vector
class Vector
{
    int * vp;
    unsigned tam;
public:
    Vector(unsigned tamanyo);
    Vector(Vector &v);
    Vector & operator=(Vector &v);
    ~Vector();
    int & operator[](unsigned i);
    friend ostream & operator<<(ostream & out, Vector &v);
};

#endif
