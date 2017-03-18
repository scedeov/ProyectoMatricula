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
	codEscuela = unNombre.substr(0, 3);
	codEscuela = Interfaz::convierteaMayusculas(codEscuela);
	codEscuela = codEscuela + to_string(codigo);
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
