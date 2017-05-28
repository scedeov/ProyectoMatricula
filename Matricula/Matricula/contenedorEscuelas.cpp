#include "contenedorEscuelas.h"
#include "contenedorProfesores.h"
#include <sstream>
#include <iostream>
using namespace std;

Contenedor_Escuelas::Contenedor_Escuelas()
{
	listaEscuelas = new Lista<Escuela>();
}

void Contenedor_Escuelas::insertarInicio(Escuela* unEscuela)
{
	listaEscuelas->push_front(unEscuela);
}

Escuela * Contenedor_Escuelas::retornaEscuela(string sigla)
{
	Nodo<Escuela> *paux = listaEscuelas->begin();
	while (paux != NULL)
	{
		if (encuentraEscuela(paux->getDato(), sigla) == true)
			return paux->getDato();
		else
			paux = paux->getNext();
	}
	return nullptr;
}

Profesor * Contenedor_Escuelas::retornaProfesor(int cedula)
{
	Nodo<Escuela> *paux = listaEscuelas->begin();
	while (paux != NULL) {
		if (paux->getDato()->getContenedorProfesores()->retornaProfesor(cedula) != NULL)
			return paux->getDato()->getContenedorProfesores()->retornaProfesor(cedula);
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
	if (listaEscuelas->empty())
		s << "La lista esta vacia..." << endl;
	else {
		Nodo<Escuela>  *paux = listaEscuelas->begin();
		while (paux != NULL) {
			s << paux->getDato()->toStringEscuela(op) << endl;
			paux = paux->getNext();
		}
	}
	return s.str();
}

Contenedor_Escuelas::~Contenedor_Escuelas()
{
	cout << "Eliminando Contenedor de Escuelas" << endl;

	while (pinicio != NULL)
	{
		paux = pinicio;
		pinicio = pinicio->getNext();
		delete paux;
	}
}
