#include "universidad.h"

Universidad::Universidad()
{
	nombre = "Undefined";
	numeroTelefono = "Undefined";
	direccion = "Undefined";
}

Universidad::~Universidad()
{
	//Bye
}

void Universidad::setTelefono(string unTelefono)
{
	numeroTelefono = unTelefono;
}

void Universidad::setDireccion(string unDireccion)
{
	direccion = unDireccion;
}

string Universidad::getNombre()
{
	return nombre;
}

string Universidad::getNumero()
{
	return numeroTelefono;
}

string Universidad::getDireccion()
{
	return direccion;
}

string Universidad::toString()
{
	stringstream s;

	s	<< string("Nombre Universidad: ") << nombre << endl
		<< string("Numero de Telefono: ") << numeroTelefono << endl
		<< string("Direccion: ") << direccion << endl;
	return s.str();
}
