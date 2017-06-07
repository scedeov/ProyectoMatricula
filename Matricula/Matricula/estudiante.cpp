#include "estudiante.h"

Estudiante::Estudiante()
{
	porcentajeBeca = 0;
	carnet = "";
}

Estudiante::Estudiante(int porcentajeBeca, string carnet) :
	Persona() {
	this->porcentajeBeca = porcentajeBeca;
	this->carnet = carnet;
	generaCarnet();
}

string Estudiante::getCarnet()
{
	return carnet;
}

void Estudiante::setPorcentajeBeca(int porcentajeBeca) {
	this->porcentajeBeca = porcentajeBeca;
}

int Estudiante::getPorcentajeBeca() {
	return porcentajeBeca;
}

void Estudiante::generaCarnet() {
	srand((unsigned)time(0));
	int numeroRandom = 1000 + rand() % 5000;
	carnet = primerApellido.substr(0, 1) + segundoApellido.substr(0, 1) + nombre.substr(0, 1) + to_string(numeroRandom);
}

string Estudiante::toString() {
	stringstream s;
	s << Persona::toString() << endl;
	s << "Numero de Carnet: " << carnet << endl;
	s << "Nacionalidad: "; 
	s << "Porcentaje Beca: " << porcentajeBeca << endl;
	return s.str();
}

Estudiante::~Estudiante()
{
	cout << "Eliminando Estudiante..." << endl;
}

ostream & operator<<(ostream &o, Estudiante &E)
{
	return o << E.toString();
}
