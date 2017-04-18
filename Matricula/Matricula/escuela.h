#ifndef ESCUELA
#define ESCUELA

#include <iostream>
#include <sstream>
#include <string>

#include "contenedorCursos.h"

using namespace std;

class Escuela
{
private:
	string nombreEscuela;
	string siglaEscuela;
	Contenedor_Cursos* CC;
public:
	Escuela(string);
	~Escuela();
	void setNombre(string);
	string getNombre();
	void setSiglaEscuela(string);
	string getSiglaEscuela();
	string generaSigla(string);
	void insertarCurso(Curso*);
	Contenedor_Cursos* retornaContenedorCursos();
	Curso* retornaCurso(string);
	string toStringEscuela(char);
};
#endif // !ESCUELA

