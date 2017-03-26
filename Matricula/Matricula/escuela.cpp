#include "escuela.h"

Escuela::Escuela(string unNombre = "Undefined") :
	nombreEscuela(unNombre)
{
	siglaEscuela = generaSigla(nombreEscuela);

	if (nombreEscuela != "Undefined")
		nombreEscuela = "Escuela de " + nombreEscuela;
}

Escuela::~Escuela()
{
	cout << "Eliminando Escuela" << endl;
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

string Escuela::toString()
{
	stringstream s;
	s << "Nombre de la Escuela: " << nombreEscuela;
	s << "| Codigo: " << siglaEscuela << endl;

	return s.str();
}
