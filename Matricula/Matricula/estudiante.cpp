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
}

Estudiante::Estudiante(string nombre, string pApellido, string sApellido, int cedula, int porcentaje)
{
	setNombre(nombre);
	setPrimerApellido(pApellido);
	setSegundoApellido(sApellido);
	setNumCedula(cedula);
	generaCarnet();
	porcentajeBeca = porcentaje;
}

string Estudiante::getCarnet()
{
	return carnet;
}

void Estudiante::agregaCurso(Curso* curso)
{
	listaCursos.push_back(curso);
}

string Estudiante::imprimeCursos() {
	stringstream s;
	for (size_t i = 0; i < listaCursos.capacity(); i++)
		s << listaCursos[i]->getCodigoCurso() << " - ";
	s << endl;
	return s.str();
}

int Estudiante::getCantidadCursosMatriculados()
{
	return (int) listaCursos.size();
}

Curso * Estudiante::getCursoMatriculado(int pos)
{
	return listaCursos[pos];
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
