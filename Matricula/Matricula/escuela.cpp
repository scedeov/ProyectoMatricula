#include "escuela.h"

Escuela::Escuela()
{
	nombre = "Undefined";
	codigoEscuela = "Undefined";
}

Escuela::~Escuela()
{
	//Murió
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

string Escuela::toString()
{
	stringstream s;

	s << "Nombre de la Escuela: " << nombre << endl;
	s << "Codigo de la Escuela: " << codigoEscuela << endl;

	return s.str();
}
