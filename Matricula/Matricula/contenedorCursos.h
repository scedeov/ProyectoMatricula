#ifndef CONTENEDOR_CURSOS
#define CONTENEDOR_CURSOS	


#include "lista.h"

class Curso;
class Contenedor_Cursos {
private:
	Lista *listaCursos;
public:
	Contenedor_Cursos();
	int getCantidad();
	Curso* getCursoporPos(int);
	void insertaInicio(Curso*);
	bool eliminarEspecifico(std::string);
	Curso* retornaCursoEspecifico(std::string);
	bool encuentraCurso(Curso*, std::string);
	std::string toString();
	int getProfesores(std::string, int);
	friend std::ostream& operator << (std::ostream&, Contenedor_Cursos&);
	~Contenedor_Cursos();
};
#endif // !CONTENEDOR_CURSOS

