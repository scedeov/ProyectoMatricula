#ifndef CONTENEDOR_ESTUDIANTES
#define CONTENEDOR_ESTUDIANTES	

#include "lista.h"
#include <string>

class Estudiante;
class ControladorEstudiantes {
private:
	Lista<Estudiante> *listaEstudiantes;
public:
	ControladorEstudiantes();
	int getCantidadEstudiantes();
	void insertaInicio(Estudiante*);
	Estudiante* retornaEstudiante(std::string);
	std::string toString();
	friend std::ostream& operator << (std::ostream&, ControladorEstudiantes&);
	~ControladorEstudiantes();
};
#endif // !CONTENEDOR_ESTUDIANTES

