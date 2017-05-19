#ifndef CONTENEDOR_ESTUDIANTES
#define CONTENEDOR_ESTUDIANTES	

#include "nodoEstudiantes.h"

class Contenedor_Estudiantes
{
private:
	Nodo_Estudiantes *pinicio;
	Nodo_Estudiantes *paux;
	friend std::ostream& operator << (std::ostream&, Contenedor_Estudiantes&);
public:
	Contenedor_Estudiantes();
	void insertaInicio(Estudiante*);
	Estudiante* retornaEstudiante(int);
	std::string toString();
	~Contenedor_Estudiantes();
};
#endif // !CONTENEDOR_ESTUDIANTES

