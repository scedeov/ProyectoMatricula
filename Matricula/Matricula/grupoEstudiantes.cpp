#include "grupoEstudiantes.h"
#include "estudiante.h"
#include <iostream>
#include <sstream>
using namespace std;

GrupoEstudiantes::GrupoEstudiantes()
{
	profesorEncargado = nullptr;
	listaEstudiantes.reserve(MAXESTU);
}

int GrupoEstudiantes::getCantidad()
{
	return (int) listaEstudiantes.size();
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
	listaEstudiantes.push_back(E);
}

bool GrupoEstudiantes::eliminarEstudiante(int cedula)
{
	if (listaEstudiantes.size() < listaEstudiantes.capacity())
		for (int i = 0; i < listaEstudiantes.size(); i++)
			if (listaEstudiantes[i]->getNumCedula() == cedula) {
				listaEstudiantes.erase(listaEstudiantes.begin() + (i - 1));
				return true;
			}
	return false;
}

string GrupoEstudiantes::toString()
{
	stringstream s;
	for (int i = 0; i < listaEstudiantes.size(); i++)
		s << listaEstudiantes[i]->getNombreCompleto() << endl;
	return s.str();
}

GrupoEstudiantes::~GrupoEstudiantes()
{
	std::cout << "Eliminando grupo Estudiantes..." << std::endl;
}
