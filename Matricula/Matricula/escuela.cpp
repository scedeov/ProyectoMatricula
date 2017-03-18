#include "escuela.h"

Escuela::Escuela(string unNombre = "Undefined") :
	nombre(unNombre)
{
	if (nombre != "Undefined")
		nombre = "Escuela de " + nombre;

	codigoEscuela = generaCodigo(nombre);
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

string Escuela::generaCodigo(string unNombre)
{
	string codEscuela;
	codEscuela = unNombre + to_string(codigo);
	codigo++;
	return codEscuela;
}

string Escuela::toString()
{
	stringstream s;

	s << "Nombre de la Escuela: " << nombre << endl;
	s << "Codigo de la Escuela: " << codigoEscuela << endl;

	return s.str();
}
