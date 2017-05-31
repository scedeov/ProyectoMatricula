#include "grupoEstudiantes.h"
#include "estudiante.h"
#include <iostream>
#include <sstream>
using namespace std;

GrupoEstudiantes::GrupoEstudiantes()
{
	profesorEncargado = nullptr;
	vectorEstudiantes = new Vector<Estudiante>(MAXESTU);
}

int GrupoEstudiantes::getCantidad()
{
	return vectorEstudiantes->getCantidad();
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
	vectorEstudiantes->agregarInicio(E);
}

bool GrupoEstudiantes::eliminarEstudiante(int cedula)
{
	Vector<Estudiante>::Iterador it(vectorEstudiantes);
	it.posicionaPrimerObjeto();
	while (it.getPosicionActual() < vectorEstudiantes->getCantidad()) {
		if (it.getObjetoActual()->getNumCedula() == cedula) { // si es el primero
			vectorEstudiantes->eliminaEspecifico(it.getPosicionActual());
			return true;
		}
		else
			it.posicionaSiguiente();
	}
	return false;
}

string GrupoEstudiantes::toString()
{
	stringstream s;
	Vector<Estudiante>::Iterador it(vectorEstudiantes);
	it.posicionaPrimerObjeto();
	for (int i = 0; i < vectorEstudiantes->getCantidad(); i++) {
		s << it.getObjetoActual()->getNombreCompleto() << endl;
		it.posicionaSiguiente();
	}
	return s.str();
}

GrupoEstudiantes::~GrupoEstudiantes()
{
	std::cout << "Eliminando grupo Estudiantes..." << std::endl;
	delete vectorEstudiantes;
}
