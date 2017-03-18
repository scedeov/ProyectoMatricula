#include "escuela.h"

Escuela::Escuela(string unNombre = "Undefined") :
	nombre(unNombre)
{
	codigoEscuela = generaCodigo(nombre);

	if (nombre != "Undefined")
		nombre = "Escuela de " + nombre;
}

Escuela::~Escuela()
{
	nombre = "Undefined";
	codigoEscuela = "Undefined";
}

void Escuela::setNombre(string unNombre)
{
	nombre = unNombre;
}

string Escuela::getNombre()
{
	return nombre;
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
	s << "Universidad: " << nombreU;
	s << "| Nombre de la Escuela: " << nombre;
	s << "| Codigo: " << codigoEscuela << endl;

	return s.str();
}
