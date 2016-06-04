
#ifndef _FECHA_H
#define _FECHA_H

#include <iostream>
using namespace std;

class Fecha
{
    public:
        Fecha ();
        Fecha IniciarFecha (int d, int m, int a);
        friend ostream& operator<< (ostream & out, Fecha fec);
        friend istream& operator>> (istream & in, Fecha & f);
        friend bool operator< (Fecha, Fecha);
    private:
        int dia;
        int mes;
        int anyo;
        int Fecha2Int ();
};

#endif
