#ifndef GRUPOESTUDIANTES
#define GRUPOESTUDIANTES

class Profesor;
class Estudiante;
#include "vector.h"
#include <string>

const int MAXESTU = 5;

class GrupoEstudiantes {
private:
	Profesor* profesorEncargado;
	Vector<Estudiante> *vectorEstudiantes;
	int cantidadEstudiantes;
public:
	GrupoEstudiantes();
	int getCantidad();
	void setProfesorEncargado(Profesor*);
	Profesor* getProfesorEncargado();
	void agregarEstudiante(Estudiante*);
	bool eliminarEstudiante(int);
	std::string toString();
	~GrupoEstudiantes();
};
#endif // !GRUPO
