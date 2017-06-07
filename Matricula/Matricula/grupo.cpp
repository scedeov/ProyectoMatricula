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

void Grupo::agregarEstudiante(Estudiante *E)
{
	listaEstudiantes->push(E);
}

bool Grupo::eliminarEstudiante(int cedula)
{
	/*if (listaEstudiantes.size() < listaEstudiantes.capacity())
		for (int i = 0; i < listaEstudiantes.size(); i++)
			if (listaEstudiantes[i]->getNumCedula() == cedula) {
				listaEstudiantes.erase(listaEstudiantes.begin() + (i - 1));
				return true;
			}
	return false;*/
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
