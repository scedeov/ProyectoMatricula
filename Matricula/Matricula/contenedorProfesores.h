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
public:
	Contenedor_Profesores();
	void insertaInicio(Profesor*);
	~Contenedor_Profesores();

};
#endif // !CONTENEDOR_PROFESORES
