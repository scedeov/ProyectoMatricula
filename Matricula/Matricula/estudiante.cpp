#include "estudiante.h"

Estudiante::Estudiante()
{
	carnet = "undefined";
	esExtranjero = "undefined";
	porcentajeBeca = 0;
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

Estudiante::~Estudiante()
{
	cout << "Eliminando Estudiante..." << endl;
}
