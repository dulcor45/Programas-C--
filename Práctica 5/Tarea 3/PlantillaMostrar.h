/*
Plantilla para mostrar los datos de los libros y las revistas.
*/
#include <Vector>
template <class TipoDato>


void Mostrar (vector<TipoDato> v)
{
    unsigned int i;

    cout << "Las publicaciones leidas son:\n";

    for (i = 0; i < v.size (); i++)
    {
    		cout << v[i] << endl;
    }

    return;
}

