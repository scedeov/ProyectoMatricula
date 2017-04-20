#include "aranceles.h"

double Aranceles::cobroMatricula(Curso *C, Estudiante *E)
{
	double resultado = 0;
	resultado =  C->getCantidadCreditos() * costoCredito;
	resultado = resultado + cargosAdministrativos;
	if (E->getNacionalidad())
		resultado =  resultado + (resultado * recargoExtranjeros);
	return resultado;
}
