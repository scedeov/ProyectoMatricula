#include "contenedorCursos.h"
#include "grupoProfesores.h"
#include <sstream>
#include <iostream>
using namespace std;

Contenedor_Cursos::Contenedor_Cursos()
{
}

int Contenedor_Cursos::getCantidad()
{	
	return listaCursos.tamano();
}

Curso * Contenedor_Cursos::getCursoporPos(int pos)
{
	return listaCursos.
}

void Contenedor_Cursos::insertaInicio(Curso *unCurso)
{
	listaCursos.push_front(unCurso);
}

bool Contenedor_Cursos::eliminaCursoEspecifico(string codigo)
{
	if (listaCursos.empty()) {
		return false;
	}
	if (listaCursos.begin()->->getCodigoCurso() == codigo)
	{
		listaCursos.remove()
	}

	while (paux != NULL &&   paux->getCurso()->getCodigoCurso() != codigo) {
		anterior = paux;
		paux = paux->getNext();
	}

	if (paux == NULL)
	{
		return false;
	}

	else
	{
		anterior->setNext(paux->getNext());
		delete paux;
		cantidad--;
		return true;
	}
	return false;
}

Curso * Contenedor_Cursos::retornaCursoEspecifico(string codigo)
{
	/*paux = pinicio;
	while (paux != NULL)
	{
		if (encuentraCurso(paux->getCurso(), codigo) == true)
			return paux->getCurso();
		else
			paux = paux->getNext();
	}
	*/
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
	/*paux = pinicio;
	stringstream s;
	while (paux != NULL) {
		s << paux->toStringNodo() << endl;
		paux = paux->getNext();
	}
	return s.str();*/
	return string();
}

int Contenedor_Cursos::getProfesores(string codigo, int pos) {
	return retornaCursoEspecifico(codigo)->getGrupoProfesores()->getProfesor(pos)->getNumCedula();
}

Contenedor_Cursos::~Contenedor_Cursos()
{/*
	cout << "Eliminando Contenedor de Cursos" << endl;

	while (pinicio != NULL)
	{
		paux = pinicio;
		pinicio = pinicio->getNext();
		delete paux;
	}*/
}

ostream & operator<<(ostream &o, Contenedor_Cursos &ConC) {
	return o << ConC.toString();
}
