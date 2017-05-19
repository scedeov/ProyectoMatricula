#ifndef CONTENEDOR_CURSOS
#define CONTENEDOR_CURSOS	

#include "nodoCursos.h"

class Contenedor_Cursos
{
private:
	Nodo_Cursos *pinicio;
	Nodo_Cursos *paux;
	int cantidad;
	friend std::ostream& operator << (std::ostream&, Contenedor_Cursos&);
public:
	Contenedor_Cursos();
	int getCantidad();
	Curso* getCursoporPos(int);
	void insertaInicio(Curso*);
	bool eliminaCursoEspecifico(std::string);
	Curso* retornaCursoEspecifico(std::string);
	bool encuentraCurso(Curso*, std::string);
	std::string toString();
	int getProfesores(std::string, int);
	~Contenedor_Cursos();
};
#endif // !CONTENEDOR_CURSOS

