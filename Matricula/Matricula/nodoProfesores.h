#ifndef NODO_PROFESORES
#define NODO_PROFESORES

#include "profesor.h"

class Nodo_Profesores
{
private:
	Profesor* P;
	Nodo_Profesores* Next;
	friend ostream& operator << (ostream&, Nodo_Profesores&);
public:
	Nodo_Profesores(Profesor*, Nodo_Profesores*);
	void setNext(Nodo_Profesores*);
	Nodo_Profesores* getNext();
	void setProfesor(Profesor*);
	Profesor* getProfesor();
	string toStringNodo();
	~Nodo_Profesores();
};
#endif // !NODO_PROFESORES
