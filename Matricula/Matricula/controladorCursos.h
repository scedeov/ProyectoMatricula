#ifndef CONTROLADORCURSOS
#define CONTROLADORCURSOS

#include "lista.h"
#include <string>

class Curso;
class ControladorCursos
{
private:
	Lista<Curso> *listaCursos;
public:
	ControladorCursos();
	int getCantidad();
	Curso* getCursoporPos(int);
	void insertaInicio(Curso*);
	bool eliminaCursoEspecifico(std::string);
	Curso* retornaCursoEspecifico(std::string);
	std::string toString();
	std::string getCursosProfesorEspecifico(std::string);
	friend std::ostream& operator << (std::ostream&, ControladorCursos&);
	~ControladorCursos();
};
#endif // !CONTENEDOR_CURSOS

