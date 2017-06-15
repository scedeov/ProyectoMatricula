#include "escuela.h"


Escuela::Escuela(string unNombre = "Undefined") :
	nombreEscuela(unNombre)
{
	siglaEscuela = generaSigla(nombreEscuela);

	if (nombreEscuela != "Undefined")
		nombreEscuela = "Escuela de " + nombreEscuela;

	ContP = new ControladorProfesores();
	ConC = new ControladorCursos();

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

ControladorCursos * Escuela::getContenedorCursos()
{
	return ConC;
}

ControladorProfesores * Escuela::getContenedorProfesores() {
	return ContP;
}

string Escuela::toStringEscuela() {
	stringstream s;
	s << "Nombre de la Escuela: " << nombreEscuela;
	s << "| Sigla: " << siglaEscuela << endl;
	return s.str();
}

std::string Escuela::toStringConCursos() {
	stringstream s;
	s << "Nombre de la Escuela: " << nombreEscuela;
	s << "| Sigla: " << siglaEscuela << endl;
	s << "Cursos Impartidos: " << endl;
	s << *ConC << endl;
	return s.str();
}
