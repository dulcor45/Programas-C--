#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "Persona.h"
using namespace std;


Persona::Persona()
{
    dni = "";
    nombre = "";
    apellido1 = "";
    apellido2 = "";
   
}

Persona::Persona (string d, string n, string a1, string a2)
{
    dni = d; 
    nombre = n; 
    apellido1 = a1; 
    apellido2 = a2; 
}

void Persona::AsignarDatos (string d, string n, string a1, string a2)
{
    dni = d; 
    nombre = n; 
    apellido1 = a1; 
    apellido2 = a2; 
}

string Persona::DevuelveDNI()
{
    return dni;
}

string Persona::DevuelveNombre()
{
    return nombre;
}

string Persona::DevuelveApellido1()
{
    return apellido1;
}

string Persona::DevuelveApellido2()
{
    return apellido2;
}

ostream& operator << (ostream & out, const Persona & p)
{
    out << "DNI: " << p.dni << endl;
    out << "Nombre: " << p.nombre << endl;
    out << "Primer apellido: " << p.apellido1 << endl;
    out << "Segundo apellido: " << p.apellido2 << endl;
   
    return out;
}
