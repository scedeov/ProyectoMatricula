#ifndef ARANCELES
#define ARANCELES

#include "curso.h"
#include "estudiante.h"

class Aranceles
{
private:
	const int costoCredito = 10000;
	const int cargosAdministrativos = 15000;
	const double recargoExtranjeros = 0.40;
public:
	double cobroMatricula(Curso*, Estudiante*);

};
#endif // !ARANCELES
