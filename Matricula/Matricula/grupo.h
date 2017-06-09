#ifndef GRUPOESTUDIANTES
#define GRUPOESTUDIANTES


#include <iostream>
#include <sstream>
//class Profesor;
//class Estudiante;
#include "vector.h"
#include "estudiante.h"
#include "profesor.h"

const int CUPOMAXIMO = 30;

class Grupo {
private:
	Profesor* profesorEncargado;
	Vector<Estudiante> *listaEstudiantes;
public:
	Grupo();
	int getCantidad();
	void setProfesorEncargado(Profesor*);
	Profesor* getProfesorEncargado();
	Estudiante* getEstudiante(int);
	void agregarEstudiante(Estudiante*);
	bool eliminarEstudiante(string);
	std::string toString();
	~Grupo();
};
#endif // !GRUPO
