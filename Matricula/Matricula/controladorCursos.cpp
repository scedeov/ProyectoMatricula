#include "controladorCursos.h"
#include "grupo.h"
#include "curso.h"
#include <sstream>
#include <iostream>
using namespace std;

ControladorCursos::ControladorCursos()
{
	listaCursos = new Lista<Curso>();
}

int ControladorCursos::getCantidad()
{
	return listaCursos->size();
}

Curso* ControladorCursos::getCursoporPos(int pos)
{
	return listaCursos->at(pos);
}

void ControladorCursos::insertaInicio(Curso *unCurso)
{
	listaCursos->push_front(unCurso);
}

bool ControladorCursos::eliminaCursoEspecifico(string codigo) {
	if (listaCursos->empty())
		return false;

	if (listaCursos->front()->getCodigoCurso() == codigo)
		listaCursos->pop_front();

	Nodo<Curso> *paux = listaCursos->begin();
	Nodo<Curso> *anterior = listaCursos->begin();
	while (paux != NULL && listaCursos->front()->getCodigoCurso() != codigo) {
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

Curso* ControladorCursos::retornaCursoEspecifico(string codigo) {
	Nodo<Curso> *paux = listaCursos->begin();
	while (paux != NULL)
		if (paux->getDato()->getCodigoCurso() == codigo)
			return paux->getDato();
		else
			paux = paux->getNext();

	return nullptr;
}

string ControladorCursos::toString()
{
	stringstream s;
	if (listaCursos->empty())
		s << "La lista esta vacia..." << endl;
	else {
		Nodo<Curso>  *paux = listaCursos->begin();
		while (paux != NULL) {
			s << paux->getDato()->toString() << endl;
			paux = paux->getNext();
		}
	}
	return s.str();
}

string ControladorCursos::getCursosProfesorEspecifico(string cedula) {
	stringstream s;
	Nodo<Curso> *paux = listaCursos->begin();
	while (paux != NULL) {
		for (int i = 0; i < paux->getDato()->getCantidadGrupos(); i++) {
			if (paux->getDato()->getGrupo(i)->getProfesorEncargado()->getID() == cedula) {
				s << paux->getDato()->getNombre() << " | " << paux->getDato()->getCodigoCurso() << endl;
				paux = paux->getNext();
				break;
			}
		}
	}
	return s.str();
}

ControladorCursos::~ControladorCursos()
{
	cout << "Eliminando Contenedor de Cursos" << endl;
	listaCursos->wipe();
}

ostream & operator<<(ostream &o, ControladorCursos &ConC) {
	return o << ConC.toString();
}
