#include "universidad.h"

Universidad::Universidad()
{
	nombre = "Undefined";
	numeroTelefono = "Undefined";
	direccion = "Undefined";

	ContE = new Contenedor_Escuelas();
}

Universidad::Universidad(string unNombre, string xNumero, string unDireccion)
{
	nombre = unNombre;
	numeroTelefono = xNumero;
	direccion = unDireccion;

	ContE = new Contenedor_Escuelas();
}

Universidad::~Universidad()
{
	cout << "Eliminando Universidad..." << endl;
	delete ContE;
}

void Universidad::setTelefono(string unTelefono)
{
	numeroTelefono = unTelefono;
}

void Universidad::setDireccion(string unDireccion)
{
	direccion = unDireccion;
}

void Universidad::setNombre(string unNombre)
{
	nombre = unNombre;
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
	s << "Nombre Universidad: " << nombre << endl
		<< "Numero de Telefono: " << numeroTelefono << endl
		<< "Direccion: " << direccion << endl;

	return s.str();
}

Contenedor_Escuelas* Universidad::getContenedorEscuelas() {
	return ContE;
}

ostream& operator << (ostream &o, Universidad& U)
{
	return o << U.toString();
}
