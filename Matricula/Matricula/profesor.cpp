#include "profesor.h"

int Profesor::getNumCedula()
{
	return Persona::getNumCedula();
}

string Profesor::getNombreCompleto()
{
	return Persona::getNombreCompleto();
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

//void Profesor::generaCodigoProfesor() {
//	string primera, segunda, tercera;
//	primera = getNombre()[0];
//	segunda = getPrimerApellido()[0];
//	tercera = getSegundoApellido()[0];
//	codigoProfesor = primera + segunda + tercera;
//	codigoProfesor = codigoProfesor + to_string(cantidadCursos);
//}


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
