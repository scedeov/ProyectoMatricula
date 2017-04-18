#ifndef ARANCELES
#define ARANCELES


class Aranceles
{
private:
	const int costoCredito = 10000;
	const int cargosAdministrativos = 15000;
	const int recargoExtranjeros = 0.40;
public:
	float cobroMatricula(Curso*, Estudiante*);

};
#endif // !ARANCELES
