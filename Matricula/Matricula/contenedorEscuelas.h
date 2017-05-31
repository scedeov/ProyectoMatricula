#ifndef CONTENEDOR_ESCUELAS
#define CONTENEDOR_ESCUELAS

#include "contenedores.h"

class Escuela;
class Profesor;

class Contenedor_Escuelas: public adaptadorBase {
private:
	Lista *listaEscuelas;
public:
	Contenedor_Escuelas();
	void agregarInicio(Escuela*);
	Escuela* retornaEscuela(std::string);
	bool encuentraEscuela(Escuela*, std::string);
	Profesor* retornaProfesor(int);
	std::string toString(char);
	~Contenedor_Escuelas();
};

#endif // !CONTENEDOR_ESCUELAS

