#include "estudiante.h"

Estudiante::Estudiante(string nombre, string pApellido, string sApellido, string xcarnet, bool xExtranjero, int porcentaje)
{
	setNombre(nombre);
	setPrimerApellido(pApellido);
	setSegundoApellido(sApellido);
	carnet = xcarnet;
	esExtranjero = xExtranjero;
	porcentajeBeca = porcentaje;
}

void Estudiante::setCarnet(string carnet)
{
	this->carnet = carnet;
}

string Estudiante::getCarnet()
{
	return carnet;
}

void Estudiante::setNacionalidad(bool esExtranjero)
{
	this->esExtranjero = esExtranjero;
}

bool Estudiante::getNacionalidad()
{
	return esExtranjero;
}

void Estudiante::setPorcentajeBeca(int porcentajeBeca)
{
	this->porcentajeBeca = porcentajeBeca;
}

int Estudiante::getPorcentajeBeca()
{
	return porcentajeBeca;
}

string Estudiante::toString()
{
	stringstream s;
	s << Persona::toString() << endl;
	s << "Numero de Carnet: " << carnet << endl;
	s << "Nacionalidad: "; 
	if (esExtranjero)
		s << "Extranjera" << endl;
	else
		s << "Nacional" << endl;
	s << "Porcentaje Beca: " << porcentajeBeca << endl;
	return s.str();


	return string();
}

Estudiante::~Estudiante()
{
	cout << "Eliminando Estudiante..." << endl;
}

ostream & operator<<(ostream &o, Estudiante &E)
{
	return o << E.toString();
}
