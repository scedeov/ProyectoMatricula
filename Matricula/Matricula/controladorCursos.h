#ifndef CONTROLADORCURSOS
#define CONTROLADORCURSOS

#include "curso.h"
#include <sstream>
#include <iostream>
#include "lista.h"
using namespace std;

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
	int getProfesores(std::string, int);
	friend std::ostream& operator << (std::ostream&, ControladorCursos&);
	~ControladorCursos();
};
#endif // !CONTENEDOR_CURSOS

