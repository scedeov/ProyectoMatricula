#ifndef NODO_ESTUDIANTES
#define NODO_ESTUDIANTES

#include "estudianteNacional.h"
#include "estudianteExtranjero.h"

class Nodo_Estudiantes
{
private:
	Estudiante* E;
	Nodo_Estudiantes* Next;
	friend ostream& operator << (ostream&, Nodo_Estudiantes&);
public:
	Nodo_Estudiantes(Estudiante*, Nodo_Estudiantes*);
	void setEstudiante(Estudiante*);
	Estudiante* getEstudiante();
	void setNext(Nodo_Estudiantes*);
	Nodo_Estudiantes* getNext();
	string toStringNodo();
	~Nodo_Estudiantes();
};
#endif // !NODO_ESTUDIANTES