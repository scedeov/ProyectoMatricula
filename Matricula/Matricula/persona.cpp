#include "persona.h"


Persona::Persona() {
	nombre = "";
	primerApellido = "";
	segundoApellido = "";
	id = "";
	nombreCompleto = getNombreCompleto();
	cedula = "";
}

Persona::~Persona()
{
	cout << "Eliminando Persona" << endl;
}

string Persona::getNombreCompleto()
{
	std::string nombrecomp = nombre + " " + primerApellido + " " + segundoApellido;
	return nombrecomp;
}

void Persona::setNombre(string nombre)
{
	this->nombre = ((char) toupper(nombre[0])) + nombre.substr(1, nombre.length() - 1);
}

string Persona::getNombre()
{
	return nombre;
}

void Persona::setPrimerApellido(string primerApellido)
{
	this->primerApellido = ((char) toupper(primerApellido[0])) + primerApellido.substr(1, primerApellido.length() - 1);
}

string Persona::getPrimerApellido()
{
	return primerApellido;
}

void Persona::setSegundoApellido(string segundoApellido) {
	this->segundoApellido = ((char) toupper(segundoApellido[0])) + segundoApellido.substr(1, segundoApellido.length() - 1);
}

string Persona::getSegundoApellido() {
	return segundoApellido;
}

void Persona::setNumCedula(string id) {
	this->id = id;
}

string Persona::getNumCedula() {
	return id;
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
