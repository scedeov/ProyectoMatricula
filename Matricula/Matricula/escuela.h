#ifndef ESCUELA
#define ESCUELA

#include <iostream>
#include <sstream>
#include <string>

#include "contenedorCursos.h"
#include "contenedorProfesores.h"

using namespace std;

class Escuela
{
private:
	string nombreEscuela;
	string siglaEscuela;
	Contenedor_Cursos* ConC;
	Contenedor_Profesores* ContP;
public:
	Escuela(string);
	~Escuela();
	void setNombre(string);
	string getNombre();
	void setSiglaEscuela(string);
	string getSiglaEscuela();
	string generaSigla(string);
	Contenedor_Cursos* getContenedorCursos();
	Contenedor_Profesores* getContenedorProfesores();
	string toStringEscuela(char);
};
#endif // !ESCUELA

