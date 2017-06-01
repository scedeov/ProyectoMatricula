#include "grupoProfesores.h"
#include "profesor.h"
#include <string>
#include <iostream>

GrupoProfesores::GrupoProfesores()
{
	profesores = new Vector<Profesor>(MAXPROF);
}

void GrupoProfesores::agregarProfesor(Profesor *profenuevo)
{
	profesores->agregarInicio(profenuevo);
}

Profesor* GrupoProfesores::getProfesor(int pos)
{
	Vector<Profesor>::Iterador it(profesores);
	it.posicionaPrimerObjeto();
	for (int i = 0; i < pos; i++)
		it.posicionaSiguiente();
	return it.getObjectoCursorActual();
}

bool GrupoProfesores::eliminarProfesor(int cedula)
{
	if (profesores->eliminaEspecifico(cedula))
		return true;
	return false;
}

int GrupoProfesores::getCantidad()
{
	return profesores->getCantidad();
}

GrupoProfesores::~GrupoProfesores()
{
	std::cout << "Eliminando grupo de profesores..." << std::endl;
}
