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

string Persona::toString()
{
	stringstream s;
	s << "Nombre: " << getNombre() << " " << getPrimerApellido() << " " << getSegundoApellido() << " | ";
	s << " Numero de Cedula: " << getNumCedula() << endl;
	return s.str();
}

ostream & operator<<(ostream &o, Persona &P) {
	return o << P.toString();
}
