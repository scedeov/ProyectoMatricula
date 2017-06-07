#ifndef ESCUELA
#define ESCUELA

#include "controladorProfesores.h"
#include "controladorCursos.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

//class ControladorCursos;
//class ControladorProfesores;

class Escuela
{
private:
	ControladorCursos* ConC;
	ControladorProfesores* ContP;
	std::string nombreEscuela;
	std::string siglaEscuela;
public:
	Escuela(std::string);
	~Escuela();
	void setNombre(std::string);
	std::string getNombre();
	void setSiglaEscuela(std::string);
	std::string getSiglaEscuela();
	std::string generaSigla(std::string);
	ControladorCursos* getContenedorCursos();
	ControladorProfesores* getContenedorProfesores();
	std::string toStringEscuela();
	std::string toStringConCursos();
	//tiene que haber un matricular
};
#endif // !ESCUELA

