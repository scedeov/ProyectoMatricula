#include "curso.h"

bool Curso::operator == (const Curso &c)
{
	if (codigoCurso == c.codigoCurso)
		return true;
	else
		return false;
}

Curso::Curso()
{
	codigoCurso = "Undefined";
	nombreCurso = "Undefined";
}

Curso::Curso(string unNombre, string siglaEscuela) // en el momento que el curso se crea, se debe agregar ya la sigla de la Escuela.
{
	nombreCurso = unNombre;
	codigoCurso = siglaEscuela + to_string(cantidad);
	cantidad++;
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

string Curso::getNombre()
{
	return nombreCurso;

}

string Curso::getCodigoCurso()
{
	return codigoCurso;
}

ostream& operator << (ostream& o, const Curso& c)
{
	o << "Codigo del curso: " << c.codigoCurso << "||| " << c.nombreCurso << endl;
	return o;
}

//string Curso::toStringCurso()
//{
//	stringstream s;
//
//	s << "Codigo del curso: " << codigoCurso << "||| " << nombreCurso << endl;
//
//	return s.str();
//}
