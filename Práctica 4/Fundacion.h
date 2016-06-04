#ifndef __FUNDACION_H
#define __FUNDACION_H

#include <string>
#include <iostream>
#include <vector>
#include "Persona.h"
using namespace std;



class Fundacion
{
    public:
    	Fundacion();
    	Fundacion(string n, float s);
        bool Ingresar(float);
        bool Retirar(float);
        bool AgregarMiembro(Persona);
        bool DesligarMiembro(string);
        void AsignarNombre(string);
        bool AsignarPresidente(string);
        int BuscarMiembro(string);
        string DevuelveNombre();
        string DevuelvePresidente();
        float DevuelveSaldo();
        friend Fundacion operator + (Fundacion, float);
		friend Fundacion operator + (float, Fundacion);
		friend Fundacion operator - (Fundacion, float);
		friend Fundacion operator - (float, Fundacion);
		friend Fundacion operator + (Fundacion, Persona);
		friend Fundacion operator + (Persona, Fundacion);
		friend Fundacion operator - (Fundacion, string);
		friend Fundacion operator - (string, Fundacion);
		
    private:
        string nombref, presidente;
        vector<Persona> miembros;
        float saldo;
};

#endif

