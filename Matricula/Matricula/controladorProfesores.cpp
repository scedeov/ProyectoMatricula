#include "controladorProfesores.h"
#include "profesor.h"
#include <sstream>
#include <iostream>
using namespace std;

ControladorProfesores::ControladorProfesores()
{
	listaProfesores = new Lista<Profesor>();
}

void ControladorProfesores::insertaInicio(Profesor *P) {
	listaProfesores->push_front(P);
}

Profesor * ControladorProfesores::retornaProfesor(string cedula) {
	Nodo<Profesor> *paux = listaProfesores->begin();
	while (paux != nullptr) {
		if (paux->getDato()->getID() == cedula)
			return paux->getDato();
		else
			paux = paux->getNext();
	}
	return nullptr;
}

int ControladorProfesores::contadorProfesores() {
	return listaProfesores->size();
}

string ControladorProfesores::toString()
{
	stringstream s;
	Nodo<Profesor> *paux = listaProfesores->begin();
	while (paux != NULL) {
		s << paux->getDato()->toString();
		paux = paux->getNext();
	}
	return s.str();
}

ControladorProfesores::~ControladorProfesores() {
	cout << "Eliminando Contenedor de Profesores" << endl;
	listaProfesores->wipe();
}

ostream & operator<<(ostream &o, ControladorProfesores &ContP) {
	return o << ContP.toString();
}
