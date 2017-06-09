#include "grupo.h"

using namespace std;

Grupo::Grupo()
{
	profesorEncargado = nullptr;
	listaEstudiantes = new Vector<Estudiante>(CUPOMAXIMO);
}

int Grupo::getCantidad()
{
	return listaEstudiantes->getCantidad();
}

void Grupo::setProfesorEncargado(Profesor *P)
{
	profesorEncargado = P;
}

Profesor * Grupo::getProfesorEncargado()
{
	return profesorEncargado;
}

Estudiante * Grupo::getEstudiante(int pos)
{
	return listaEstudiantes->getDato(pos);
}

void Grupo::agregarEstudiante(Estudiante *E)
{
	listaEstudiantes->push(E);
}

bool Grupo::eliminarEstudiante(string cedula)
{
	if (listaEstudiantes->getCantidad() < listaEstudiantes->getCapacidad())
		for (int i = 0; i < listaEstudiantes->getCantidad(); i++)
			if (listaEstudiantes->getDato(i)->getID() == cedula) {
				listaEstudiantes->eliminarPosicion(i);
				return true;
			}
	return false;
}

string Grupo::toString() {
	stringstream s;
	for (int i = 0; i < listaEstudiantes->getCantidad(); i++)
		s << listaEstudiantes->getDato(i)->getNombreCompleto() << endl;
	return s.str();
}

Grupo::~Grupo()
{
	std::cout << "Eliminando grupo Estudiantes..." << std::endl;
}
