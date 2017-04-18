#include "persona.h"

Persona::Persona(){
	nombre = "";
	primerApellido = "";
	numCedula = 0;
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

void Persona::setPrimerApellido(string primerApellido)
{
	this->primerApellido = primerApellido;
}

string Persona::getPrimerApellido()
{
	return primerApellido;
}

void Persona::setSegundoApellido(string segundoApellido) {
	this->segundoApellido = segundoApellido;
}

string Persona::getSegundoApellido() {
	return segundoApellido;
}

void Persona::setNumCedula(int numCedula)
{
	this->numCedula = numCedula;
}

int Persona::getNumCedula()
{
	return numCedula;
}

ostream& operator<< (ostream& o, const Persona& p)
{
	o	<< "Nombre: " << p.nombre << "Apellido: " << p.primerApellido
		<< "Numero de Cedula: " << p.numCedula << "Numero de Telefono: " << endl;
	return o;
}