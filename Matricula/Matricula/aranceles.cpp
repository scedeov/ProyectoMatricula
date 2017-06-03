#include "aranceles.h"

double Aranceles::cobroMatricula(Curso *C, Estudiante *E)
{
	double resultado = 0;
	resultado =  C->getCantidadCreditos() * costoCredito;
	resultado = resultado + cargosAdministrativos;
	if (E->getEsExtranjero())
		resultado = resultado + (resultado * recargoExtranjeros);
	else
		resultado = resultado - (resultado*(E->getPorcentajeBeca() / 100));
	return resultado;
}
