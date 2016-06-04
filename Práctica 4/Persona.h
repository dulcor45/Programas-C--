#ifndef __PERSONA_H
#define __PERSONA_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Persona
{
    public:
        Persona ();
        Persona (string d, string n, string a1, string a2);
        void AsignarDatos(string dni, string nombre, string apellido1, string apellido2);
        string DevuelveDNI();
        string DevuelveNombre();
        string DevuelveApellido1();
        string DevuelveApellido2();
        friend ostream& operator << (ostream & out, const Persona & p);

    private:
        string dni, nombre, apellido1, apellido2;

};

#endif
