#ifndef CONTENEDOR_ESTUDIANTES
#define CONTENEDOR_ESTUDIANTES	

#include "nodoEstudiantes.h"

#include <iostream>
using namespace std;

class Contenedor_Estudiantes
{
private:
	Nodo_Estudiantes *pinicio;
	Nodo_Estudiantes *paux;
	friend ostream& operator << (ostream&, Contenedor_Estudiantes&);
public:
	Contenedor_Estudiantes();
	void insertaInicio(Estudiante*);
	string toString();
	~Contenedor_Estudiantes();
};
#endif // !CONTENEDOR_ESTUDIANTES

