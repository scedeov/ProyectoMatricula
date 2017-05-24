#include "curso.h"
#include <sstream>
#include <iostream>
using namespace std;

Curso::Curso()
{
	codigoCurso = "Undefined";
	nombreCurso = "Undefined";

	grupoEstu.reserve(5);
	for (int i = 0; i < grupoEstu.capacity(); i++)
		grupoEstu.push_back(new GrupoEstudiantes());

	grupoProfes = new GrupoProfesores();
}

Curso::Curso(string unNombre, string siglaEscuela) // en el momento que el curso se crea, se debe agregar ya la sigla de la Escuela.
{
	nombreCurso = unNombre;
	codigoCurso = siglaEscuela + to_string(variableCodigoCursos);
	variableCodigoCursos++;

	grupoEstu.reserve(5);
	for (int i = 0; i < grupoEstu.capacity(); i++)
		grupoEstu.push_back(new GrupoEstudiantes());

	grupoProfes = new GrupoProfesores();
}

Curso::~Curso()
{
	cout << "Eliminando curso..." << endl;
}

void Curso::setNombre(string unNombre)
{
	nombreCurso = unNombre;
}

void Curso::setCodigoCurso(string unCodigoCurso)
{
	codigoCurso = unCodigoCurso;
}

void Curso::setCantidadCreditos(int cantidadCreditos)
{
	this->cantidadCreditos = cantidadCreditos;
}

GrupoEstudiantes* Curso::getGrupoEstudiantes(int pos)
{
	return grupoEstu[pos];
}

GrupoProfesores* Curso::getGrupoProfesores() {
	return grupoProfes;
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

std::string Curso::imprimeEstudiantesMatriculados()
{
	stringstream s;
	for (int i = 0; i < grupoEstu.size(); i++)
		s << grupoEstu[i]->toString() << endl;
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