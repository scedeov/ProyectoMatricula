#include "curso.h"


Curso::Curso()
{
	codigoCurso = "Undefined";
	nombreCurso = "Undefined";

	grupo = new Vector<Grupo>(MAXGRUPOSESTUDIANTES);
}

Curso::Curso(string unNombre, string siglaEscuela) // en el momento que el curso se crea, se debe agregar ya la sigla de la Escuela.
{
	nombreCurso = unNombre;
	codigoCurso = siglaEscuela + to_string(variableCodigoCursos);
	variableCodigoCursos++;

	grupo = new Vector<Grupo>(MAXGRUPOSESTUDIANTES);
}

Curso::~Curso()
{
	cout << "Eliminando curso..." << endl;
	delete grupo;
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

Grupo* Curso::getGrupo(int pos)
{
	return grupo->getDato(pos);
}

Profesor * Curso::getProfesorEncargado(int pos)
{
	for (int i = 0; i < grupo->getCantidad(); i++)
		return grupo->getDato(pos)->getProfesorEncargado();
}

int Curso::getCantidadGrupos()
{
	return grupo->getCantidad();
}

int Curso::getCantidadProfesoresEncargados()
{
	int contador = 0;
	for (int i = 0; i < grupo->getCantidad(); i++)
		if (grupo->getDato(i)->getProfesorEncargado())
			contador++;
	return contador;
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

bool Curso::estaEstudiante(Estudiante *estudiante)
{
	for (int i = 0; i < grupo->getCantidad(); i++) {
		Grupo *grupoaux = grupo->getDato(i);
		for (int x = 0; x < grupoaux->getCantidad(); x++)
			if (grupoaux->getEstudiante(x)->getID() == estudiante->getID())
				return true;
	}
	return false;
}

string Curso::imprimeEstudiantesMatriculados()
{
	stringstream s;
	Vector<Grupo>::Iterador it(grupo);
	it.first();
	for (int i = 0; i < grupo->getCantidad(); i++) {
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