#include "profesor.h"
#include "escuela.h"
#include <sstream>
#include <iostream>
using namespace std;

Profesor::Profesor(): Persona() {
	
}

void Profesor::setEscuela(Escuela *escuela)
{
	this->escuela = escuela;
}

Escuela * Profesor::getEscuela()
{
	return escuela;
}

//void Profesor::setCursosImpartidos(string cursoNuevo) {
//	if (cantidadCursos < MAXCURSOS) {
//		cursosImpartidos[cantidadCursos] = cursoNuevo;
//		cantidadCursos++;
//	}
//}


//
//int Profesor::getCantidadCursos()
//{
//	return cantidadCursos;
//}
//
//int Profesor::getMaxCursos()
//{
//	return MAXCURSOS;
//}

//string Profesor::getCursosImpartidos() {
//	stringstream s;
//	for (int i = 0; i < cantidadCursos; i++)
//		s << cursosImpartidos[i] << " ";
//	return s.str();
//}

//bool Profesor::eliminarCursoImpartido(string codigo)
//{
//	for (int i = 0; i < cantidadCursos; i++) 
//		if (cursosImpartidos[i] == codigo) {
//			for (int x = i; x < cantidadCursos; x++)
//				cursosImpartidos[x] = cursosImpartidos[i + 1];
//			cantidadCursos--;
//			return true;
//		}
//	return false;
//}

//bool Profesor::getEsDirector()
//{
//	return esDirector;
//}

string Profesor::toString()
{
	stringstream s;
	s << Persona::toString();
	/*if (esDirector)
		s << "Es el director." << endl;*/
	return s.str();
}

Profesor::~Profesor()
{
	cout << "Eliminando Profesor... " << endl;
}

ostream & operator<<(ostream &o, Profesor &P) {
	return o << P.toString();
}
