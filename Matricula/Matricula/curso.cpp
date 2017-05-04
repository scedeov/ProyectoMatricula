#include "curso.h"

Curso::Curso()
{
	codigoCurso = "Undefined";
	nombreCurso = "Undefined";
}

Curso::Curso(string unNombre, string siglaEscuela) // en el momento que el curso se crea, se debe agregar ya la sigla de la Escuela.
{
	nombreCurso = unNombre;
	codigoCurso = siglaEscuela + to_string(variableCodigoCursos);
	variableCodigoCursos++;

	for (int i = 0; i < MAXPROF; i++)
		profesores[i] = "Undefined";
	cantidadProfesores = 0;
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

void Curso::setProfesores(string profenuevo) {
	if (cantidadProfesores < MAXPROF) {
		profesores[cantidadProfesores] = profenuevo;
		cantidadProfesores++;
	}
}

string Curso::getProfesores() {
	stringstream s;
	for (int i = 0; i < cantidadProfesores; i++)
		s << profesores[i] << " ";
	return s.str();
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