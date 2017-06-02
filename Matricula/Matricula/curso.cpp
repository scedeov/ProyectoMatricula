#include "curso.h"
#include "contenedorGrupoCurso.h"
#include "grupoProfesores.h"
#include <sstream>
#include <iostream>
using namespace std;

Curso::Curso (
	string unNombre = "Undefined", 
	string siglaEscuela = "Undefined",
	int xCantidadCreditos = 0) :
	nombreCurso(unNombre), codigoCurso(siglaEscuela), cantidadCreditos(xCantidadCreditos)
{
	setCodigoCurso;
	variableCodigoCursos++;

	grupoProfesores = new GrupoProfesores();
	contenedorGrupoCurso = new ContenedorGrupoCurso();
}

Curso::~Curso()
{
	cout << "Eliminando curso..." << endl;
	delete contenedorGrupoCurso;
	delete grupoProfesores;
}

void Curso::setNombre(string unNombre)
{
	nombreCurso = unNombre;
}

void Curso::setCodigoCurso(string siglaEscuela)
{
	codigoCurso = codigoCurso + to_string(variableCodigoCursos);
}

void Curso::setCantidadCreditos(int cantidadCreditos)
{
	this->cantidadCreditos = cantidadCreditos;
}

ContenedorGrupoCurso* Curso::getContenedorGrupoCurso()
{
	return contenedorGrupoCurso;
}

GrupoProfesores* Curso::getGrupoProfesores() {
	return grupoProfesores;
}

string Curso::getNombre()
{
	return nombreCurso;
}

string Curso::getCodigoCurso()
{
	return codigoCurso;
}

int Curso::getCantidadCreditos()
{
	return cantidadCreditos;
}

string Curso::imprimeEstudiantesMatriculados()
{
	stringstream s;
	Vector<GrupoCurso>::Iterador it(grupoEstu);
	it.posicionaPrimerObjeto();
	for (int i = 0; i < grupoEstu->getCantidad(); i++) {
		s << it.getObjectoCursorActual()->toString() << endl;
		it.posicionaSiguiente();
	}
	return s.str();
}

string Curso::toString()
{
	stringstream s;
	s << "Codigo del Curso: " << codigoCurso << " | " << nombreCurso << endl;
	return s.str();
}

ostream& operator << (ostream& o, Curso& c)
{
	return o << c.toString();
}

bool Curso::operator == (const Curso &c) const
{
	return this->nombreCurso == c.nombreCurso && this->codigoCurso == c.codigoCurso;
}