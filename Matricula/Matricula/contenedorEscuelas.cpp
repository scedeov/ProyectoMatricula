#include "contenedorEscuelas.h"
#include "escuela.h"
#include "contenedorProfesores.h"
#include <sstream>
#include <iostream>
using namespace std;

contenedorEscuelas::contenedorEscuelas() {
	listaEscuelas = new Lista<Escuela>();
}

void contenedorEscuelas::agregarInicio(Escuela* unEscuela) {
	listaEscuelas->agregarInicio(unEscuela);
}

Escuela * contenedorEscuelas::retornaEscuela(string sigla) const {
	Nodo<Escuela> *paux = listaEscuelas->getPrimerNodo();
	while (paux != NULL) {
		if (encuentraEscuela(paux->getDato(), sigla) == true)
			return paux->getDato();
		else
			paux = paux->getNext();
	}
	return nullptr;
}

Profesor * contenedorEscuelas::retornaProfesor(int cedula) {
	Nodo<Escuela> *paux = listaEscuelas->getPrimerNodo();
	while (paux != NULL) {
		if (dynamic_cast<Escuela*>(paux->getDato())->getContenedorProfesores()->retornaProfesor(cedula) != NULL)
			return dynamic_cast<Escuela*>(paux->getDato())->getContenedorProfesores()->retornaProfesor(cedula);
		else
			paux = paux->getNext();
	}
	return nullptr;
}

bool contenedorEscuelas::encuentraEscuela(Escuela* e, string sigla) const {
	if (e->getSiglaEscuela() == sigla)
		return true;
	else
		return false;
}

string contenedorEscuelas::toString(char op) const {
	stringstream s;
	if (listaEscuelas->estaVacia())
		s << "La lista esta vacia..." << endl;
	else {
		Nodo<Escuela> *paux = listaEscuelas->getPrimerNodo();
		while (paux != NULL) {
			s << paux->getDato()->toString(op) << endl;
			paux = paux->getNext();
		}
	}
	return s.str();
}

contenedorEscuelas::~contenedorEscuelas() {
	cout << "Eliminando Contenedor de Escuelas" << endl;
	listaEscuelas->limpiar();
}
