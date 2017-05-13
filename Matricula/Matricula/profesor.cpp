#include "profesor.h"

Profesor::Profesor()
{
	for (int i = 0; i < MAXCURSOS; i++)
		cursosImpartidos[i] = "Undefined";
	cantidadCursos = 0;
	esDirector = false;
}

Profesor::Profesor(string nombre, string primerApellido, string segundoApellido, int numCedula) {
	setNombre(nombre);
	setPrimerApellido(primerApellido);
	setSegundoApellido(segundoApellido);
	setNumCedula(numCedula);
	
	esDirector = false;

	for (int i = 0; i < MAXCURSOS; i++)
		cursosImpartidos[i] = "Undefined";
	cantidadCursos = 0;
}

void Profesor::setCursosImpartidos(string cursoNuevo) {
	if (cantidadCursos < MAXCURSOS) {
		cursosImpartidos[cantidadCursos] = cursoNuevo;
		cantidadCursos++;
	}
}

string Profesor::getCursosImpartidos() {
	stringstream s;
	for (int i = 0; i < cantidadCursos; i++)
		s << cursosImpartidos[i] << " ";
	return s.str();
}

bool Profesor::getEsDirector()
{
	return esDirector;
}

string Profesor::toString()
{
	stringstream s;
	s << Persona::toString();
	if (esDirector)
		s << "Es el director." << endl;
	return s.str();
}

Profesor::~Profesor()
{
	cout << "Eliminando Profesor... " << endl;
}

ostream & operator<<(ostream &o, Profesor &P) {
	return o << P.toString();
}
