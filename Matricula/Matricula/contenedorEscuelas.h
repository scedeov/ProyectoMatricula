#ifndef CONTENEDOR_ESCUELAS
#define CONTENEDOR_ESCUELAS

#include "nodoEscuelas.h"

class Profesor;


class Contenedor_Escuelas
{
private:
	Nodo_Escuelas* pinicio;
	Nodo_Escuelas* paux;
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

