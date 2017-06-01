#include "contenedorProfesores.h"
#include <sstream>
#include <iostream>
using namespace std;

contenedorProfesores::contenedorProfesores()
{
	listaProfesores = new Lista<Profesor>();
}

void contenedorProfesores::agregarInicio(Profesor *P) {
	listaProfesores->agregarInicio(P);
}

Profesor * contenedorProfesores::retornaProfesor(int cedula) {
	Nodo<Profesor> *paux = listaProfesores->getPrimerNodo();
	while (paux != NULL) {
		if (encuentraProfesor(paux->getDato(), cedula) == true)
			return paux->getDato();
		else
			paux = paux->getNext();
	}
	return nullptr;
}

bool contenedorProfesores::encuentraProfesor(Profesor *P, int cedula) {
	if (P->getNumCedula() == cedula)
		return true;
	else
		return false;
}

int contenedorProfesores::contadorProfesores() {
	listaProfesores->getCantidad();
}

string contenedorProfesores::toString()
{
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

contenedorProfesores::~contenedorProfesores() {
	cout << "Eliminando Contenedor de Profesores" << endl;
	listaProfesores->limpiar();
}

ostream & operator<<(ostream &o, contenedorProfesores &ContP) {
	return o << ContP.toString();
}
