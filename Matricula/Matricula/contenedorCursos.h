#ifndef CONTENEDOR_CURSOS
#define CONTENEDOR_CURSOS	

#include "nodoCursos.h"


class Contenedor_Cursos
{
private:
	Nodo_Cursos *pinicio;
	Nodo_Cursos *paux;
public:
	Contenedor_Cursos();
	void insertaInicio(Curso*);
	string toString();

	
	~Contenedor_Cursos();
};
#endif // !CONTENEDOR_CURSOS

