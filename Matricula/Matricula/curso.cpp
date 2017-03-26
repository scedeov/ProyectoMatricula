#include "curso.h"

Curso::Curso()
{
	codigoCurso = "Undefined";
	nombreCurso = "Undefined";
}

Curso::Curso(string unNombre, string unCodigoCurso)
{
	nombreCurso = unNombre;
	codigoCurso = unCodigoCurso;
}

Curso::~Curso()
{
}

void Curso::setNombre(string unNombre)
{
	nombreCurso = unNombre;
}

void Curso::setCodigoCurso(string unCodigoCurso)
{
	codigoCurso = unCodigoCurso;
}

string Curso::getNombre()
{
	return nombreCurso;

}

string Curso::getCodigoCurso()
{
	return codigoCurso;
}

string Curso::toStringCurso()
{
	stringstream s;

	s << "Nombre del curso: " << nombreCurso << endl;
	s << "Sigla del curso: " << codigoCurso << endl;

	return s.str();
}
