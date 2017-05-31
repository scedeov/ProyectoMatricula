#include "contenedorProfesores.h"
#include <sstream>
#include <iostream>
using namespace std;

Contenedor_Profesores::Contenedor_Profesores()
{
	listaProfesores = new Lista<Profesor>();
}

void Contenedor_Profesores::insertaInicio(Profesor *P) {
	listaProfesores->agregarInicio(P);
}

Profesor * Contenedor_Profesores::retornaProfesor(int cedula) {
	Nodo<Profesor> *paux = listaProfesores->getPrimerNodo();
	while (paux != NULL) {
		if (encuentraProfesor(paux->getDato(), cedula) == true)
			return paux->getDato();
		else
			paux = paux->getNext();
	}
	return nullptr;
}

bool Contenedor_Profesores::encuentraProfesor(Profesor *P, int cedula) {
	if (P->getNumCedula() == cedula)
		return true;
	else
		return false;
}

int Contenedor_Profesores::contadorProfesores() {
	listaProfesores->getCantidad();
}

string Contenedor_Profesores::toString()
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

Contenedor_Profesores::~Contenedor_Profesores() {
	cout << "Eliminando Contenedor de Profesores" << endl;
	listaProfesores->limpiar();
}

ostream & operator<<(ostream &o, Contenedor_Profesores &ContP) {
	return o << ContP.toString();
}
