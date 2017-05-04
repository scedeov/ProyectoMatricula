#ifndef CONTENEDOR_PROFESORES
#define CONTENEDOR_PROFESORES

#include "nodoProfesores.h"

#include <iostream>
using namespace std;


class Contenedor_Profesores
{
private:
	Nodo_Profesores *pinicio;
	Nodo_Profesores *paux;
	friend ostream& operator << (ostream&, Contenedor_Profesores&);
public:
	Contenedor_Profesores();
	void insertaInicio(Profesor*);
	Profesor* retornaProfesor(int);
	bool encuentraProfesor(Profesor*, int);
	int contadorProfesores();
	string toString();
	~Contenedor_Profesores();
};
#endif // !CONTENEDOR_PROFESORES
