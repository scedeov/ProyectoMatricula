#include "estudiante.h"
#include "curso.h"
#include <time.h>
#include <sstream>
#include <iostream>
using namespace std;

Estudiante::Estudiante()
{
	carnet = "Undefined";
	porcentajeBeca = 0;
	esExtranjero = false;
	generaCarnet();
	vectorCursos = new Vector<Curso>(12);
}

Estudiante::Estudiante(string nombre, string pApellido, string sApellido, int cedula, int porcentaje)
{
	setNombre(nombre);
	setPrimerApellido(pApellido);
	setSegundoApellido(sApellido);
	setNumCedula(cedula);
	generaCarnet();
	porcentajeBeca = porcentaje;
	vectorCursos = new Vector<Curso>(12);
}

string Estudiante::getCarnet()
{
	return carnet;
}

void Estudiante::agregaCurso(Curso* curso)
{
	vectorCursos->agregar(curso);
}

string Estudiante::imprimeCursos() {
	stringstream s;
	Vector<Curso>::Iterador it(vectorCursos);
	it.posicionaPrimerObjeto();
	for (int i = 0; i < vectorCursos->getCantidad(); i++) {
		s << it.getObjectoCursorActual()->toString() << endl;
		it.posicionaSiguiente();
	}
	return s.str();
}

int Estudiante::getCantidadCursosMatriculados()
{
	return vectorCursos->getCantidad();
}

Curso * Estudiante::getCursoMatriculado(int pos)
{
	Vector<Curso>::Iterador it(vectorCursos);
	it.posicionaPrimerObjeto();
	for (int i = 0; i < pos; i++)
		it.posicionaSiguiente();
	return it.getObjectoCursorActual();
}

void Estudiante::setEsExtranjero(bool esExtranjero)
{
	this->esExtranjero = esExtranjero;
}

bool Estudiante::getEsExtranjero()
{
	return esExtranjero;
}

void Estudiante::setPorcentajeBeca(int porcentajeBeca)
{
	this->porcentajeBeca = porcentajeBeca;
}

int Estudiante::getPorcentajeBeca()
{
	return porcentajeBeca;
}

void Estudiante::generaCarnet()
{
	srand((unsigned)time(0));
	int numeroRandom = 1000 + rand() % 5000;
	carnet = getPrimerApellido().substr(0, 1) + getSegundoApellido().substr(0, 1) + getNombre().substr(0, 1) + to_string(numeroRandom);
}

string Estudiante::toString()
{
	stringstream s;
	s << Persona::toString() << endl;
	s << "Numero de Carnet: " << carnet << endl;
	s << "Nacionalidad: "; 
	if (esExtranjero)
		s << "Extranjera" << endl;
	else
		s << "Nacional" << endl;
	s << "Porcentaje Beca: " << porcentajeBeca << endl;
	return s.str();
}

Estudiante::~Estudiante()
{
	cout << "Eliminando Estudiante..." << endl;
}

ostream & operator<<(ostream &o, Estudiante &E)
{
	return o << E.toString();
}
