#include "contenedorCursos.h"
#include "grupoProfesores.h"
#include "addBehavior.h"
#include "curso.h"
#include <sstream>
#include <iostream>
using namespace std;

ContenedorCursos::ContenedorCursos() {
	listaCursos = new Lista<Curso>();
}

int ContenedorCursos::getCantidad() {	
	return listaCursos->getCantidad();
}

Curso* ContenedorCursos::getCurso(int pos) {
	return listaCursos->at(pos);
}

void ContenedorCursos::agregarInicio(Curso *unCurso) {
	listaCursos->agregarInicio(unCurso);
}

bool ContenedorCursos::eliminarEspecifico(string codigo)
{
	if (listaCursos->estaVacia())
		return false;

	if (listaCursos->getPrimerDato()->getCodigoCurso() == codigo)
		listaCursos->eliminarInicio();

	Nodo<Curso> *paux = listaCursos->getPrimerNodo();
	Nodo<Curso> *anterior = listaCursos->getPrimerNodo();
	while (paux != NULL && listaCursos->getPrimerDato()->getCodigoCurso() != codigo) {
		anterior = paux;
		paux = paux->getNext();
	}

	if (paux == NULL)
		return false;

	else {
		anterior->setNext(paux->getNext());
		delete paux;
		return true;
	}
	return false;
}

Curso* ContenedorCursos::getCursoEspecifico(string codigo)
{
	Nodo<Curso> *paux = listaCursos->getPrimerNodo();
	while (paux != NULL) {
		if (encuentraCurso(paux->getDato(), codigo) == true)
			return paux->getDato();
		else
			paux = paux->getNext();
	}
	return nullptr;
}

bool ContenedorCursos::encuentraCurso(Curso* C, string codigo)
{
	if (C->getCodigoCurso() == codigo)
		return true;
	else
		return false;
}

string ContenedorCursos::toString()
{
	stringstream s;
	if (listaCursos->estaVacia())
		s << "La lista esta vacia..." << endl;
	else {
		Nodo<Curso>  *paux = listaCursos->getPrimerNodo();
		while (paux != NULL) {
			s << paux->getDato()->toString() << endl;
			paux = paux->getNext();
		}
	}
	return s.str();
}

int ContenedorCursos::getProfesores(string codigo, int pos) {
	return getCursoEspecifico(codigo)->getGrupoProfesores()->getProfesor(pos)->getNumCedula();
}

ContenedorCursos::~ContenedorCursos()
{
	cout << "Eliminando Contenedor de Cursos" << endl;
	listaCursos->limpiar();
}

ostream & operator<<(ostream &o, ContenedorCursos &ConC) {
	return o << ConC.toString();
}
