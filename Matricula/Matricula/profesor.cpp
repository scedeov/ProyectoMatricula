#include "profesor.h"

Profesor::Profesor(string nombre, string primerApellido, string segundoApellido, int numCedula)
{
	setNombre(nombre);
	setPrimerApellido(primerApellido);
	setSegundoApellido(segundoApellido);
	setNumCedula(numCedula);
	esDirector = false;
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
