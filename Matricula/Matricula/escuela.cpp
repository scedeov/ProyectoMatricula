#include "escuela.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

Escuela::Escuela(string unNombre = "Undefined") :
	nombreEscuela(unNombre)
{
	siglaEscuela = generaSigla(nombreEscuela);

	if (nombreEscuela != "Undefined")
		nombreEscuela = "Escuela de " + nombreEscuela;

	ContP = new Contenedor_Profesores();
	ConC = new Contenedor_Cursos();

}

Escuela::~Escuela()
{
	cout << "Eliminando Escuela" << endl;
	delete ConC;
}

void Escuela::setNombre(string unNombre)
{
	nombreEscuela = unNombre;
}

string Escuela::getNombre()
{
	return nombreEscuela;
}

void Escuela::setSiglaEscuela(string unSiglaEscuela)
{
	siglaEscuela = unSiglaEscuela;
}

string Escuela::getSiglaEscuela()
{
	return siglaEscuela;
}

string Escuela::generaSigla(string unNombre)
{
	siglaEscuela = unNombre.substr(0, 3);
	string aux;
	for (int i = 0; i < siglaEscuela.length(); i++)
	{
		aux += toupper(siglaEscuela[i]);
	}

	siglaEscuela = aux;

	return siglaEscuela;
}

Contenedor_Cursos * Escuela::getContenedorCursos()
{
	return ConC;
}

Contenedor_Profesores * Escuela::getContenedorProfesores() {
	return ContP;
}

string Escuela::toStringEscuela(char op)
{
	stringstream s;
	s << "Nombre de la Escuela: " << nombreEscuela;
	s << "| Codigo: " << siglaEscuela << endl;

	if (op == '2') {
		s << "Cursos Impartidos: " << endl;
		s << *ConC << endl;
	}
	return s.str();
}
