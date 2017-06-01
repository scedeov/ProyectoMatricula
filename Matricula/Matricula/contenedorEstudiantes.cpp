#include "contenedorEstudiantes.h"
#include <iostream>
#include <sstream>
using namespace std;

contenedorEstudiantes::contenedorEstudiantes()
{
	estudiantes = new Lista<Estudiante>();
}

int contenedorEstudiantes::getCantidadEstudiantes() {
	return estudiantes->getCantidad();
}

void contenedorEstudiantes::agregarInicio(Estudiante *unEstudiante)
{
	estudiantes->agregarInicio(unEstudiante);
}

Estudiante * contenedorEstudiantes::retornaEstudiante(int cedula)
{
	for (int i = 0; i < estudiantes->getCantidad(); i++)
		if ((estudiantes->getPrimerDato() + i)->getNumCedula() == cedula)
			return estudiantes->getPrimerDato() + i;
	return nullptr;
}

string contenedorEstudiantes::toString()
{
	stringstream s;
	for (int i = 0; i < estudiantes->getCantidad(); i++)
		s << (estudiantes->getPrimerDato() + 1)->toString() << endl;
	return s.str();
}

contenedorEstudiantes::~contenedorEstudiantes()
{
	cout << "Eliminando Contenedor de Cursos" << endl;
	estudiantes->limpiar();
}

ostream & operator<<(ostream &o, contenedorEstudiantes &CEs) {
	return o << CEs.toString();
}
