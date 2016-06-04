/*
*  Implementacion de la clase Lista
*/

#include "Lista.h"

/*************** Lista::Lista() *****************************************
 *
 *  Descripcion:  Constructor por defecto de la clase.
 *					Deja la lista vacía.
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/
 
Lista::Lista()
{
    ini = fin = pto = NULL;
}

/*************** Lista::Lista (const Lista& orig) *****************************************
 *
 *  Descripcion:  Constructor por defecto de la clase.
 *				  Inicializa la lista con una copia de otra.
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  orig		    Lista	     E    Lista a copiar
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/

Lista::Lista (const Lista& orig)
{
    ini = fin = pto = NULL;
    Copiar (orig);
}

/*************** Lista::~Lista () *****************************************
 *
 *  Descripcion:  Destructor por defecto de la clase.
 *					Vacía la lista.
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  ninguno
 *
 *  Valor devuelto:
 *  Ninguno
 ****************************************************************************/
 
Lista::~Lista ()
{
    Vaciar();
}

/*************** const Lista& Lista::operator= (const Lista& orig) *****************************
 *
 *  Descripcion:  Sobrecarga del operador =.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  orig            Lista        E    Lista a copiar
 *
 *  Valor devuelto:
 *  Lista   Devuelve la lista con la copia de la otra
 ****************************************************************************/
 
const Lista& Lista::operator= (const Lista& orig)
{
    Vaciar();
    Copiar (orig);
    return (*this);
}

/*************** void Lista::Insertar (Producto x) *****************************
 *
 *  Descripcion:  inserta un producto en la lista.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  x				Producto	E 		Producto a insertar en la lista
 *
 *  Valor devuelto:
 * 	ninguno
 ****************************************************************************/
 
void Lista::Insertar (Producto x)
{
    Puntero aux;
    
    //Reservar memoria para el nuevo Nodo,
    //pero no asignar valores a los campos porque depende del caso
    aux = new Nodo;
    
    //si el pto es NULL, está más allá del final de la lista:
    //el nuevo Nodo será el último de la lista
    if (pto == NULL)
    {
        aux->info = x;
        aux->sig = NULL;
        
        if (ini == NULL) //si lista vacia
            ini = aux;
        else //ubicar detras del fin
            fin->sig = aux;
            
        fin = aux; //el nuevo siempre es el fin
    }
    //en cualquier otro caso
    else
    {
        *aux = *pto; //copiar info+sig del pto en el nuevo nodo
        
        pto->info = x; //cambiar datos del pto
        pto->sig = aux;
        
        if ( pto == fin ) //caso particular, trasladar fin
            fin = aux;
        
        pto = aux; //el pto sigue apuntando a la misma información
    }
}

/*************** bool Lista::Eliminar () *****************************
 *
 *  Descripcion:  Elimina el producto que se encuentra en el punto de interés.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  Ninguno
 *
 *  Valor devuelto:
 * 	bool	Devuelve si se ha podido eliminar el producto de la lista
 ****************************************************************************/

bool Lista::Eliminar ()
{
    Puntero aux;
    bool ok;
    //error si el pto está más allá del final de la lista
    //esto ocurre también cuando la lista está vacía
    if ( (pto == NULL) )
        ok = false;
    //en cualquier otro caso, se puede eliminar
    else
    {
        ok = true;
        //si pto es el último elemento y no hay nada detrás
        if (pto == fin)
        {
            //además de ser el último también es único elemento
            if (pto == ini)
            {
                delete pto;
                ini = fin = pto = NULL;
            }
            else
            {
                aux = ini;
                //hay que buscar el anterior a fin
                while ( aux->sig != fin )
                    aux = aux->sig;
                    
                fin = aux;
                fin->sig = NULL;
                delete pto;
                pto = NULL;
            }
        }
        //caso en que pto NO es el último elemento
        else
        {
            aux = pto->sig; //guardar el nodo que va a desaparecer
            *pto = *aux; //copiar los datos del nodo en pto
            
            if (aux == fin) //si desaparece el último cambiar fin
                fin = pto;
                
            delete aux; //liberar memoria
        }
    }
    return (ok);
}

/*************** bool Lista::Consultar (Producto & x) *****************************
 *
 *  Descripcion:  Devuelve el producto que se encuentra en el punto de interés.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  x				Producto	S	  El producto que recibimos al realizar la consulta
 *
 *  Valor devuelto:
 * 	bool	Devuelve si se ha podido consultar el producto de la lista
 ****************************************************************************/

bool Lista::Consultar (Producto & x)
{
    bool ok;
    
    if ( pto == NULL )
        ok = false;
    else
    {
        ok = true;
        x = pto->info;
    }
    
    return (ok);
}

/*************** bool Lista::Buscar (string x) *****************************
 *
 *  Descripcion:  Busca un producto con un determinado nombre.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  x				string	     E	  El nombre que queremos buscar en la lista
 *
 *  Valor devuelto:
 * 	bool	Devuelve si se ha encontrado un producto con el mismo nombre
 ****************************************************************************/

