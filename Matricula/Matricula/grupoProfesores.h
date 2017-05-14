#ifndef GRUPOPROFESORES
#define GRUPOPROFESORES


#include "profesor.h"
const int MAXPROF = 5;

class GrupoProfesores {
private:
	int cantidadProfesores;
	Profesor* profesores[MAXPROF];
public:
	GrupoProfesores();
	void agregarProfesor(Profesor*);
	Profesor* getProfesor(int);
	bool eliminarProfesor(int);
	int getCantidadProfesores();
	~GrupoProfesores();
};
#endif // !GRUPO
