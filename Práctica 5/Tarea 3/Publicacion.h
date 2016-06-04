#ifndef _PUBLICACION_H
#define _PUBLICACION_H

#include <iostream>
#include <string>
using namespace std;
#include "Fecha.h"

class Publicacion
{
    public:
        Publicacion ();
        void IniciarPublicacion (long long cod, string edi, Fecha fec);
        void PonerCodigo (int);
        void PonerEditor (string);
        void PonerFecha (Fecha);
        int ConsultarCodigo (void);
        string ConsultarEditor (void);
        Fecha ConsultarFecha (void);
        friend ostream& operator<< (ostream&, Publicacion);

    protected:
        long long codigo;
        string editor;
        Fecha fecha;
};

#endif
