#ifndef CONTENEDOR_PROFESORES
#define CONTENEDOR_PROFESORES

#include "nodoProfesores.h"

class Contenedor_Profesores
{
private:
	Nodo_Profesores *pinicio;
	Nodo_Profesores *paux;
	friend std::ostream& operator << (std::ostream&, Contenedor_Profesores&);
public:
	Contenedor_Profesores();
	void insertaInicio(Profesor*);
	Profesor* retornaProfesor(int);
	bool encuentraProfesor(Profesor*, int);
	int contadorProfesores();
	std::string toString();
	~Contenedor_Profesores();
};
#endif // !CONTENEDOR_PROFESORES
