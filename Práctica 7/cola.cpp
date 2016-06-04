#include "cola.h"
using namespace std;

/*************** Cola::Cola () ********************
 *
 *  Descripcion:  Constructor de la cola. Crea el objeto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 ************************************************/
Cola::Cola ()
{
    inicio = NULL;
    fin = NULL;
}

/*************** Cola::~Cola () ********************
 *
 *  Descripcion:  Destructor de la cola. Vacia el objeto.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *
 *  Valor devuelto:
 ************************************************/
Cola::~Cola ()
{
    Vaciar ();
}

/*************** Cola::Cola (const Cola& c) ********************
 *
 *  Descripcion:  Constructor de la funcion Copiar.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *   c               Cola       E/S   Cola a copiar
 *  
 *  Valor devuelto:
 ************************************************/
Cola::Cola (const Cola& c)
{
    Copiar(c);
}

/*************** bool Cola::Encolar (Alumno a) ********************
 *
 *  Descripcion:  Añade un elemento al final de la cola.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *   a               Alumno      E   Alumno a encolar
 *  
 *  Valor devuelto:
 *  Lógico. Dice si la operación se ha realizado con éxito o no.
 ************************************************/
bool Cola::Encolar (Alumno a)
{
    Puntero p_aux;
    bool ok = false;
    
    p_aux = new Nodo;
    p_aux->info = a;
    p_aux->sig = NULL;
    
    if (inicio == NULL)
        inicio = p_aux;
    else
        fin->sig = p_aux;
    
    fin = p_aux;
    
    ok = true;
    
    return ok;
}

/*************** bool Cola::DesEncolar(void) ********************
 *
 *  Descripcion:  Elimina el primer elemento de la cola.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 * 
 *  
 *  Valor devuelto:
 *  Lógico. Dice si la operación se ha realizado con éxito o no.
 ************************************************/
bool Cola::DesEncolar(void)
{
     bool ok;
     Puntero p_aux;

     if (inicio == NULL)
        ok = false;
     else
     {
        p_aux = inicio;
        inicio = inicio->sig;
        
        if (inicio == NULL)
            fin = NULL;
        
        delete p_aux;
        
        ok = true;
    }
    
    return (ok);
}

/*************** int Cola::Elementos (void) ********************
 *
 *  Descripcion:  Devuelve el número de elementos de la cola.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *   
 *  
 *  Valor devuelto:
 *  Entero. Número de elementos de la cola.
 ************************************************/
int Cola::Elementos (void)
{
    Puntero p_aux;
    int n;
    
    n = 0;
    
    if (inicio == NULL)
        cout << "Cola Vacia" << endl;
    else
    {
        p_aux = inicio;
        
        while(p_aux != NULL)
        {
            p_aux = p_aux->sig;
            n++;
        }
    }
    
    return n;
}

/*************** int Cola::Vaciar (void) ********************
 *
 *  Descripcion:  Vacia la cola y cuenta el número de elementos que ha vaciado.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *   
 *  
 *  Valor devuelto:
 *  Entero. Número de elementos eliminados.
 ************************************************/
int Cola::Vaciar()
{
    int i;
    
    i = 0;
    
    while (DesEncolar())
        i ++;
    
    return i;
}

/*************** bool Cola::VerPrimero (Alumno &a) ********************
 *
 *  Descripcion:  Devuelve en a la información del primer alumno de la cola.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *   a              Alumno      E/S   Alumno
 *  
 *  Valor devuelto:
 *  Lógico. Dice si la operación se ha realizado con éxito o no.
 ************************************************/
bool Cola::VerPrimero (Alumno &a)
{
    bool ok;
    
    ok = VerPosicion (0, a);
    
    return ok;
}

/*************** bool Cola::VerUltimo (Alumno &a) ********************
 *
 *  Descripcion:  Devuelve en a la información del último alumno de la cola.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *   a              Alumno      E/S   Alumno
 *  
 *  Valor devuelto:
 *  Lógico. Dice si la operación se ha realizado con éxito o no.
 ************************************************/
bool Cola::VerUltimo (Alumno &a)
{
    bool ok;
    
    ok = VerPosicion (Elementos () - 1, a);
    
    return ok;
}

/*************** void Cola::Mostrar(void) ********************
 *
 *  Descripcion:  Muestra toda la cola por pantalla.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  
 *  
 *  Valor devuelto:
 *  
 ************************************************/
void Cola::Mostrar(void)
{
    Puntero p_aux;
    
    if (inicio == NULL)
        cout << "Cola Vacia" << endl;
    else
    {
        p_aux = inicio;
        
        while(p_aux != NULL)
        {
            cout << p_aux->info;
            p_aux = p_aux->sig;
        }
    }
    
    return;
}

/*************** bool Cola::VerPosicion (int pos, Alumno &a) ********************
 *
 *  Descripcion:  Devuelve en a la información del alumno que esté en la posicion pos de la cola.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *   a              Alumno      E/S   Alumno
 *   pos            int          E    Posición
 *  
 *  Valor devuelto:
 *  Lógico. Dice si la operación se ha realizado con éxito o no.
 ************************************************/
bool Cola::VerPosicion (int pos, Alumno &a)
{
    bool ok;
    Puntero p_aux;
    int i;

    
    if (pos > Elementos() && inicio == NULL)
    {
        cout << "Error" << endl;
        ok = false;
    }
    else
    {
        p_aux = inicio;
        
        
        for(i = 0; i < pos; i++)
        {
        	p_aux->info;
            p_aux = p_aux->sig;
        }
        
        a = p_aux->info;
        
        /*while (p_aux != pos)
        {
            a = p_aux->info;
            p_aux = p_aux->sig;
        }*/
        
        ok = true;
        
    }
    
    return ok;
}

/*************** void Cola::Copiar (const Cola& c) ********************
 *
 *  Descripcion:  Copia la cola c.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *   c               Cola       E/S   Cola a copiar
 *  
 *  Valor devuelto:
 *  
 ************************************************/
void Cola::Copiar (const Cola& c)
{
    Puntero p_aux, dup;
    
    p_aux = c.inicio;
    
    while ( (p_aux != NULL) )
    {
        dup = new Nodo;
        dup->info = p_aux->info;
        dup->sig = NULL;
        
        if (inicio == NULL)
            inicio = dup;
        else
            fin->sig = dup;
            
        fin = dup;
        p_aux = p_aux->sig;
    }
    
    return;
}

/*************** Cola& Cola::operator = (const Cola & c) ********************
 *
 *  Descripcion:  Sobrecarga del operador "=".
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *   c               Cola       E/S   Cola a igualar
 *  
 *  Valor devuelto:
 *  Devuelve el puntero this por ser una funcion miembro.
 ************************************************/
Cola& Cola::operator = (const Cola & c)
{
   if (this != &c) //Comprueba que los dos elementos no sean el mismo
        this->Copiar (c);
        
    return *this;
}









