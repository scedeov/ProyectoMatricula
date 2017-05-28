#include "curso.h"
#include "grupoEstudiantes.h"
#include "grupoProfesores.h"
#include <sstream>
#include <iostream>
using namespace std;

Curso::Curso()
{
	codigoCurso = "Undefined";
	nombreCurso = "Undefined";
	
	grupoEstu = new Vector<GrupoEstudiantes>(MAXGRUPOSESTUDIANTES);
	for (int i = 0; i < MAXGRUPOSESTUDIANTES; i++)
		grupoEstu->push(new GrupoEstudiantes());

	grupoProfes = new GrupoProfesores();
}

Curso::Curso(string unNombre, string siglaEscuela) // en el momento que el curso se crea, se debe agregar ya la sigla de la Escuela.
{
	nombreCurso = unNombre;
	codigoCurso = siglaEscuela + to_string(variableCodigoCursos);
	variableCodigoCursos++;

	grupoEstu = new Vector<GrupoEstudiantes>(MAXGRUPOSESTUDIANTES);
	for (int i = 0; i < grupoEstu->getCapacidad(); i++)
		grupoEstu->push(new GrupoEstudiantes());

	grupoProfes = new GrupoProfesores();
}

Curso::~Curso()
{
	cout << "Eliminando curso..." << endl;
	delete grupoEstu;
	delete grupoProfes;
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
	Vector<GrupoEstudiantes>::Iterador it(grupoEstu);
	it.first();
	for (int i = 0; i < pos; i++)
		it.next();
		return it.getCurItem();
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

string Curso::imprimeEstudiantesMatriculados()
{
	stringstream s;
	Vector<GrupoEstudiantes>::Iterador it(grupoEstu);
	it.first();
	for (int i = 0; i < grupoEstu->getCantidad(); i++) {
		s << it.getCurItem()->toString() << endl;
		it.next();
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