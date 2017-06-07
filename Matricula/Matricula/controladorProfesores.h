#ifndef CONTENEDOR_PROFESORES
#define CONTENEDOR_PROFESORES

#include "profesor.h"
#include <sstream>
#include <iostream>
#include "lista.h"

using namespace std;

class ControladorProfesores
{
private:
	Lista<Profesor> *listaProfesores;
public:
	ControladorProfesores();
	void insertaInicio(Profesor*);
	Profesor* retornaProfesor(string);
	int contadorProfesores();
	std::string toString();
	friend std::ostream& operator << (std::ostream&, ControladorProfesores&);
	~ControladorProfesores();
};
#endif // !CONTENEDOR_PROFESORES
