#ifndef CONTENEDOR_PROFESORES
#define CONTENEDOR_PROFESORES

#include "lista.h"
#include <string>

class Profesor;
class ControladorProfesores {
private:
	Lista<Profesor> *listaProfesores;
public:
	ControladorProfesores();
	void insertaInicio(Profesor*);
	Profesor* retornaProfesor(std::string);
	int contadorProfesores();
	std::string toString();
	friend std::ostream& operator << (std::ostream&, ControladorProfesores&);
	~ControladorProfesores();
};
#endif // !CONTENEDOR_PROFESORES
