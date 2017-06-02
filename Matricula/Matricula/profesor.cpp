#include "profesor.h"
#include "curso.h"
#include <sstream>
#include <iostream>
using namespace std;

Profesor::Profesor() : 
	Persona() {
	//cursosImpartidos = new Vector<Curso>(MAXCURSOS);
	//cantidadCursos = 0;
	//esDirector = false;
}

Profesor::Profesor(Persona* persona = NULL) : 
	Persona() {

	//esDirector = false;
	//cursosImpartidos = new Vector<Curso>(MAXCURSOS);
	//cantidadCursos = 0;
}

//void Profesor::agregaNuevoCursoImpartido(Curso* cursoNuevo) {
//	cursosImpartidos->agregarInicio(cursoNuevo);
//}
//
//void Profesor::setEscuela(string escuela)
//{
//	this->escuela = ((char)toupper(escuela[0])) + escuela.substr(1, escuela.length() - 1);
//}
//
//string Profesor::getEscuela()
//{
//	return escuela;
//}
//
//int Profesor::getCantidadCursos()
//{
//	return cursosImpartidos->getCantidad();
//}
//
//int Profesor::getMaxCursos()
//{
//	return cursosImpartidos->getCapacidad();
//}
//
//string Profesor::getCursosImpartidos() {
//	stringstream s;
//	Vector<Curso>::Iterador it(cursosImpartidos);
//	it.posicionaPrimerObjeto();
//	while (it.getPosicionActual() < cursosImpartidos->getCantidad()) {
//		s << it.getObjectoCursorActual()->getCodigoCurso() << " ";
//		it.posicionaSiguiente();
//	}
//	return s.str();
//}
//
//bool Profesor::eliminarCursoImpartido(string codigo)
//{
//	Vector<Curso>::Iterador it(cursosImpartidos);
//	it.posicionaPrimerObjeto();
//	while (it.getPosicionActual() < cursosImpartidos->getCantidad()) {
//		if (it.getObjectoCursorActual()->getCodigoCurso() == codigo) { 
//			cursosImpartidos->eliminaEspecifico(it.getPosicionActual());
//			return true;
//		}
//		else
//			it.posicionaSiguiente();
//	}
//	return false;
//}
//
//bool Profesor::getEsDirector()
//{
//	return esDirector;
//}

string Profesor::toString()
{
	stringstream s;
	s << Persona::toString();
	if (esDirector)
		s << "Es el director." << endl;
	return s.str();
}

Profesor::~Profesor()
{
	cout << "Eliminando Profesor... " << endl;
	delete cursosImpartidos;
}

ostream & operator<<(ostream &o, Profesor &P) {
	return o << P.toString();
}
