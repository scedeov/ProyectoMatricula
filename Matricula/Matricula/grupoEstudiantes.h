#ifndef GRUPOESTUDIANTES
#define GRUPOESTUDIANTES

#include "estudiante.h"
#include "profesor.h"

const int MAXESTU = 5;

class GrupoEstudiantes {
private:
	Profesor* profesorEncargado;
	std::vector<Estudiante*> listaEstudiantes;
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
