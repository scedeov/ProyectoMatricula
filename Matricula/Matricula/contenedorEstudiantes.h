#ifndef CONTENEDOR_ESTUDIANTES
#define CONTENEDOR_ESTUDIANTES	

#include "estudianteExtranjero.h"
#include "estudianteNacional.h"


class contenedorEstudiantes
{
private:
	Lista<Estudiante> *estudiantes;
	friend std::ostream& operator << (std::ostream&, contenedorEstudiantes&);
public:
	contenedorEstudiantes();
	int getCantidadEstudiantes();
	void agregarInicio(Estudiante*);
	Estudiante* retornaEstudiante(int);
	std::string toString();
	~contenedorEstudiantes();
};
#endif // !CONTENEDOR_ESTUDIANTES

