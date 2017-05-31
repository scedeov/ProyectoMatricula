#include "contenedorEscuelas.h"
#include "escuela.h"
#include "contenedorProfesores.h"
#include <sstream>
#include <iostream>
using namespace std;

Contenedor_Escuelas::Contenedor_Escuelas()
{
	listaEscuelas = new Lista();
}

void Contenedor_Escuelas::agregarInicio(Escuela* unEscuela)
{
	listaEscuelas->agregarInicio(unEscuela);
}

Escuela * Contenedor_Escuelas::retornaEscuela(string sigla)
{
	Nodo*paux = listaEscuelas->getPrimerNodo();
	while (paux != NULL) {
		if (encuentraEscuela(dynamic_cast<Escuela*>(paux->getDato()), sigla) == true)
			return dynamic_cast<Escuela*>(paux->getDato());
		else
			paux = paux->getNext();
	}
	return nullptr;
}

Profesor * Contenedor_Escuelas::retornaProfesor(int cedula)
{
	Nodo *paux = listaEscuelas->getPrimerNodo();
	while (paux != NULL) {
		if (dynamic_cast<Escuela*>(paux->getDato())->getContenedorProfesores()->retornaProfesor(cedula) != NULL)
			return dynamic_cast<Escuela*>(paux->getDato())->getContenedorProfesores()->retornaProfesor(cedula);
		else
			paux = paux->getNext();
	}
	return nullptr;
}

bool Contenedor_Escuelas::encuentraEscuela(Escuela* e, string sigla)
{
	if (e->getSiglaEscuela() == sigla)
		return true;
	else
		return false;
}

string Contenedor_Escuelas::toString(char op) // debido a este char no puedo hacer sobrecarga
{
	stringstream s;
	if (listaEscuelas->estaVacia())
		s << "La lista esta vacia..." << endl;
	else {
		Nodo *paux = listaEscuelas->getPrimerNodo();
		while (paux != NULL) {
			s << dynamic_cast<Escuela*>(paux->getDato())->toString(op) << endl;
			paux = paux->getNext();
		}
	}
	return s.str();
}

Contenedor_Escuelas::~Contenedor_Escuelas()
{
	cout << "Eliminando Contenedor de Escuelas" << endl;
	listaEscuelas->limpiar();
}
