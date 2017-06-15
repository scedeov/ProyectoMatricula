#include "controladorEscuelas.h"
#include "estudiante.h"
#include "escuela.h"
#include "curso.h"
#include <sstream>
#include <iostream>
using namespace std;

ControladorEscuelas::ControladorEscuelas()
{
	listaEscuelas = new Lista<Escuela>();
}

void ControladorEscuelas::insertarInicio(Escuela* unEscuela)
{
	listaEscuelas->push_front(unEscuela);
}

Escuela * ControladorEscuelas::retornaEscuela(string sigla)
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

Profesor * ControladorEscuelas::retornaProfesor(string cedula)
{
	Nodo<Escuela> *paux = listaEscuelas->begin();
	while (paux != NULL) {
		if (paux->getDato()->getContenedorProfesores()->retornaProfesor(cedula) != nullptr)
			return paux->getDato()->getContenedorProfesores()->retornaProfesor(cedula);
		else
			paux = paux->getNext();
	}
	return nullptr;
}

//int ControladorEscuelas::cantidadCursosMatriculadosEstudiante(Estudiante *estudiante)
//{
//	int contador = 0;
//	Nodo<Escuela> * paux = listaEscuelas->begin();
//	while (paux != NULL) {
//		for (int x = 0; x < paux->getDato()->getContenedorCursos()->getCantidad(); x++) {
//			Curso * curso = paux->getDato()->getContenedorCursos()->getCursoporPos(x);
//			if (curso->estaEstudiante(estudiante))
//				contador++;
//		}
//		paux = paux->getNext();
//	}
//	return contador;
//}

bool ControladorEscuelas::encuentraEscuela(Escuela* e, string sigla)
{
	if (e->getSiglaEscuela() == sigla)
		return true;
	else
		return false;
}

string ControladorEscuelas::toStringEscuelas()
{
	stringstream s;
	Nodo<Escuela> *paux = listaEscuelas->begin();
	while (paux != NULL) {
		s << paux->getDato()->toStringEscuela();
		paux = paux->getNext();
	}
	return s.str();
}

string ControladorEscuelas::toStringConCursos() // debido a este char no puedo hacer sobrecarga
{
	stringstream s;
	Nodo<Escuela> *paux = listaEscuelas->begin();
	while (paux != NULL) {
		s << paux->getDato()->toStringConCursos();
		paux = paux->getNext();
	}
	return s.str();
}

ControladorEscuelas::~ControladorEscuelas()
{
	cout << "Eliminando Controlador de Escuelas" << endl;
	listaEscuelas->wipe();
}
