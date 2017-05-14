#include "grupoProfesores.h"

GrupoProfesores::GrupoProfesores()
{
	for (int i = 0; i < MAXPROF; i++)
		profesores[i] = new Profesor();
	cantidadProfesores = 0;
}

void GrupoProfesores::agregarProfesor(Profesor *profenuevo)
{
	if (cantidadProfesores < MAXPROF) {
		profesores[cantidadProfesores] = profenuevo;
		cantidadProfesores++;
	}
}

Profesor* GrupoProfesores::getProfesor(int pos)
{
	return profesores[pos];
}

bool GrupoProfesores::eliminarProfesor(int cedula)
{
	for (int i = 0; i < cantidadProfesores; i++)
		if (profesores[i]->getNumCedula() == cedula) {
			for (int x = i; x < cantidadProfesores; x++)
				profesores[x] = profesores[i + 1];
			cantidadProfesores--;
			return true;
		}
	return false;
}

int GrupoProfesores::getCantidadProfesores()
{
	return cantidadProfesores;
}

GrupoProfesores::~GrupoProfesores()
{
	cout << "Eliminando grupo de profesores..." << endl;
}
