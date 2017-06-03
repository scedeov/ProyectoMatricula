#include "aranceles.h"
#include "curso.h"
#include "estudianteExtranjero.h"

double Aranceles::cobroMatricula(Curso *C, Estudiante *E)
{
	double resultado = 0;
	resultado =  C->getCantidadCreditos() * costoCredito;
	resultado = resultado + cargosAdministrativos;
	if (dynamic_cast<Estudiante_Extranjero*>(E))
		resultado =  resultado + (resultado * recargoExtranjeros);
	return resultado;
}
