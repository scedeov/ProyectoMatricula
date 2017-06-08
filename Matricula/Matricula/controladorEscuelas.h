#ifndef CONTENEDOR_ESCUELAS
#define CONTENEDOR_ESCUELAS


#include <sstream>
#include <iostream>
#include "lista.h"
#include "escuela.h"
using namespace std;

class Escuela;
class ControladorEscuelas
{
private:
	Lista<Escuela> *listaEscuelas;
public:
	ControladorEscuelas();
	void insertarInicio(Escuela*);
	Escuela* retornaEscuela(std::string);
	bool encuentraEscuela(Escuela*, std::string);
	Profesor* retornaProfesor(std::string);
	std::string toStringEscuelas();
	std::string toStringConCursos();
	~ControladorEscuelas();
};

#endif // !CONTENEDOR_ESCUELAS

