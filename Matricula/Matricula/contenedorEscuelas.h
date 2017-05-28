#ifndef CONTENEDOR_ESCUELAS
#define CONTENEDOR_ESCUELAS

#include "escuela.h"
#include "lista.h"

class Profesor;

class Contenedor_Escuelas
{
private:
	Lista<Escuela> *listaEscuelas;
public:
	Contenedor_Escuelas();
	void insertarInicio(Escuela*);
	Escuela* retornaEscuela(std::string);
	bool encuentraEscuela(Escuela*, std::string);
	Profesor* retornaProfesor(int);
	std::string toString(char);
	~Contenedor_Escuelas();
};

#endif // !CONTENEDOR_ESCUELAS

