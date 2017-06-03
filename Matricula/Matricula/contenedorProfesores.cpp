#include "contenedorProfesores.h"
#include "profesor.h"
#include <sstream>
#include <iostream>
using namespace std;

ContenedorProfesores::ContenedorProfesores()
{
	listaProfesores = new Lista<Profesor>();
}

void ContenedorProfesores::agregarInicio(Profesor *P) {
	listaProfesores->agregarInicio(P);
}

Profesor * ContenedorProfesores::retornaProfesor(int cedula) {
	Nodo<Profesor> *paux = listaProfesores->getPrimerNodo();
	while (paux != NULL) {
		if (encuentraProfesor(paux->getDato(), cedula) == true)
			return paux->getDato();
		else
			paux = paux->getNext();
	}
	return nullptr;
}

bool ContenedorProfesores::encuentraProfesor(Profesor *P, int cedula) {
	if (P->getNumCedula() == cedula)
		return true;
	else
		return false;
}

int ContenedorProfesores::getCantidad() {
	listaProfesores->getCantidad();
}

string ContenedorProfesores::toString() {
	stringstream s;
	if (listaProfesores->estaVacia())
		s << "La lista esta vacia..." << endl;
	else {
		Nodo<Profesor>  *paux = listaProfesores->getPrimerNodo();
		while (paux != NULL) {
			s << paux->getDato()->toString() << endl;
			paux = paux->getNext();
		}
	}
	return s.str();
}

ContenedorProfesores::~ContenedorProfesores() {
	cout << "Eliminando Contenedor de Profesores" << endl;
	listaProfesores->limpiar();
}

ostream & operator<<(ostream &o, ContenedorProfesores &ContP) {
	return o << ContP.toString();
}
