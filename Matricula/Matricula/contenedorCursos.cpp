#include "contenedorCursos.h"
#include "grupoProfesores.h"
#include <sstream>
#include <iostream>
using namespace std;

Contenedor_Cursos::Contenedor_Cursos()
{
	listaCursos = new Lista<Curso>();
}

int Contenedor_Cursos::getCantidad()
{	
	return listaCursos->getCantidad();
}

Curso* Contenedor_Cursos::getCursoporPos(int pos)
{
	return listaCursos->at(pos);
}

void Contenedor_Cursos::insertaInicio(Curso *unCurso)
{
	listaCursos->agregarInicio(unCurso);
}

bool Contenedor_Cursos::eliminarEspecifico(string codigo)
{
	if (listaCursos->estaVacia())
		return false;

	if (listaCursos->getPrimerDato()->getCodigoCurso() == codigo)
		listaCursos->eliminarInicio();

	Nodo *paux = listaCursos->getPrimerNodo();
	Nodo *anterior = listaCursos->getPrimerNodo();
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

Curso* Contenedor_Cursos::retornaCursoEspecifico(string codigo)
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

bool Contenedor_Cursos::encuentraCurso(Curso* C, string codigo)
{
	if (C->getCodigoCurso() == codigo)
		return true;
	else
		return false;
}

string Contenedor_Cursos::toString()
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

int Contenedor_Cursos::getProfesores(string codigo, int pos) {
	return retornaCursoEspecifico(codigo)->getGrupoProfesores()->getProfesor(pos)->getNumCedula();
}

Contenedor_Cursos::~Contenedor_Cursos()
{
	cout << "Eliminando Contenedor de Cursos" << endl;
	listaCursos->limpiar();
}

ostream & operator<<(ostream &o, Contenedor_Cursos &ConC) {
	return o << ConC.toString();
}
