#ifndef CONTENEDOR_CURSOS
#define CONTENEDOR_CURSOS	

#include "lista.h"

class Curso;
class ContenedorCursos {
private:
	Lista<Curso> *listaCursos;
public:
	ContenedorCursos();
	int getCantidad();
	Curso* getCurso(int);
	virtual void agregarInicio(Curso*);
	virtual bool eliminarEspecifico(std::string);
	Curso* getCursoEspecifico(std::string);
	bool encuentraCurso(Curso*, std::string);
	virtual std::string toString();
	int getProfesores(std::string, int);
	friend std::ostream& operator << (std::ostream&, ContenedorCursos&);
	~ContenedorCursos();
};
#endif // !CONTENEDOR_CURSOS

