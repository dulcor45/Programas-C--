/*************** void OrdenarTitulo (vector<TipoDato>  &v, int izq, int der)*****
 *
 *  Descripcion:  Plantilla para ordenar libros y revistas por título
 *
 *  Parametros:
 *  Nombre          Tipo        E/S  Descripcion
 *  ------          ----------  ---  ------------
 *  v          vector<TipoDato>   E    vector de libros o revistas
 *  izq               int         E    inicio del vector
 *  der               int         E    final del vector
 *
 *  Valor devuelto:
 *  ninguno
 *****************************************************************************/


template <class TipoDato>

void OrdenarTitulo (vector<TipoDato>  &v, int izq, int der)
{
	int i, j;					//i(j) recorre desde la izquierda(derecha) el vector
								//asume que v almacena int	
	TipoDato aux;
	string piv;
	
	piv = v[(izq + der) / 2].ConsultarTitulo();

	i = izq;
	j = der;

	while (i <= j)
	{
			
		while (v[i].ConsultarTitulo() < piv)
			i++;
					
		while (v[j].ConsultarTitulo() > piv)
			j--;
			
		if (i < j)
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
		else
			if (i == j)
			{
				i++;
				j--;
			}
	}
	
	if (izq < j)
	OrdenarTitulo (v, izq, j);
	if (i < der)
	OrdenarTitulo (v, i, der);

}




