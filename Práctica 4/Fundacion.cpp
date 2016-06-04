#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#include "Fundacion.h"
#include "Persona.h"
using namespace std;

Fundacion::Fundacion()
{
    nombref = "";
    presidente = "";
    saldo = 0;
}

Fundacion::Fundacion(string n, float s)
{
    nombref = n;
    saldo = s;
}


bool Fundacion::Ingresar(float eur)
{
    bool ok = false; 
    
    if (eur > 0)
        ok = true;
        
    saldo += eur;
    
    return ok; 
}

bool Fundacion::Retirar(float eur)
{
    bool ok = false; 
    
    if (eur > 0)
        ok = true;
        
    saldo -= eur;
    
    return ok;
}

bool Fundacion::AgregarMiembro(Persona p)
{
    bool existe = true;
    int pos;
    string d;
    
    d = p.DevuelveDNI();

    pos = BuscarMiembro(d);
    if (pos != -1)
        existe = false;
    else
        miembros.push_back(p);
    
    return existe;
}

bool Fundacion::DesligarMiembro(string d)
{
    bool existe = false;
    int pos;
    
    pos = BuscarMiembro(d);
    if(pos != -1)
    {
        existe = true;
        miembros[pos] = miembros[miembros.size() - 1];
        miembros.pop_back();
    }    
    return existe;
}


int Fundacion::BuscarMiembro(string d)
{
    int pos, i, tamanyo;
    string member;
    pos = -1;
    tamanyo = miembros.size();
    
    for(i = 0; i < tamanyo && pos == -1; i++)
    {
        if (d == miembros[i].DevuelveDNI())
        {
        	 pos = i;
        	 member = miembros[i].DevuelveNombre();
        	 cout << miembros[i];
        }
           
    }
    
    
    return pos;
}

void Fundacion::AsignarNombre(string n)
{
	nombref = n;
}

bool Fundacion::AsignarPresidente(string d)
{
	int pos;
	bool encontrado = false;
	pos = BuscarMiembro(d);
	
	if(pos != -1)
	{
		presidente = miembros[pos].DevuelveDNI();
		encontrado = true;
	}
	return encontrado;
}

string Fundacion::DevuelveNombre()
{
	return nombref; 
}

string Fundacion::DevuelvePresidente()
{
	return presidente;
}

float Fundacion::DevuelveSaldo()
{
	return saldo;
}

Fundacion operator + (Fundacion f, float eur)
{
    f.saldo += eur;
    return f;
}

Fundacion operator + (float eur, Fundacion f)
{
    f.saldo += eur;
    return f;
}

Fundacion operator - (Fundacion f, float eur)
{
    f.saldo -= eur;
    return f;
}

Fundacion operator - (float eur, Fundacion f)
{
    f.saldo -= eur;
    return f;
}

Fundacion operator + (Fundacion f, Persona p)
{
	int pos;
	string d;
	
	d = p.DevuelveDNI();
	pos = f.BuscarMiembro(d);
    
    if (pos == -1)
    	 f.miembros.push_back(p);

    return f;
}

Fundacion operator + (Persona p, Fundacion f)
{
	int pos;
	string d;
	
	d = p.DevuelveDNI();
	pos = f.BuscarMiembro(d);
    
    if (pos == -1)
    	 f.miembros.push_back(p);

    return f;
}

Fundacion operator - (Fundacion f, string d)
{
	f.DesligarMiembro(d);
    return f;
}

Fundacion operator - (string d, Fundacion f)
{
	f.DesligarMiembro(d);
    return f;
}


