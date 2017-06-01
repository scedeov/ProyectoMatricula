#ifndef ESCUELA
#define ESCUELA

#include <string>

#include "objetoBase.h"

class Contenedor_Cursos;
class contenedorProfesores;

class Escuela/*: public objetoBase*/
{
private:
	std::string nombreEscuela;
	std::string siglaEscuela;
	Contenedor_Cursos* ConC;
	contenedorProfesores* ContP;
public:
	Escuela(std::string);
	~Escuela();
	void setNombre(std::string);
	std::string getNombre();
	void setSiglaEscuela(std::string);
	std::string getSiglaEscuela();
	std::string generaSigla(std::string);
	Contenedor_Cursos* getContenedorCursos();
	contenedorProfesores* getContenedorProfesores();
	std::string toString(char);
};
#endif // !ESCUELA

