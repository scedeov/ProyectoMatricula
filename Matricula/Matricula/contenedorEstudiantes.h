#ifndef CONTENEDOR_ESTUDIANTES
#define CONTENEDOR_ESTUDIANTES	

#include "estudianteExtranjero.h"
#include "estudianteNacional.h"
#include "lista.h"

class Contenedor_Estudiantes
{
private:
	Lista<Estudiante> *estudiantes;
	friend std::ostream& operator << (std::ostream&, Contenedor_Estudiantes&);
public:
	Contenedor_Estudiantes();
	int getCantidadEstudiantes();
	void insertaInicio(Estudiante*);
	Estudiante* retornaEstudiante(int);
	std::string toString();
	~Contenedor_Estudiantes();
};
#endif // !CONTENEDOR_ESTUDIANTES

