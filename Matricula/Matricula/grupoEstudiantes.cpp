#include "grupoEstudiantes.h"

GrupoEstudiantes::GrupoEstudiantes()
{
	profesorEncargado = nullptr;
	for (int i = 0; i < MAXESTU; i++)
		listaEstudiantes[i] = new Estudiante();

	cantidadEstudiantes = 0;
}

void GrupoEstudiantes::setProfesorEncargado(Profesor *P)
{
	profesorEncargado = P;
}

Profesor * GrupoEstudiantes::getProfesorEncargado()
{
	return profesorEncargado;
}

void GrupoEstudiantes::agregarEstudiante(Estudiante *E)
{
	if (cantidadEstudiantes < MAXESTU) {
		listaEstudiantes[cantidadEstudiantes] = E;
		cantidadEstudiantes++;
	}
}

bool GrupoEstudiantes::eliminarEstudiante(int cedula)
{
	for (int i = 0; i < cantidadEstudiantes; i++)
		if (listaEstudiantes[i]->getNumCedula() == cedula) {
			for (int x = i; x < cantidadEstudiantes; x++)
				listaEstudiantes[x] = listaEstudiantes[i + 1];
			cantidadEstudiantes--;
			return true;
		}
	return false;
}

GrupoEstudiantes::~GrupoEstudiantes()
{
	cout << "Eliminando grupo Estudiantes..." << endl;
}
