#include "aranceles.h"

float Aranceles::cobroMatricula(Curso *C, Estudiante *E)
{
	float resultado = 0;
	resultado = C->getCantidadCreditos() * costoCredito;
	resultado = resultado + cargosAdministrativos;
	if (E->getNacionalidad())
		resultado = resultado + (resultado * recargoExtranjeros);
	return resultado;
}
