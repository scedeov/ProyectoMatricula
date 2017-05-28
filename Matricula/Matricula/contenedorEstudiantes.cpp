#include "contenedorEstudiantes.h"
#include <iostream>
#include <sstream>
using namespace std;

Contenedor_Estudiantes::Contenedor_Estudiantes()
{
	estudiantes = new Lista<Estudiante>();
}

int Contenedor_Estudiantes::getCantidadEstudiantes() {
	return estudiantes->size();
}

void Contenedor_Estudiantes::insertaInicio(Estudiante *unEstudiante)
{
	estudiantes->push_front(unEstudiante);
}

Estudiante * Contenedor_Estudiantes::retornaEstudiante(int cedula)
{
	for (int i = 0; i < estudiantes->size(); i++)
		if ((estudiantes->front() + i)->getNumCedula() == cedula)
			return estudiantes->front() + i;
	return nullptr;
}

string Contenedor_Estudiantes::toString()
{
	stringstream s;
	for (int i = 0; i < estudiantes->size(); i++)
		s << (estudiantes->front() + 1)->toString() << endl;
	return s.str();
}

Contenedor_Estudiantes::~Contenedor_Estudiantes()
{
	cout << "Eliminando Contenedor de Cursos" << endl;
	estudiantes->wipe();
}

ostream & operator<<(ostream &o, Contenedor_Estudiantes &CEs) {
	return o << CEs.toString();
}
