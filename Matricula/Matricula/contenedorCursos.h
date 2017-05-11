#ifndef CONTENEDOR_CURSOS
#define CONTENEDOR_CURSOS	

#include "nodoCursos.h"


class Contenedor_Cursos
{
private:
	Nodo_Cursos *pinicio;
	Nodo_Cursos *paux;
	int cantidad;
	friend ostream& operator << (ostream&, Contenedor_Cursos&);
public:
	Contenedor_Cursos();
	int getCantidad();
	Curso* getCursoporPos(int);
	void insertaInicio(Curso*);
	bool eliminaCursoEspecifico(string);
	Curso* retornaCursoEspecifico(string);
	bool encuentraCurso(Curso*, string);
	string toString();
	int getProfesores(string, int);
	~Contenedor_Cursos();
};
#endif // !CONTENEDOR_CURSOS

