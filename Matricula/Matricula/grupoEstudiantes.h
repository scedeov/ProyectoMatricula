#ifndef GRUPOESTUDIANTES
#define GRUPOESTUDIANTES

#include "estudiante.h"
#include "profesor.h"

const int MAXESTU = 5;

class GrupoEstudiantes {
private:
	Profesor* profesorEncargado;
	Estudiante* listaEstudiantes[MAXESTU];
	int cantidadEstudiantes;
public:
	GrupoEstudiantes();
	void setProfesorEncargado(Profesor*);
	Profesor* getProfesorEncargado();
	void agregarEstudiante(Estudiante*);
	bool eliminarEstudiante(int);
	~GrupoEstudiantes();
};
#endif // !GRUPO
