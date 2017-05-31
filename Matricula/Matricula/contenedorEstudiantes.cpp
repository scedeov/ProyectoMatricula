#include "contenedorEstudiantes.h"
#include <iostream>
#include <sstream>
using namespace std;

Contenedor_Estudiantes::Contenedor_Estudiantes()
{
	estudiantes = new Lista<Estudiante>();
}

int Contenedor_Estudiantes::getCantidadEstudiantes() {
	return estudiantes->getCantidad();
}

void Contenedor_Estudiantes::insertaInicio(Estudiante *unEstudiante)
{
	estudiantes->agregarInicio(unEstudiante);
}

Estudiante * Contenedor_Estudiantes::retornaEstudiante(int cedula)
{
	for (int i = 0; i < estudiantes->getCantidad(); i++)
		if ((estudiantes->getPrimerDato() + i)->getNumCedula() == cedula)
			return estudiantes->getPrimerDato() + i;
	return nullptr;
}

string Contenedor_Estudiantes::toString()
{
	stringstream s;
	for (int i = 0; i < estudiantes->getCantidad(); i++)
		s << (estudiantes->getPrimerDato() + 1)->toString() << endl;
	return s.str();
}

Contenedor_Estudiantes::~Contenedor_Estudiantes()
{
	cout << "Eliminando Contenedor de Cursos" << endl;
	estudiantes->limpiar();
}

ostream & operator<<(ostream &o, Contenedor_Estudiantes &CEs) {
	return o << CEs.toString();
}
