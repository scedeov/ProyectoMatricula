#ifndef CONTENEDOR_ESCUELAS
#define CONTENEDOR_ESCUELAS

#include "lista.h"
//class Profesor;


class Escuela;
class ControladorEscuelas
{
private:
	Lista<Escuela> *listaEscuelas;
	/*Nodo_Escuelas* pinicio;
	Nodo_Escuelas* paux;*/
public:
	ControladorEscuelas();
	void insertarInicio(Escuela*);
	Escuela* retornaEscuela(std::string);
	bool encuentraEscuela(Escuela*, std::string);
	//Profesor* retornaProfesor(int);
	std::string toStringEscuelas();
	std::string toStringConCursos();
	~ControladorEscuelas();
};

#endif // !CONTENEDOR_ESCUELAS

