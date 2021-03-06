#include "aranceles.h"

double Aranceles::cobroMatricula(Curso *C, Estudiante *E)
{
	double resultado = 0;
	double reduccionBeca = 0;
	resultado =  C->getCantidadCreditos() * costoCredito;
	resultado = resultado + cargosAdministrativos;
	if (E->getEsExtranjero())
		resultado = resultado + (resultado * recargoExtranjeros);
	else {
		reduccionBeca = (double) E->getPorcentajeBeca() / 100;
		resultado = resultado - (resultado*reduccionBeca);
	}
	return resultado;
}
