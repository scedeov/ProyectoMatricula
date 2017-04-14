#include "persona.h"

Persona::Persona()
{
	nombre = "";
	apellido = "";
	numCedula = 0;
	numTelefono = 0;
}

Persona::~Persona()
{
	cout << "Eliminando Persona" << endl;
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Persona::getNombre()
{
	return nombre;
}

void Persona::setApellido(string apellido)
{
	this->apellido = apellido;
}

string Persona::getApellido()
{
	return apellido;
}

void Persona::setNumCedula(int numCedula)
{
	this->numCedula = numCedula;
}

int Persona::getNumCedula()
{
	return numCedula;
}

void Persona::setNumTelefono(int numTelefono)
{
	this->numTelefono = numTelefono;
}

int Persona::getNumTelefono()
{
	return numTelefono;
}

ostream& operator<< (ostream& o, const Persona& p)
{
	o << "Nombre: " << p.nombre << "Apellido: " << p.apellido
		<< "Numero de Cedula: " << p.numCedula << "Numero de Telefono: " << p.numTelefono << endl;
	return o;
}