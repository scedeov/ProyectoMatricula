#include "controladorEstudiantes.h"
#include "estudiante.h"
#include <iostream>
#include <sstream>
using namespace std;

ControladorEstudiantes::ControladorEstudiantes()
{
	listaEstudiantes = new Lista<Estudiante>();
}

int ControladorEstudiantes::getCantidadEstudiantes() {
	return listaEstudiantes->size();
}

void ControladorEstudiantes::insertaInicio(Estudiante *unEstudiante)
{
	listaEstudiantes->push_front(unEstudiante);
}

Estudiante * ControladorEstudiantes::retornaEstudiante(string cedula)
{
	listaEstudiantes->encontrarPorId(cedula);
}

string ControladorEstudiantes::toString()
{
	stringstream s;
	Nodo<Estudiante> *paux = listaEstudiantes->begin();
	while (paux != NULL) {
		s << paux->getDato()->toString();
		paux = paux->getNext();
	}
	return s.str();
}

ControladorEstudiantes::~ControladorEstudiantes()
{
	cout << "Eliminando Contenedor de Cursos" << endl;
	listaEstudiantes->wipe();
}

ostream & operator<<(ostream &o, ControladorEstudiantes &CEs) {
	return o << CEs.toString();
}
