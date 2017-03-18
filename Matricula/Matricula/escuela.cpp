#include "escuela.h"

Escuela::Escuela()
{
	nombre = "Undefined";
	codigoEscuela = "Undefined";
	codigo = 0;
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

void Escuela::generaCodigo(string unNombre)
{
	string codEscuela;
	codEscuela = unNombre + to_string(codigo);
	codigo++;
}

string Escuela::toString()
{
	stringstream s;

	s << "Nombre de la Escuela: " << nombre << endl;
	s << "Codigo de la Escuela: " << codigoEscuela << endl;

	return s.str();
}
