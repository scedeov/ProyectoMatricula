#include "aranceles.h"

float Aranceles::cobroMatricula(Curso *C, Estudiante *E)
{
	float resultado = 0;
	resultado = C->getCantidadCreditos() * costoCredito;
	resultado = resultado + cargosAdministrativos;
	return resultado;
}
