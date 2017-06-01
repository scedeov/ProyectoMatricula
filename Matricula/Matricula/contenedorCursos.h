#ifndef CONTENEDOR_CURSOS
#define CONTENEDOR_CURSOS	


#include "contenedores.h"

class Curso;
class Contenedor_Cursos {
private:
	Lista<Curso> *listaCursos;
public:
	Contenedor_Cursos();
	int getCantidad();
	Curso* getCurso(int);
	virtual void agregarInicio(Curso*);
	virtual bool eliminarEspecifico(std::string);
	Curso* getCursoEspecifico(std::string);
	bool encuentraCurso(Curso*, std::string);
	virtual std::string toString();
	int getProfesores(std::string, int);
	friend std::ostream& operator << (std::ostream&, Contenedor_Cursos&);
	~Contenedor_Cursos();
};
#endif // !CONTENEDOR_CURSOS

