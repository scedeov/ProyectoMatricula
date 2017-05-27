#ifndef CONTENEDOR_CURSOS
#define CONTENEDOR_CURSOS	

#include "curso.h"
#include "lista.h"
class Contenedor_Cursos
{
private:
	Lista<Curso> *listaCursos;
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
	friend std::ostream& operator << (std::ostream&, Contenedor_Cursos&);
	~Contenedor_Cursos();
};
#endif // !CONTENEDOR_CURSOS

