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
	vectorEstudiantes->push(E);
}

bool GrupoEstudiantes::eliminarEstudiante(int cedula)
{
	Vector<Estudiante>::Iterador it(vectorEstudiantes);
	it.first();
	while (it.getPosActual() < vectorEstudiantes->getCantidad()) {
		if (it.getCurItem()->getNumCedula() == cedula) { // si es el primero
			vectorEstudiantes->eliminaEspecifico(it.getPosActual());
			return true;
		}
		else
			it.next();
	}
	return false;
}

string GrupoEstudiantes::toString()
{
	stringstream s;
	Vector<Estudiante>::Iterador it(vectorEstudiantes);
	it.first();
	for (int i = 0; i < vectorEstudiantes->getCantidad(); i++) {
		s << it.getCurItem()->getNombreCompleto() << endl;
		it.next();
	}
	return s.str();
}

GrupoEstudiantes::~GrupoEstudiantes()
{
	std::cout << "Eliminando grupo Estudiantes..." << std::endl;
}
