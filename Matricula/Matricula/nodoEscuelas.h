#ifndef NODO_ESCUELAS
#define NODO_ESCUELAS

#include "escuela.h"

class Nodo_Escuelas
{
private:
	Escuela* e;
	Nodo_Escuelas* next;
public:
	Nodo_Escuelas(Escuela*, Nodo_Escuelas*);

	void setEscuela(Escuela*);
	Escuela* getEscuela();

	void setNext(Nodo_Escuelas*);
	Nodo_Escuelas* getNext();

	string toStringNodo(char);
	Curso* retornaCurso(string);

	~Nodo_Escuelas();
};
#endif // !NODO_ESCUELAS
