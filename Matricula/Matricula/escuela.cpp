#include "escuela.h"

Escuela::Escuela(string unNombre = "Undefined") :
	nombreEscuela(unNombre)
{
	codigoEscuela = generaCodigo(nombreEscuela);

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

void Escuela::setCodigoEscuela(string unCodigoEscuela)
{
	codigoEscuela = unCodigoEscuela;
}

string Escuela::getCodigoEscuela()
{
	return codigoEscuela;
}

string Escuela::generaCodigo(string unNombre)
{
	codigoEscuela = unNombre.substr(0, 3);
	string aux;
	for (size_t i = 0; i < codigoEscuela.length(); i++)
	{
		aux += toupper(codigoEscuela[i]);
	}

	codigoEscuela = aux + to_string(codigo);
	codigo++;

	return codigoEscuela;
}

string Escuela::toString()
{
	stringstream s;
	s << "Nombre de la Escuela: " << nombreEscuela;
	s << "| Codigo: " << codigoEscuela << endl;

	return s.str();
}
