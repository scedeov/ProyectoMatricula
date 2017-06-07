#include "estudiante.h"
using namespace std;

//Estudiante::Estudiante()
//{
//	carnet = "Undefined";
//	porcentajeBeca = 0;
//	/*esExtranjero = false;*/
//	generaCarnet();
//}

Estudiante::Estudiante(int porcentaje = 0): Persona(), porcentajeBeca(porcentaje)
{
	porcentajeBeca = porcentaje;
}

string Estudiante::getCarnet()
{
	return carnet;
}

//void Estudiante::agregaCurso(Curso* curso)
//{
//	listaCursos->push(curso);
//}

//string Estudiante::imprimeCursos() {
//	stringstream s;
//	for (size_t i = 0; i < listaCursos->getCantidad(); i++)
//		s << listaCursos->getDato(i)->getCodigoCurso() << " - ";
//	s << endl;
//	return s.str();
//}

//int Estudiante::getCantidadCursosMatriculados()
//{
//	return listaCursos->getCantidad();
//}
//
//Curso * Estudiante::getCursoMatriculado(int pos)
//{
//	return listaCursos->getDato(pos);
//}

//void Estudiante::setEsExtranjero(bool esExtranjero)
//{
//	this->esExtranjero = esExtranjero;
//}

//bool Estudiante::getEsExtranjero()
//{
//	return esExtranjero;
//}

void Estudiante::setPorcentajeBeca(int porcentajeBeca) {
	this->porcentajeBeca = porcentajeBeca;
}

int Estudiante::getPorcentajeBeca() {
	return porcentajeBeca;
}

void Estudiante::generaCarnet() {
	srand((unsigned)time(0));
	int numeroRandom = 1000 + rand() % 5000;
	carnet = getPrimerApellido().substr(0, 1) + getSegundoApellido().substr(0, 1) + getNombre().substr(0, 1) + to_string(numeroRandom);
}

string Estudiante::toString() {
	stringstream s;
	s << Persona::toString() << endl;
	s << "Numero de Carnet: " << carnet << endl;
	s << "Nacionalidad: "; 
	//if (esExtranjero)
	//	s << "Extranjera" << endl;
	//else
	//	s << "Nacional" << endl;
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
