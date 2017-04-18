#ifndef NODO_CURSOS
#define NODO_CURSOS

#include "curso.h"

class Nodo_Cursos
{
private:
	Curso* c;
	Nodo_Cursos* Next;
public:
	Nodo_Cursos(Curso*, Nodo_Cursos*);

	void setCurso(Curso*);
	Curso* getCurso();

	void setNext(Nodo_Cursos*);
	Nodo_Cursos* getNext();

	/*string toStringNodo();*/

	~Nodo_Cursos();
};

#endif // !NODO_CURSOS

