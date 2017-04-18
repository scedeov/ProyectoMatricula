#include "estudiante.h"

Estudiante::Estudiante()
{
	carnet = "undefined";
	nacionalidad = "undefined";
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

void Estudiante::setNacionalidad(string nacionalidad)
{
	this->nacionalidad = nacionalidad;
}

string Estudiante::getNacionalidad()
{
	return nacionalidad;
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
