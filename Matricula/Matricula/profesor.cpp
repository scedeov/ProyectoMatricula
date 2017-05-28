#include "profesor.h"]
#include "curso.h"
#include <sstream>
#include <iostream>
using namespace std;

Profesor::Profesor()
{
	
	cursosImpartidos = new Vector<Curso>(MAXCURSOS);
	for (int i = 0; i < MAXCURSOS; i++)
		cursosImpartidos->push (new Curso());
	cantidadCursos = 0;
	esDirector = false;
}

Profesor::Profesor(string nombre, string primerApellido, string segundoApellido, int numCedula) {
	setNombre(nombre);
	setPrimerApellido(primerApellido);
	setSegundoApellido(segundoApellido);
	setNumCedula(numCedula);

	esDirector = false;
	cursosImpartidos = new Vector<Curso>(MAXCURSOS);
	cantidadCursos = 0;
}

void Profesor::agregaNuevoCursoImpartido(Curso* cursoNuevo) {
	cursosImpartidos->push(cursoNuevo);
}

void Profesor::setEscuela(string escuela)
{
	this->escuela = ((char)toupper(escuela[0])) + escuela.substr(1, escuela.length() - 1);
}

string Profesor::getEscuela()
{
	return escuela;
}

int Profesor::getCantidadCursos()
{
	return cursosImpartidos->getCantidad();
}

int Profesor::getMaxCursos()
{
	return cursosImpartidos->getCapacidad();
}

string Profesor::getCursosImpartidos() {
	stringstream s;
	Vector<Curso>::Iterador it(cursosImpartidos);
	it.first();
	while (it.getPosActual() < cursosImpartidos->getCantidad()) {
		s << it.getCurItem()->getCodigoCurso() << " ";
		it.next();
	}
		
	return s.str();
}

bool Profesor::eliminarCursoImpartido(string codigo)
{
	Vector<Curso>::Iterador it(cursosImpartidos);
	it.first();
	while (it.getPosActual() < cursosImpartidos->getCantidad()) {
		if (it.getCurItem()->getCodigoCurso() == codigo) { 
			cursosImpartidos->eliminaEspecifico(it.getPosActual());
			return true;
		}
		else
			it.next();
	}
	return false;
}

bool Profesor::getEsDirector()
{
	return esDirector;
}

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