bool Lista::Buscar (string x)
{
    bool encontrado = false;
    Producto y;
    
    IrAInicio();
    
    while (!FinalLista() && !encontrado)
    {
        Consultar (y);
        
        if (y.DevuelveNombre() == x)
            encontrado = true;
        else
            Avanzar();
    }
    
    return encontrado;
}

/*************** bool Lista::ListaVacia () *****************************
 *
 *  Descripcion:  Comrpueba si la lista esá vacía.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  Ninguno
 *
 *  Valor devuelto:
 * 	bool	Devuelve si la lista está vacía
 ****************************************************************************/

bool Lista::ListaVacia ()
{
    return (ini == NULL);
}

/*************** void Lista::IrAInicio () *****************************
 *
 *  Descripcion:  Vuelve al inicio de la lista
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  Ninguno
 *
 *  Valor devuelto:
 * 	ninguno
 ****************************************************************************/

void Lista::IrAInicio ()
{
    pto = ini;
}

/*************** bool Lista::Avanzar () *****************************
 *
 *  Descripcion:  Avanza en la lista.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  Ninguno
 *
 *  Valor devuelto:
 * 	bool	Devuelve si se ha podido avanzar en la lista
 ****************************************************************************/
 
bool Lista::Avanzar ()
{
    bool ok;

    if (pto == NULL)
        ok = false; //no se puede avanzar
    else
    {
        ok = true;
        pto = pto->sig;
    }
    
	return (ok);
}

/*************** bool Lista::FinalLista () *****************************
 *
 *  Descripcion:  Comprueba si se ha llegado hasta el final de la lista.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  Ninguno
 *
 *  Valor devuelto:
 * 	bool	Devuelve si se ha llegado al final de la lista
 ****************************************************************************/
 
bool Lista::FinalLista ()
{
    return (pto == NULL);
}

/*************** void Lista::Copiar (const Lista& orig) *****************************
 *
 *  Descripcion:  Copia una lista.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  orig		   Lista	     E		Lista a copiar
 *
 *  Valor devuelto:
 * 	ninguno
 ****************************************************************************/

void Lista::Copiar (const Lista& orig)
{
    Puntero aux, dup;
    aux = orig.ini;
    dup = NULL;

    //se recorre toda la lista orig
    while ( aux != NULL )
    {
        dup = new Nodo; //se crea un nuevo Nodo en cada iteración
        dup->info = aux->info; //copia la información de orig
        dup->sig = NULL; //de momento, éste es el último elemento
        if (ini == NULL) //si la copia está vacia, fijar su inicio
            ini = dup;
        else //detras del fin
            fin->sig = dup;
            
        fin = dup; //siempre es el fin

        if ( aux == orig.pto ) //fijar pto. de interes
            pto = dup;

        aux = aux->sig;
    }
}

/*************** void Lista::Vaciar () *****************************
 *
 *  Descripcion:  Elimina todos los productos de la lista.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  Ninguno
 *
 *  Valor devuelto:
 * 	ninguno
 ****************************************************************************/

void Lista::Vaciar ()
{
    pto = ini;
    while ( Eliminar() );
}

/*************** ostream& operator << (ostream & out, const Lista & l) *****************************
 *
 *  Descripcion:  Sobrecarga del operador salida por pantalla.
 				  Muestra la lista en orden directo.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  out             ostream     E/S   Flujo de datos
 *  l               Lista       E/S   Objeto de la clase lista
 *
 *  Valor devuelto:
 *  ostream 
 ****************************************************************************/

ostream& operator << (ostream & out, const Lista & l)
{
	int i;
	Lista copia;
	
	copia.Copiar (l);
	copia.IrAInicio ();
	
	while(!copia.FinalLista ())
	{
		out << endl << copia.pto->info << " ";
		copia.Avanzar ();
	}

    return out;
}

/*************** ostream& operator >> (ostream & out, const Lista & l) *****************************
 *
 *  Descripcion:  Sobrecarga del operador salida por pantalla.
 				  Muestra la lista en orden inverso.
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  out             ostream     E/S   Flujo de datos
 *  l               Lista       E/S   Objeto de la clase lista
 *
 *  Valor devuelto:
 *  ostream 
 ****************************************************************************/

ostream& operator >> (ostream & out, const Lista & l)
{
	vector<Producto> v;
    int i, n;
    Lista l_aux;
    Producto y;
    
    l_aux = l;
    
    l_aux.IrAInicio();
    
    while (!l_aux.FinalLista())
    {
        l_aux.Consultar (y);
        v.push_back(y);
        l_aux.Avanzar();
    }
    
    n = v.size();
    
    for (i = n - 1; i >= 0; i --)    	
        out << endl <<v[i];
        
    return out;
}
