/*************** void OrdenarFecha (vector<TipoDato>  &v, int izq, int der)*****
 *
 *  Descripcion:  Plantilla para ordenar libros y revistas por fecha
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

void OrdenarFecha (vector<TipoDato>  &v, int izq, int der)
{
	int i, j;					//i(j) recorre desde la izquierda(derecha) el vector
								//asume que v almacena int	
	TipoDato aux;
	Fecha piv;
	
	piv = v[(izq + der) / 2].ConsultarFecha();

	i = izq;
	j = der;

	while (i <= j)
	{
			
		while (v[i].ConsultarFecha() < piv)
			i++;
					
		while (piv < v[j].ConsultarFecha())
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
	OrdenarFecha (v, izq, j);
	if (i < der)
	OrdenarFecha (v, i, der);

}


