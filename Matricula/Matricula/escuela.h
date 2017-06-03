#ifndef ESCUELA
#define ESCUELA

#include <string>
#include "contenedor.h"

//class ContenedorCursos;
//class ContenedorProfesores;

class Escuela {
private:
	std::string nombreEscuela;
	std::string siglaEscuela;
	//ContenedorCursos* ConC;
	//ContenedorProfesores* ContP;
public:
	Escuela(std::string);
	~Escuela();
	void setNombre(std::string);
	std::string getNombre();
	void setSiglaEscuela(std::string);
	std::string getSiglaEscuela();
	std::string generaSigla(std::string);
	//ContenedorCursos* getContenedorCursos();
	//ContenedorProfesores* getContenedorProfesores();
	std::string toString(char);
};
#endif // !ESCUELA

